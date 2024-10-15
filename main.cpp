#include <iostream>
#include "event.h"
#include <ctime>
#include <sstream>

bool compareTime(const std::tm& time1, const std::tm& time2) {
    time_t t1 = mktime(const_cast<std::tm*>(&time1));
    time_t t2 = mktime(const_cast<std::tm*>(&time2));
    return t1 > t2;
}

using namespace std;
int main() {
    std::vector<Event*> eventList;

    //sample input to fill stuff and test search func
    Concert* conc1 = new Concert(2024, 11, 2, 14, 30, "ChristmasMusic", "MSG", "bandnametbd", "rocknroll"); //sample input to fill stuff
    Concert* conc2 = new Concert(2024, 12, 15, 20, 00, "Jazz Night", "Blue Note Jazz Club", "Miles Davis Quintet", "Jazz");
    Concert* conc3 = new Concert(2024, 10, 20, 19, 15, "Classical Evening", "Sydney Opera House", "Vienna Philharmonic", "Classical");
    eventList.push_back(conc1);
    eventList.push_back(conc2);
    eventList.push_back(conc3);

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
                    int year, mon, day, hour, min;
                    std::string syear, smon, sday, shour, smin, name, loc, band, genre;
                    cout << "Enter info as \"year, month, day, hour, minute, event name, location, band, genre\"" << endl;
                    std::getline(std::cin, syear, ',');
                    year = std::stoi(syear);
                    std::getline(std::cin, smon, ',');
                    mon = std::stoi(smon);
                    std::getline(std::cin, sday, ',');
                    day = std::stoi(sday);
                    std::getline(std::cin, shour, ',');
                    hour = std::stoi(shour);
                    std::getline(std::cin, smin, ',');
                    min = std::stoi(smin);
                    std::getline(std::cin, name, ',');
                    std::getline(std::cin, loc, ',');
                    std::getline(std::cin, band, ',');
                    std::getline(std::cin, genre, '\n');

                    Concert* conc = new Concert(year, mon, day, hour, min, name, loc, band, genre);
                    eventList.push_back(conc);
                }
                else if (eventType == 2) {
                    int year, mon, day, hour, min;
                    std::string syear, smon, sday, shour, smin, name, loc, topic, temp;
                    cout << "Enter info as \"year, month, day, hour, minute, event name, location, conference topic, speaker1, speaker2, ... etc\"" << endl;
                    std::getline(std::cin, syear, ',');
                    year = std::stoi(syear);
                    std::getline(std::cin, smon, ',');
                    mon = std::stoi(smon);
                    std::getline(std::cin, sday, ',');
                    day = std::stoi(sday);
                    std::getline(std::cin, shour, ',');
                    hour = std::stoi(shour);
                    std::getline(std::cin, smin, ',');
                    min = std::stoi(smin);
                    std::getline(std::cin, name, ',');
                    std::getline(std::cin, loc, ',');
                    std::getline(std::cin, topic, ',');
                    std::getline(std::cin, temp, '\n');
                    std::vector<std::string> speakerNames;
                    std::stringstream ss(temp);
                    std::string nameTemp;
                     while (std::getline(ss, nameTemp, ',')) {
                        if (!nameTemp.empty() && nameTemp[0] == ' ') {
                            nameTemp.erase(0, 1);
                        }
                        speakerNames.push_back(nameTemp);
                    }
                    Conference* conf = new Conference(year, mon, day, hour, min, name, loc, topic, speakerNames);
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