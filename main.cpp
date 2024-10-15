#include <iostream>
#include "event.h"
#include <ctime>

bool compareTime(const std::tm& time1, const std::tm& time2) {
    time_t t1 = mktime(const_cast<std::tm*>(&time1));
    time_t t2 = mktime(const_cast<std::tm*>(&time2));
    return t1 > t2;
}

using namespace std;
int main() {
    cout << "compiles?" << endl;
    std::vector<Event*> eventList;

    Concert* conc1 = new Concert(2024, 11, 2, 14, 30, "ChristmasMusic", "MSG", "bandnametbd", "rocknroll");
    Conference* conf1 = new Conference();
    eventList.push_back(conc1);
    eventList.push_back(conf1);
  

    while (true) {
        cout << "enter the corresponding number to select a menu option" << endl;
        cout << "1. create a new event" << endl;
        cout << "2. search for event" << endl;
        cout << "3. Display details of all events" << endl;
        cout << "4. list all upcoming events" << endl;
        cout << "5. end program" << endl;
        int option = 1;
        cin >> option;
         switch (option)
        {
        case 1:
            {
                cout << "What Event would you like to create?" << endl << "1. Concert" << endl << "2. Conference" << endl;
                cin.ignore();
                int eventType;
                cin >> eventType;
                if (eventType == 1) {
                    Concert* conc = new Concert(2025, 11, 30, 20, 0, "Halloween Party", "HauntedHouse", "ghostband", "classical");
                    eventList.push_back(conc);
                }
                else if (eventType == 2) {
                    Conference* conf = new Conference();
                    eventList.push_back(conf);
                }
               /*else if (eventType == 3) {
                    
                }*/
                else
                    cout << "invalid event number, no event created" << endl;
            }
            break;
        case 2:
            {
                /*
                std::vector<Concert*> concVec;
                std::vector<Conference*> confVec;
                for (Event* e : eventList) {
                    if (Concert* conc = dynamic_cast<Concert*>(e)) {
                        cout << "type is concert" << endl;
                        concVec.push_back(conc);
                    }
                    else if (Conference* conf = dynamic_cast<Conference*>(e)) {
                        cout << "type is conference" << endl;
                        confVec.push_back(conf);
                    }
                }
                */
                cout << "1. Show all event Types" << endl << "2. Show only Concert events." << endl << "3. Show only Conference events." << endl;
                int eventType;
                cin >> eventType;

                cout << "1. Show all events reguardless of date" << endl << "2. Show events before a date." << endl << "3. Show events after a date." << endl;
                int dateType;
                cin >> dateType;

                int year, mon, day;
                if (dateType = 2 || dateType == 3) {
                    cout << "enter date as integers \"month day year\"" << endl;
                    cin >> mon >> day >> year;
                }
                std::tm date = {};
                date.tm_year = year - 1900;
                date.tm_mon = mon - 1;
                date.tm_mday = day;

                cout << "1. Show all events reguardless of location" << endl << "Show events at a given location. Enter Location name: " << endl;
                string locType;
                cin >> locType;

                std::vector<Event*> eventsMatching;

                for (Event* e : eventList) {
                    if (eventType == 1)
                        eventsMatching.push_back(e);
                    else if (eventType == 2)
                    { if (Concert* conc = dynamic_cast<Concert*>(e)) {eventsMatching.push_back(e);}}
                    else if (eventType == 2)
                    { if (Conference* conf = dynamic_cast<Conference*>(e)) {eventsMatching.push_back(e);}}

                    if (year == 0 && mon == 0 && day == 0) {
                        eventsMatching.push_back(e);
                    }
                    else if (dateType == 2) {
                       if (compareTime(e->getDate(), date)) {
                            eventsMatching.push_back(e);
                        }
                    }
                    else if (dateType == 3) {
                        if (compareTime(date, e->getDate())) {
                            eventsMatching.push_back(e);
                        }
                    }
                    
                    if (locType == "1") {
                        eventsMatching.push_back(e);
                    }
                    else if (!e->getName().compare(locType)) {
                        eventsMatching.push_back(e);
                    }
                        
                       
                }
                cout << "Events matching your criteria: " << endl;
                for (Event* e : eventsMatching) {
                    string s = e->getDetails();
                    cout << s << endl;
                }

            }   
            break;
         case 3:
            {
                for (Event* e : eventList) {
                    string t = e->getDetails();
                    cout << t << endl;
                }
            }
            break;
         case 4:
            {
                for (Event* e : eventList) {
                    string t = e->getName();
                    cout << t << endl;
                }
            }
            break;
        default:
            {
                //cleanup here
               exit(0); //end program
            }
        }
    }


    return 0;
}