#include "calendar.hpp"

int main(int argc, char *argv[])
{
    calendar *mainCalendar = new calendar;
    day *mainDay = new day;
    event mainEvent;
    phonecall mainCall;
    project mainProject;
    entry *newEvent = &mainEvent;
    entry *newCall = &mainCall;
    entry *newProject = &mainProject;

    char arg1[] = {"This"};
    char arg2[] = {"That"};

    newEvent->add(arg1, arg2);
    mainDay->add(*newEvent);
    mainCalendar->add(mainDay);

    delete mainCalendar;
    delete mainDay;
    mainCalendar = nullptr;
    mainDay = nullptr;

    return 0;
}