/** main.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * The purpose of this program is to create a calendar type program that will
 * keep track of 3 unique items such as phone calls, events, projects to finish.
 * The project to finish item will be a list of projects to finish.
 * 
 * We are playing with RTTI in this program and learning how to create a base
 * class with all the derived classes similar in function, but with different
 * data. We are going to be able to create a data structure that is a base class
 * object pointer that will be our weekly calendar.
 * 
 * The calendar itself will be using a DLL ADT. We will be using Dynamic Binding
 * to achieve all of this. We will have the base class and at least three other
 * classes with similar functions, and one class that has at least ONE function
 * that is different than the rest so we can experience RTTI in action.
 * 
 * NOTE: below
 * Program #2 – Important C++ Syntax
 * Remember to support the following constructs as necessary:
 * 1. Every class should have a default constructor
 * 2. Every class that manages dynamic memory must have a destructor
 * 3. Every class that manages dynamic memory must have a copy constructor
 * 4. If a derived class has a copy constructor, then it MUST have an
 *    initialization list to cause the base class copy constructor to be invoked
 * 5. Make sure to specify the base class’ destructor as virtual (but don’t make
 *    it a pure virtual function)
 * 6. It is expected that you will experience RTTI with dynamic_cast in this
 *    assignment
 *
 * NOTE: below
 * Program #2 – Data Structure Requirements
 * The real beauty of dynamic binding is that we can have a data structure be a
 * collection of different data types! There needs to be ONE data structure of
 * base class pointers used to represent your weekly calendar. This data
 * structure will keep track of all of the different items that are scheduled
 * for the week, using upcasting. Luckily, with upcasting, a base class pointer
 * can point to any object within the hierarchy.
 * The data structure will be a doubly linked list of calendar days, where
 * each day has a Linear linked list of base class pointers. Implementation of
 * the data structure(s) requires full support of insert, removal, display,
 * retrieval, and remove-all.
 *
 * RTTI Example:
 *   events *an_event = new calendar;
 *   calendar *cal = dynamic_cast<calendar*>(events);
 *   OR
 *   calendar an_entry = dynamic_cast<calendar&>(events);
 * 
 */

#include "events.hpp"
#include "phonecalls.hpp"
#include "projects.hpp"

int main(int argc, char **argv)
{
    calendar mainCal;
    events mainEvent;
    phonecalls mainPhone;
    projects mainProject;
    events *newEvent = dynamic_cast<events *>(&mainPhone);
    //entry *an_event = &mainEvent;
    //entry *a_phone = &mainPhone;
    //entry *a_project = &mainProject;
    char arg1[101];
    char arg2[101];

    int choice = 1;

    while (choice != 0)
    {
        cout << "\n********************\n";
        cout << " Main Menu\n";
        cout << " --------------------\n";
        cout << "1. Add an event\n";
        cout << "2. Add a phonecall\n";
        cout << "3. Add a project\n";
        cout << "4. Display calendar\n";
        cout << "5. Delete all\n";
        cout << "0. Exit the program\n";
        cout << "********************\n";
        cin >> choice;
        cin.ignore(100, '\n');

        switch (choice)
        {
        case 1:
            cout << "\nEnter the event name: ";
            cin.get(arg1, 100, '\n');
            cin.ignore(100, '\n');
            cout << "\nEnter the event time: ";
            cin.get(arg2, 100, '\n');
            cin.ignore(100, '\n');

            mainEvent.add(arg1, arg2);

            mainCal.add(mainEvent);

            cin.clear();
            break;

        case 2:
            cout << "\nEnter the Name to call: ";
            cin.get(arg1, 100, '\n');
            cin.ignore(100, '\n');
            cout << "\nEnter the phone number to call: ";
            cin.get(arg2, 100, '\n');
            cin.ignore(100, '\n');

            mainPhone.add(arg1, arg2);

            mainCal.add(mainPhone);
            cin.clear();
            break;

        case 3:
            cout << "\nEnter the project name: ";
            cin.get(arg1, 100, '\n');
            cin.ignore(100, '\n');
            cout << "\nEnter the project due date: ";
            cin.get(arg2, 100, '\n');
            cin.ignore(100, '\n');

            mainProject.add(arg1, arg2);

            mainCal.add(mainProject);
            cin.clear();
            break;

        case 4:
            cout << "\nDisplaying Calendar:\n";
            mainCal.display();
            break;

        case 5:
            cout << "\nRemoving all entries...\n";
            mainCal.remove_all();
            break;

        case 0:
            cout << "\nThank you and goodbye!\n";
            cin.clear();
            break;

        default:
            cout << "Invalid entry, try again.\n";
            cin.clear();
            continue;
        }
    }

    return 0;
}