#include <iostream>
#include "event.h"
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
        cout << "3. Display details of event" << endl;
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
                for (Event* e : eventList) {
                    if (Concert* conc = dynamic_cast<Concert*>(e)) {
                        cout << "type is concert" << endl;
                    }
                    else if (Conference* conc = dynamic_cast<Conference*>(e)) {
                        cout << "type is conference" << endl;
                    }
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
                    string t = e->eventName;
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