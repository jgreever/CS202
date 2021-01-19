#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "warehouse.hpp"

class distribution : public warehouse
{
    public:
        distribution();
        ~distribution();
        void set_transport();
        void choose_speed();
        void change_speed();

    protected:
        int transportation_type; //0 = ground, 1 = air
};

#endif