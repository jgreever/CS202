#include "methods.hpp"


class contact
{
    public:
        contact();
        contact(contact &to_copy);
        ~contact();

        int add(char *to_add, device *a_device);

    private:

    protected:
        char *name;
        device *a_device;
};