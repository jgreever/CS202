/** main.cpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * Program 3, or Let's Overload those operators and Inherit
 * our Base class!
 *
 * The main purpose of this program is to experience operator
 * overloading and continue with Inheritance.
 *
 * As per Program 3 instructions:
 * Apply Operator Overloading to these classes: An important
 * part of this assignment is to implement a complete set of
 * operators. The operators to support must include: =, +, +=,
 * [], ==, !=, the relational/equality operators, and the ability
 * to input/output data. You may apply these to a single class
 * or use them throughout your hierarchy.
 *
 * Using https://en.cppreference.com/w/cpp/language/operators
 * as a reference for Operator Overloading.
 *
 * Overloads planned (+/- a few more later):
 *   bool &operator==(const T&);
 *   bool &operator!=(const T&);
 *   bool &operator<(const T&);
 *   bool &operator>(const T&);
 *   T& operator+(const T&, const T&);
 *   T& operator[](const T&) const;
 *   T& operator=(const T&);
 *   T& operator+=(const T&);
 *
 */

#include "methods.hpp"

int main(int argc, const char * argv[]) {
    contact newList; // Makes a new contact list
    int menuChoice = 0;
    int choice = 0;

    do {

        cout << "\n\n";
        cout << "  Prog3 Device Contact List Organizer\n";
        cout << "  ====================================\n";
        cout << "  1.  Add an entry\n";
        cout << "  2.  Display an entry\n";
        cout << "  3.  Search for an entry\n";
        cout << "  4.  Remove all entries\n";
        cout << "\n";
        cout << "  0.  Exit\n";
        cout << "  ====================================\n";
        cout << "  Enter your selection: ";
        cin >> menuChoice;
        cin.ignore(100, '\n');
        cout << endl;
      
        switch (menuChoice) {
            case 1:
                cout << "\nWhat type of device will we be adding?\n";
                cout << "(1) for Phone, (2) for Pager, (3) for VoIP: ";
                cin >> choice;
                cin.ignore(100, '\n');
                newList.add(choice);
                cin.clear();
                break;

            case 2:
                newList.display();
                cin.clear();
                break;

            case 3:
                char searchEntry[256];
                cout << "\nEnter the name of the contact to search for:\n";
                cin.get(searchEntry, 265, '\n');
                cin.ignore(100, '\n');
                newList.search(searchEntry);
                cin.clear();
                break;

            case 4:
                newList.removeAll();
                cin.clear();
                break;

            case 0:
                break;

            default:
                cout << menuChoice << " is not a valid choice, please try again.\n";
                cin.clear();
            }
    } while (menuChoice != 0);
    return 0;
}