#include "ReligiousEvent.h"
#include "Devotee.h" 
#include <iostream>
#include <algorithm>
#include <sstream>

ReligiousEvent::ReligiousEvent()
    : eventID(""), eventName(""), dateTime(""), location(""), description(""), maxParticipant(0) {}

ReligiousEvent::ReligiousEvent(const std::string& _id, const std::string& _name,
                               const std::string& _dateTime, const std::string& _location,
                               const std::string& _desc, int _maxPart)
    : eventID(_id), eventName(_name), dateTime(_dateTime),
      location(_location), description(_desc), maxParticipant(_maxPart) {}

bool ReligiousEvent::registerDevotee(const std::string& devoteeID) {
    if ((int)registeredDevotees.size() >= maxParticipant) {
        std::cerr << "Event is full. Cannot register more devotees!\n";
        return false;
    }
    auto it = std::find(registeredDevotees.begin(), registeredDevotees.end(), devoteeID);
    if (it != registeredDevotees.end()) {
        std::cerr << "Devotee already registered!\n";
        return false;
    }
    registeredDevotees.push_back(devoteeID);
    return true;
}

bool ReligiousEvent::removeDevotee(const std::string& devoteeID) {
    auto it = std::find(registeredDevotees.begin(), registeredDevotees.end(), devoteeID);
    if (it != registeredDevotees.end()) {
        registeredDevotees.erase(it);
        return true;
    }
    std::cerr << "Devotee not found in this event!\n";
    return false;
}

void ReligiousEvent::showInfo() const {
    std::cout << "EventID: " << eventID
              << ", Name: " << eventName
              << ", DateTime: " << dateTime
              << ", Location: " << location
              << ", MaxPart: " << maxParticipant
              << "\nDescription: " << description << std::endl;
}

void ReligiousEvent::showRegisteredDevotees(const std::vector<Devotee>& allDevotees) const {
    std::cout << "=== Danh sach Devotee da dang ky vao su kien [" << eventName << "] ===\n";
    for (const auto& devID : registeredDevotees) {
        auto it = std::find_if(allDevotees.begin(), allDevotees.end(),
                               [&devID](const Devotee& d) { return d.getID() == devID; });
        if (it != allDevotees.end()) {
            std::string rank;
            int merit = it->getMeritPoint();
            if (merit >= 1200) rank = "Thach Dau";
            else if (merit >= 900) rank = "Cao Thu";
            else if (merit >= 700) rank = "Kim Cuong";
            else if (merit >= 500) rank = "Luc Bao";
            else if (merit >= 300) rank = "Bach Kim";
            else if (merit >= 200) rank = "Vang";
            else if (merit >= 100) rank = "Bac";
            else rank = "Dong";

            std::cout << " - " << it->getName()
                      << " | Diem: " << merit
                      << " | Rank: " << rank << "\n";
        } else {
            std::cout << " - [Unknown Devotee ID: " << devID << "]\n";
        }
    }
}

// ================== SAVE TO STREAM ==================
void ReligiousEvent::saveToStream(std::ostream& out) const {
    // Format 1 dong:
    // eventID;eventName;dateTime;location;description;maxParticipant;D001,D002,...
    out << eventID << ";" 
        << eventName << ";" 
        << dateTime << ";" 
        << location << ";" 
        << description << ";" 
        << maxParticipant << ";";

    for (size_t i = 0; i < registeredDevotees.size(); ++i) {
        out << registeredDevotees[i];
        if (i < registeredDevotees.size() - 1)
            out << ",";
    }
    out << "\n";
}

// ================== LOAD FROM STREAM ==================
bool ReligiousEvent::loadFromStream(std::istream& in) {
    std::string line;
    if (!std::getline(in, line)) return false; // het file => false

    // Dinh dang: E001;Le Vu Lan;2025-08-15 08:00;Chinh Dien;Mo ta;100;D001,D002,...
    std::stringstream ss(line);

    std::string maxPStr;
    std::string devsStr;

    std::getline(ss, eventID, ';');
    std::getline(ss, eventName, ';');
    std::getline(ss, dateTime, ';');
    std::getline(ss, location, ';');
    std::getline(ss, description, ';');
    std::getline(ss, maxPStr, ';');
    maxParticipant = std::stoi(maxPStr);

    // Danh sach Devotee: D001,D002,...
    std::getline(ss, devsStr);
    registeredDevotees.clear();
    std::stringstream devSS(devsStr);

    std::string devID;
    while (std::getline(devSS, devID, ',')) {
        if (!devID.empty()) {
            registeredDevotees.push_back(devID);
        }
    }

    return true;
}
