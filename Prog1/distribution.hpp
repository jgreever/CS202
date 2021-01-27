#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

/** distribution.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * This is our distribution class file. It will manage how the  item that
 * the user purchased gets to them. This allows us to determine if the item
 * will be shipped via ground or air, and if it will be sent overnight, 
 * standard, or express based on the item location (which warehouse its at).
 * We have an option to hold a package in this class, in the event the user
 * decides they don't want the item, or need to pick it up at a local place
 * or new address.
 * 
 */

#include "warehouse.hpp"

class distribution : public warehouse
{
    public:
        //Default constructor
        distribution();

        //Copy constructor
        distribution(const int transport_type);

        //Default destructor
        ~distribution();

        //This will let us check the speed that the user choose for
        //delivery and ensure we match the fastest or best route to them.
        void check_speed();

        //This will allow us to check if we have ground or air transport
        //for a specific package/item being shipped.
        void check_transport();

        //This will allow us to hold a package in the event a person cancels
        //their order or needs it held for pickup at a local distribution center
        void hold_package(int tracking_num);

    protected:
        //User passes one of the following: 0 = ground, 1 = air
        int transportation_type;
};

class transportation : public distribution
{
    public:
        //Default constructor
        transportation();
        
        //Default destructor
        ~transportation();

        //Allows us to set the transport type, 0 = ground, 1 = air
        void set_transport();

        //Allows us to choose the speed, 0 = standard, 1 = express,
        //2 = overnight
        void choose_speed();

        //Allows us to change the speed, assuming the package is not too far in
        //the current shipping stage, much like Amazon. If it can't change the
        //speed, it *might* end up calling the hold_package(); function from the
        //distrubution class to hold onto the package.
        void change_speed();

    protected:
        //ship_how accepts 0 = ground, 1 = air
        int ship_how;

        //ship_speed accepts 0 = standard, 1 = express,
        //2 = overnight
        int ship_speed;
};

#endif