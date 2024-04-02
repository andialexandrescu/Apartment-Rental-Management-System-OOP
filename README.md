# Project Title:
## Apartment Rental Management System Object Oriented Programming C++
# Description:
It represents a management system meant to respond to inquiries based on user input. The user must
first specify the intent of using the platform, getting to experience two possible interfaces: Tenant's view
or Host's view.

A tenant is able to input search criteria, such as location, number of rooms/ guests (1) and maximum price range per
individual (per night). A list of results is displayed containing all of the apartments that fit the criteria chosen.
Then, the individual is prompted to either choose an apartment, or return to the searching submenu. Once a choice is made, the
tenant has to enter the apartment ID assigned and specify the dates of their booking (2). Shortly after, the user
has to re-enter the number of guests, mentioning how many are underage, in order to compute the total price of their stay.
The last steps of their booking involve user registration and initiating card transfer process.

The host is prompted immediately to create an account and mention how many apartments the individual intends to
upload on the platform. Once the apartment details are specified, the host is able to see the updated searching submenu.

# Technical implementations:

(1) - These choices are slightly different, considering an apartment might host more people due to it's capacity,
however it might have less rooms than expected.

(2) - Each apartment has a vector of int variables, being the dates in the year on which it has already been booked by
other clients. Since the user must include a start and end date of their stay, this specific time interval is being checked
whether it's available or not, then the apartment is booked if it is not overlapping with another time frame.

# Nu primesc notă dacă că nu am pus titlu și descriere

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)

## Tema 1

#### Cerințe
- [ ] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [ ] constructori de inițializare
    - [ ] constructor supraîncărcat
    - [ ] constructori de copiere
    - [ ] `operator=` de copiere
    - [ ] destructor
    - [ ] `operator<<` pentru afișare (std::ostream)
    - [ ] `operator>>` pentru citire (std::istream)
    - [ ] alt operator supraîncărcat ca funcție membră
    - [ ] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] opțiune pentru citirea și afișarea a n obiecte (1p)

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet
* funcționalitatea creată să folosească metode ale obiectului generic
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
