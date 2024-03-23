#include <iostream>
#include <thread>
#include "Apartment.h"
#include "User.h"
#include "Reservation.h"
#include <limits>

int main() {
    // using setters to get rid of [unusedFunction] cppcheck error
    User test;
    test.setUsername("testing");

    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 136);
    Apartment Ap2("1wd27", "Santona, Spain", "Duplex", "Unique oceanfront location within a few meters from the beach. Very large terrace to enjoy.", 4, 6, 155);
    Apartment Ap3("323w", "Altea, Spain", "Villa", "Beautiful villa with a private pool and a hot tub in Altea’s prime location, on Don Cayo golf course and nestled away from highway noise. Ideal for big families or groups.", 4, 4, 120);
    Apartment Ap4("56sf7", "Florence, Italy", "Rental Unit", "Chez Geraldine is an apartment just outside the historical center. It’s predominantly a residential district, but the cathedral, Galleria dell'Accademia, and Piazza San Marco are a 15-minute walk away. Food stores, restaurants, and bars are close by.", 3, 5, 90);
    Apartment Ap5("9g65", "Dubrovnik, Croatia", "Rental Unit", "The apartment is perched on a small hill in Montovjerna, offering stunning views of the Adriatic Sea. Dubrovnik's Old Town is around a five-minute drive away, while the nearest beach, Bellevue, is around 300 metres away.", 4, 7, 180);
    Apartment Ap6("hdhsa", "Malaga, Spain", "Rental Unit", "Our vacation apartment with terrace and sea view is located on the beachfront, in the Huelin area. The seafront promenade and Plaza de Huelin are just 20 meters away.", 4, 7, 210);
    Apartment Ap7("dsaa53", "A Coruna, Spain", "Mansion", "La Casa de la Pradera is located in A Bana, A Coruna, Galicia. It is located 50 km from O Grove.", 4, 4, 115);
    Apartment Ap8("edas2sa", "Florence, Italy", "Entire Condo", "The apartment is located in a pedestrian area in the historic center of Florence, a stone's throw from the Duomo and Piazza della Signoria, and not far from the Ponte Vecchio and the Mercato di San Lorenzo.", 3, 4, 220);
    Apartment Ap9("adsw3aa", "Lecce, Italy", "Entire Suite", "Wooden Cabin situated just under 1 km away from Torre Rinalda and 9 km from Oaks.", 3, 4, 80);
    Apartment Ap10("sdgfas4", "Furore, Italy", "Duplex", "Romantic, quiet and sea view, this accommodation opens to the cozy area, consisting of a small living room with kitchenette from which you can access the panoramic terrace", 3, 4, 110);
    Apartment Ap11("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap12("asfDSDG", "Ko Samui, Thailand", "Entire Condo", "Enjoy the panoramic sea and mountain views from the pool, terrace and lush garden. The villa is located on a small hilltop in Maenam village, a locals-only spot with a bustling night market and long sandy beach.", 5, 8, 120);
    Apartment Ap13("fsafAS", "Kas, Turkey", "Villa", "This rental holiday villa is located in Kördere area of Kalkan. It is a holiday villa with sea view and with unseen pool area. The city center is 3 km away.", 5, 12, 260);
    Apartment Ap14("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap15("gsdAAS", "Jezierze, Poland", "Houseboat", "The Moors, or a cottage on the water, is a unique place where you can relax and connect with nature in a special way.", 1, 3, 75);
    Apartment Ap16("adsFAD", "Warsaw, Poland", "Rental Unit", "This apartment can be found in the modern city center, near Grzybowski Square and Saski Garden. A supermarket is located in the same building, and the Hala Mirowska food market is nearby, along with restaurants, cafes, and 2 modern art galleries.", 4, 5, 210);
    Apartment Ap17("fdjhg9", "Rabka-Zdroj, Poland", "Cottage", "Comfortable year-round cottages, located on a hill with a beautiful view of the forest. The perfect place to relax away from the hustle and bustle.", 3, 4, 125);

    Reservation r;
    r += Ap1; r += Ap2; r += Ap3; r += Ap4; r += Ap5; r += Ap6; r += Ap7; r += Ap8; r += Ap9; r += Ap10; r += Ap11; r += Ap12; r += Ap13; r += Ap14; r += Ap15; r += Ap16; r += Ap17;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout<<"Welcome to our apartment rental management system! Are you looking to rent an apartment while travelling OR would you like to put your apartment up for rent? Then, you're in the right place."<<std::endl;
    /*std::cout<<"Press Enter twice to continue browsing.";
    std::cin.get(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<std::endl<<"An interactive menu will be displayed to improve your user experience."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"------- These are of the apartments listed on our platform so far: -------"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    // using getters to get rid of [unusedFunction] cppcheck error
    std::vector<Apartment> vec_apts = r.getApts();
    for(const auto &apt: vec_apts)
    {
        std::cout<<apt<<std::endl;
    }

    User current_user;
    int choice_differentiate_users;
    bool credentials = false, booked = false;
    std::cout<<std::endl<<std::endl<<"Please select your choice of browsing: "<<std::endl;
    std::cout<<"1. Search for an apartment to rent\n2. Update/ upload details about an apartment I own"<<std::endl;
    std::cin>>choice_differentiate_users; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<std::endl<<"Loading..."<<std::endl;
    switch(choice_differentiate_users)
    {
        case 1:
            std::cout<<"------- Tenant's view -------"<<std::endl;
            do{
                r.proceedTransaction(r, booked);
            }while(!booked);
            std::cout<<"Last step of your booking is to create an account and to specify your card details."<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            std::cout<<std::endl<<"Account was created successfully. Your account details:"<<std::endl;
            std::cout<<current_user<<std::endl;
            std::cin>>r;
            // using getters to get rid of [unusedFunction] cppcheck error
            std::cout<<std::endl<<"These are your card details: "<<std::endl;
            std::cout<<"Card Number: "<<r.getCardNumber()<<std::endl;
            std::cout<<"Card Holder Name: "<<r.getCardHolderName()<<std::endl;
            std::cout<<"Card CVV: "<<r.getCardCVV()<<std::endl;
            std::cout<<std::endl<<"Payment received. Thank you for choosing our platform!"<<std::endl;
            break;
        case 2:
            std::cout<<"------- Host's View -------"<<std::endl;
            std::cout<<"You must create an account before proceeding to upload details about an apartment."<<std::endl;
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            if(credentials)
            {
                std::cout<<" Account was created successfully. Your account details:"<<std::endl;
                //std::cout<<current_user<<std::endl;

                // using getters to get rid of [unusedFunction] cppcheck error
                std::cout<<"Username: "<<current_user.getUsername()<<std::endl;
                std::cout<<"Password: "<<current_user.getPassword()<<std::endl;
                std::cout<<"First Name: "<<current_user.getFirstName()<<std::endl;
                std::cout<<"Last Name: "<<current_user.getLastName()<<std::endl;
                std::cout<<"Email: "<<current_user.getEmail()<<std::endl;
                std::cout<<"ID Number: "<<current_user.getIDNumber()<<std::endl;
                std::cout<<"ID Residence: "<<current_user.getIDResidence()<<std::endl;
                std::cout<<"Phone Number: "<<current_user.getPhoneNumber()<<std::endl;
                std::cout<<std::endl<<"How many apartments will your portfolio contain? Enter the number of apartments you would like to list on the market."<<std::endl;
                std::cout<<"Number of apartments to list: ";
                int no_apts;
                std::cin>>no_apts;
                for(int i = 0; i < no_apts; i++)
                {
                    Apartment Ap;
                    std::cin>>Ap;
                    r += Ap;
                }
                std::cout<<"Added successfully to the catalog."<<std::endl;
                std::cout<<"Would you like to see the updated version of the latest listed apartments?"<<std::endl;
                std::cout<<"1. Yes\n2. No"<<std::endl;
                int choice_display;
                std::cin>>choice_display;
                if(choice_display == 1)
                {
                    std::cout<<r;
                }
                std::cout<<std::endl<<"Thank you for choosing our platform!"<<std::endl;
            } else
            {
                std::cout<<" Account was not created. Stop and run this script again."<<std::endl;
            }
            break;
        default:
            return 0;
    }
    return 0;
}