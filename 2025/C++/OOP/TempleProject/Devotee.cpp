#include "Devotee.h"

#include <iostream>
#include <sstream> // stringstream
#include "ReligiousEvent.h"  

Devotee::Devotee()
    : Person(), phone(""), address(""), meritPoint(0), rank("Dong") {}

Devotee::Devotee(const std::string& _id, const std::string& _name, int _age,
                 const std::string& _user, const std::string& _pass,
                 const std::string& _phone, const std::string& _address,
                 int _meritPoint, const std::string& _rank)
    : Person(_id, _name, _age, _user, _pass),
      phone(_phone), address(_address), meritPoint(_meritPoint), rank(_rank) {}


void Devotee::displayInfo() const {
    std::cout << "[Devotee] ID: " << id
              << ", Name: " << name
              << ", Age: " << age
              << ", Phone: " << phone
              << ", Address: " << address
              << ", MeritPoint: " << meritPoint
              << ", Rank: " << rank
              << std::endl;
}
bool Devotee::login(const std::string& username, const std::string& password) {
    return (this->username == username && this->password == password);
}

std::string Devotee::getRankName() const {
    int p = meritPoint;
    if (p >= 100) return "Kim Cuong";
    if (p >= 70) return "Luc Bao";
    if (p >= 50) return "Bach Kim";
    if (p >= 30) return "Vang";
    if (p >= 20) return "Bac";
    if (p >= 10) return "Dong";
    return "Moi";
}
void Devotee::listEventsJoined(const std::vector<ReligiousEvent>& allEvents) const {
    std::cout << "Devotee " << name << " đã tham gia các sự kiện:\n";
    for (const auto& ev : allEvents) {
        for (const auto& id : ev.getRegisteredDevotees()) {
            if (id == this->getID()) {
                std::cout << " - " << ev.getEventName() << " (" << ev.getDateTime() << ")\n";
                break;
            }
        }
    }
}


void Devotee::updateRank() {
    if (meritPoint >= 1200) rank = "Thach Dau";
    else if (meritPoint >= 900) rank = "Cao Thu";
    else if (meritPoint >= 700) rank = "Kim Cuong";
    else if (meritPoint >= 500) rank = "Luc Bao";
    else if (meritPoint >= 300) rank = "Bach Kim";
    else if (meritPoint >= 200) rank = "Vang";
    else if (meritPoint >= 100) rank = "Bac";
    else rank = "Dong";
}

// ============ LOAD FROM STREAM ============
bool Devotee::loadFromStream(std::istream& in) {
    std::string line;
    if (!std::getline(in, line)) return false; // hết file => false

    // Dinh dang 1 dong: id;name;age;username;password;phone;address;meritPoint;rank;
    std::stringstream ss(line);

    std::string ageStr, meritStr;
    std::getline(ss, id, ';');
    std::getline(ss, name, ';');
    std::getline(ss, ageStr, ';');
    age = std::stoi(ageStr);

    std::getline(ss, username, ';');
    std::getline(ss, password, ';');
    std::getline(ss, phone, ';');
    std::getline(ss, address, ';');

    std::getline(ss, meritStr, ';');
    meritPoint = std::stoi(meritStr);

    std::getline(ss, rank, ';');

    // Cap nhat rank 1 lan nua cho chinh xac
    updateRank();
    return true;
}

// ============ SAVE TO STREAM ============
void Devotee::saveToStream(std::ostream& out) const {
    // id;name;age;username;password;phone;address;meritPoint;rank;
    out << id << ";"
        << name << ";"
        << age << ";"
        << username << ";"
        << password << ";"
        << phone << ";"
        << address << ";"
        << meritPoint << ";"
        << rank << ";\n";
}
