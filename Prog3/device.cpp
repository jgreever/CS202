/** device.cpp
 * 
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 * 
 * This file contains the Device class. This is the base class
 * for our 3 derrived classes: Phone, Pager, and VoIP.
 * 
 * This class holds our data for our derrived classes. It holds
 * a device *next, but this will most likely be removed and done
 * differently.
 * 
 */

#include "device.hpp"

template <class Type>
device<Type>::device() {}

//device::device(const device &to_copy) {}

template <class Type>
device<Type>::~device() {}

template <class Type>
int device<Type>::add(Type *to_add) { return 0; }

template <class Type>int device<Type>::remove() { return 0; }

template <class Type>
void device<Type>::display() const {}

template <class Type>
int device<Type>::search(Type *to_search) { return 0; }

/*
int device::remove(device &to_remove) { return 0; }

void device::set_next(device *next) { this->next = next; }

device *device::get_next() { return this->next; }
*/