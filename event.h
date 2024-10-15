#ifndef _EVENTH_
#define _EVENTH_

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>

class Event {
    public:
        Event();
        Event(int year, int mon, int day, int hour, int min, std::string eventName, std::string eventLocation);
   
        //event is abstract base class
        //force each type of event to override details as they have diff details
        virtual std::string getDetails() = 0;

        bool isUpcoming();

        std::string getName();
        std::tm getDate();

    //protected allows subclasses to edit their own attributes rather than have to rely on functions
    //in Base class to modify a child object
    protected:
        std::tm eventDate = {};
        std::string eventName;
        std::string eventLocation;

};

class Concert : public Event {
public:
    Concert(int year, int mon, int day, int hour, int min, std::string eventName, std::string eventLocation, std::string band, std::string genre);
    std::string getDetails() override;
    //bool isUpcoming();
protected:
    std::string band;
    std::string genre;


};

class Conference : public Event {
public:
    std::string getDetails() override;
    //bool isUpcoming();
protected:
    std::vector<std::string> speakerList;
    std::string confTopic;

};


/*
class newEventType : public Event {
    public:
        newEventType();
        std::string getDetails() override;

    protected:
        //unique stuff to this event
};
*/

#endif