#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <vector>
#include <iostream>
#include "Apartment.h"

class Reservation { // reservation also acts as a submenu for choosing an apartment
private:
    int card_number;
    std::string card_holder_name;
    int cvv;
    std::vector<Apartment> l_apts;
public:
    // overloaded constructors
    Reservation();

    [[maybe_unused]] Reservation(int card_number, const std::string &card_holder_name, int cvv);
    ~Reservation();

    // operators
    Reservation& operator+=(const Apartment &apt); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const Reservation &r);// operator overloading as friend/ non-member functions
    friend std::istream& operator>>(std::istream& in, Reservation &r);

    // getters
    [[nodiscard]] std::vector<Apartment> getApts() const;
    [[nodiscard]] std::string getCardHolderName() const;
    [[nodiscard]] int getCardNumber() const;
    [[nodiscard]] int getCardCVV() const;

    // other methods
    static void searchMenu(const Reservation &r);
    static void convertDate(int year, int month, int day, int &date);
    void proceedTransaction(const Reservation &r, bool &booked);
    static void computeTransaction(const Apartment &apt, int start_date, int end_date);
};

#endif //OOP_RESERVATION_H