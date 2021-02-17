#ifndef PHONECALLS_HPP
#define PHONECALLS_HPP
/** phonecalls.hpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our derived class, phonecalls.
 * 
 * The phonecalls class will be the one using RTTI. It will have a
 * function that allows the user to mask/unmask the phone number
 * when it's being displayed (for privacy).
 * 
 */

#include "calendar.hpp"

class phonecalls : public entry
{
public:
    //Derived class default constructor
    phonecalls();

    //Derived class default copy constructor
    phonecalls(char *arg1, char *arg2);

    //Derived class decault copy constructor
    phonecalls(entry &to_copy);

    //Derived class default destructor
    ~phonecalls();

    //Self similar functions
    bool add(entry *&to_add);
    bool add(char *arg1, char *arg2);
    bool edit(entry &to_edit);
    bool remove(entry &to_remove);
    void display() const;

    //RTTI function(s)
    bool enable_privacy(int add_privacy);

private:

protected:
    char *callee_name;
    char *phone_number;
    //to_mask: pass 0 for no, 1 for yes. Masking will make the  phone
    //number appear as '***-***-****' when displaying the entry.
    int to_mask;

};

#endif