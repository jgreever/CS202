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
    contact newContact;
    contact newList;
    phone *aPhone = new phone;
    pager *aPager = new pager;
    voip *aVoip = new voip;
    device *newPhone = reinterpret_cast<device *>(&aPhone);
    device *newPager = reinterpret_cast<device *>(&aPager);
    device *newVoip = reinterpret_cast<device *>(&aVoip);

    newList.add();
    newList.display();

    newList.add();
    newList.display();

    newList.add();
    newList.display();

    //newVoip = nullptr;
    //newPager = nullptr;
    //newPhone = nullptr;

    delete aVoip;
    delete aPager;
    delete aPhone;
    //delete newList;
    //aVoip = nullptr;
    //aPager = nullptr;
    //aPhone = nullptr;
    //newList = nullptr;

    return 0;

}