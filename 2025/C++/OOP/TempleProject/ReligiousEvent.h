#ifndef RELIGIOUSEVENT_H
#define RELIGIOUSEVENT_H

#include <string>
#include <vector>
#include <fstream>
#include "Devotee.h" 
class Devotee;  // forward declaration
class ReligiousEvent {
private:
    std::string eventID;
    std::string eventName;
    std::string dateTime;    // Co the tach ngay/gio rieng
    std::string location;
    std::string description;
    int maxParticipant;

    // Luu danh sach ID Devotee da dang ky
    std::vector<std::string> registeredDevotees;

public:
    ReligiousEvent();
    ReligiousEvent(const std::string& _id, const std::string& _name,
                   const std::string& _dateTime, const std::string& _location,
                   const std::string& _desc, int _maxPart);

    // Getter / Setter
    std::string getEventID() const { return eventID; }
    std::string getEventName() const { return eventName; }
    std::string getDateTime() const { return dateTime; }
    std::string getLocation() const { return location; }
    std::string getDescription() const { return description; }
    int getMaxParticipant() const { return maxParticipant; }
    std::vector<std::string> getRegisteredDevotees() const { return registeredDevotees; }

    void setEventID(const std::string& _id) { eventID = _id; }
    void setEventName(const std::string& _name) { eventName = _name; }
    void setDateTime(const std::string& _dt) { dateTime = _dt; }
    void setLocation(const std::string& _loc) { location = _loc; }
    void setDescription(const std::string& _desc) { description = _desc; }
    void setMaxParticipant(int _max) { maxParticipant = _max; }
    void setRegisteredDevotees(const std::vector<std::string>& list) { registeredDevotees = list; }

    // Cac ham khac
    bool registerDevotee(const std::string& devoteeID);
    bool removeDevotee(const std::string& devoteeID);

    void showInfo() const;
    void showRegisteredDevotees(const std::vector<class Devotee>& allDevotees) const;

    // === Save/Load to stream
    bool loadFromStream(std::istream& in);
    void saveToStream(std::ostream& out) const;
};

#endif
