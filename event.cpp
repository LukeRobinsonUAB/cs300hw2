#include "event.h"

//EVENT IMPL//

Event::Event() {
    this->eventDate = {};
    this->eventName = "Default Event Name";
    this->eventLocation = "No location set";
}

Event::Event(int year, int mon, int day, int hour, int min, std::string ceventName, std::string ceventLocation) {
   
   this->eventDate.tm_year = year - 1900;
   this->eventDate.tm_mon = mon - 1;
   this->eventDate.tm_mday = day;
   this->eventDate.tm_hour = hour;
   this->eventDate.tm_min = min;

   this->eventName = ceventName;
   this->eventLocation = ceventLocation;
}

bool Event::isUpcoming() {
   std::time_t currentTime = std::time(nullptr);
   std::tm* currentDate = std::localtime(&currentTime);
   std::time_t timeCurrent = std::mktime(const_cast<std::tm*>(currentDate));
   std::time_t timeDate = std::mktime(&this->eventDate);
   if (timeDate > timeCurrent) {
      return true; //event has NOT happened
   }
      return false; //event already happened
   }

std::string Event::getName() {
   return this->eventName;
}

///CONCERT IMPL//
Concert::Concert(int year, int mon, int day, int hour, int min, std::string ceventName, std::string ceventLocation, std::string cband, std::string cgenre) 
   : Event(year, mon, day, hour, min, ceventName, ceventLocation)
   {
      this->band = cband;
      this->genre = cgenre;
   }

std::string Concert::getDetails() {
   std::string concertDetails = "Concert: \n";
   concertDetails += "name: " + this->eventName + '\n' + "location: " + this->eventLocation + '\n' + "date: " + std::to_string(this->eventDate.tm_mon) + "/" + std::to_string(this->eventDate.tm_mday) + "/" + std::to_string(this->eventDate.tm_year) + std::to_string(this->eventDate.tm_hour) + ":" + std::to_string(this->eventDate.tm_min) + '\n';
   concertDetails += "band: " + this->band + '\n' + "genre: " + this->genre + '\n';
   return concertDetails; 
}


//CONF IMPL//

std::string Conference::getDetails() {
   std::string conferenceDetails = "Conference: \n";
   conferenceDetails += "name: " + this->eventName + '\n' + "location: " + this->eventLocation + '\n' + "date: " + std::to_string(this->eventDate.tm_mon) + "/" + std::to_string(this->eventDate.tm_mday) + "/" + std::to_string(this->eventDate.tm_year) + std::to_string(this->eventDate.tm_hour) + ":" + std::to_string(this->eventDate.tm_min) + '\n';
   conferenceDetails += "Topic: " + this->confTopic + '\n' + "speakers: " + '\n';
   for (std::string s : this->speakerList) {
      conferenceDetails += s + '\n';
   }
   return conferenceDetails;
}
