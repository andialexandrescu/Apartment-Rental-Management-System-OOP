#include <Reservation.h>
#include <Apartment.h>
#include <iostream>
#include <vector>
#include <limits>

Reservation::Reservation(): card_number(0), card_holder_name("None"), cvv(0) {
    l_apts.clear();
}

[[maybe_unused]] Reservation::Reservation(int card_number, const std::string &card_holder_name, int cvv) {
    this->card_number = card_number;
    this->card_holder_name = card_holder_name;
    this->cvv = cvv;
}

Reservation::~Reservation() {
    if(!this->l_apts.empty())
    {
        this->l_apts.clear();
    }
}

Reservation &Reservation::operator+=(const Apartment &apt) {
    l_apts.push_back(apt);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Reservation &r) {
    std::cout<<"------- Search Results -------"<<std::endl;
    for(const Apartment &apt: r.l_apts)
    {
        out<<apt<<std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Reservation &r) {
    std::cout<<"Card Number: ";
    in>>r.card_number; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Card Holder Name: ";
    std::getline(in >> std::ws, r.card_holder_name);
    std::cout<<"Card CVV: "; in.clear();
    in>>r.cvv;
    return in;
}

std::vector<Apartment> Reservation::getApts() const {
    return l_apts;
}

std::string Reservation::getCardHolderName() const {
    return card_holder_name;
}

int Reservation::getCardNumber() const {
    return card_number;
}

int Reservation::getCardCVV() const {
    return cvv;
}

void Reservation::searchMenu(const Reservation &r) {
    int choice, guests = 0, rooms, p;
    std::cout<<"You are now in the searching main menu section. You will be able to search for apartments based on location, number of rooms and price."<<std::endl;
    std::cout<<"Please enter the search destination formatted as <City, Country>, the search engine will filter results containing at least one of these parameters.";
    std::cout<<"Search destinations: "<<std::endl;
    std::string city, country;
    std::cout<<"City: ";
    std::cin>>city;
    std::cout<<"Country: ";
    std::cin>>country;
    std::cout<<"Search chosen number of rooms: "<<std::endl;
    std::cin>>rooms;
    std::cout<<"Are you willing to opt for a different number of rooms? This means that you get to choose the number of guests. This way you will get a wider range of options considering both the number of rooms and number of guests chosen."<<std::endl;
    std::cout<<"Enter your choice:\nSearch criteria will be based on\n1. Number of rooms only\n2. Number of rooms and number of guests (either)"<<std::endl;
    std::cin>>choice;
    if (choice != 1 && choice != 2)
    {
        std::cout<<"Invalid choice. Please enter either 1 or 2."<<std::endl;
        return;
    }
    if(choice == 2)
    {
        std::cout<<"Enter number of guests: ";
        std::cin>>guests;
    }
    std::cout<<"Search maximum price range: "<<std::endl;
    std::cin>>p;
    if (r.l_apts.empty())
    {
        std::cout<<"No apartments available."<<std::endl;
        return;
    }
    for(const Apartment& apt : r.l_apts)
    {
        if(apt.searchCriteriaLocation(apt, city, country) && Apartment::searchCriteriaRooms(apt, rooms, guests, choice) && Apartment::searchCriteriaPrice(apt, p))
        {
            std::cout<<apt<<std::endl;
        }
    }
}

void Reservation::convertDate(int year, int month, int day, int &date) { // meant to convert a date; easier to manipulate booking dates, since it's going to specify the exact day it represents in the year
    std::vector<int> no_days = {0, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days in each month
    if (no_days[month]<day || month<1 || month>12 || day<1 || day>31)
    {
        std::cout << "Invalid date." << std::endl;
        return;
    }
    if(year%400==0 || (year%100!=0 && year%4==0))
    {
        no_days[2] = 29;
    } else no_days[2] = 28; // modify february's number of days during leap years
    int day_in_the_year = 0;
    for(int i = 1; i < month; i++)
    {
        day_in_the_year += no_days[i]; // the sum of days from previous months
    }
    day_in_the_year += day; // adding days in the current month

    date = day_in_the_year;
}

void Reservation::proceedTransaction(const Reservation &r, bool &booked) { // NOLINT(*-no-recursion)
    int choice;
    std::string apt_id;
    searchMenu(r);
    std::cout<<std::endl<<"You are now in the transaction submenu. Would you like to choose one of the listed apartments?"<<std::endl;
    std::cout<<"1. Yes, proceed with the reservation.\n2. No, return to the searching menu."<<std::endl;
    std::cin>>choice;
    switch(choice)
    {
        case 1:
            std::cout<<"Enter the apartment ID: ";
            std::cin>>apt_id;
            for([[maybe_unused]] auto apt: r.l_apts)
            {
                if(apt.getApartmentID() == apt_id)
                {
                    int year, start_date, end_date;
                    int start_month, start_day, end_month, end_day;
                    std::cout<<"Now you able to enter your choice of stay."<<std::endl;
                    std::cout<<"Enter current year: ";
                    std::cin>>year;
                    std::cout<<"Start date:"<<std::endl;
                    std::cout<<"Enter a month (1-12): ";
                    std::cin>>start_month;
                    std::cout<<"Enter a day (1-31): ";
                    std::cin>>start_day;
                    convertDate(year, start_month, start_day, start_date);
                    std::cout<<"End date:"<<std::endl;
                    std::cout<<"Enter a month (1-12): ";
                    std::cin>>end_month;
                    std::cout<<"Enter a day (1-31): ";
                    std::cin>>end_day;
                    convertDate(year, end_month, end_day, end_date);
                    if(!apt.isBooked(start_date, end_date)) // false
                    {
                        for(int i = start_date; i < end_date; i++) // booking all days
                        {
                            apt.bookApartment(i);
                        }
                        computeTransaction(apt, start_date, end_date);
                        booked = true;
                    } else
                    {
                        std::cout<<"The apartment is already booked between these dates. Would you like to enter another time frame?"<<std::endl;
                        std::cout<<"1. Yes, take me back\n2. No, I changed my mind"<<std::endl;
                        int choice2;
                        std::cin>>choice2;
                        if(choice2 == 1)
                        {
                            proceedTransaction(r, booked);
                        } else break;
                    }
                }
            }
            break;
        case 2:
            std::cout<<"Loading..."<<std::endl<<std::endl;
            break;
        default:
            return;
    }
    //std::cout<<"You are now at the last step of your booking. Insert your credentials: "<<std::endl;
    //std::cin>>r;
}

void Reservation::computeTransaction(const Apartment &apt, int start_date, int end_date) {
    int children, guests, price_per_night, total_price;
    std::cout<<"Enter number of total guests: ";
    std::cin>>guests;
    std::cout<<"Enter the number of guests who are underage (0 if none): ";
    std::cin>>children;
    price_per_night = apt.getPrice_perIndividual() * (guests-children); // adults
    if(children > 0)
    {
        price_per_night += apt.getPrice_perIndividual() * children;
    }
    total_price = price_per_night * (end_date-start_date);
    std::cout<<"Price per night: "<<price_per_night<<std::endl;
    std::cout<<"Total price: "<<total_price<<std::endl;
}