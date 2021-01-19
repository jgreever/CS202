#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "warehouse.hpp"

class distribution : public warehouse
{
    public:
        distribution();
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
        int transportation_type; //0 = ground, 1 = air
};

#endif