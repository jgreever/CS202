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

device::device() : number(nullptr), capabilities(nullptr),  device_type(nullptr), next(nullptr) {}

device::device(const device &to_copy) : number(to_copy.number), capabilities(to_copy.capabilities), device_type(to_copy.device_type), next(to_copy.next) {}

device::~device() {}

int device::add(device *to_add) { return 0; }

int device::remove() { return 0; } //TODO create non-public function

void device::display() const {}

int device::search(device *to_search) { return 0; }
