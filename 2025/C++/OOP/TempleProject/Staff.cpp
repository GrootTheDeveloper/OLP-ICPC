#include "Staff.h"
#include <iostream>
#include <sstream>

Staff::Staff() : Person(), duty("NoDuty") {}

Staff::Staff(const std::string& _id, const std::string& _name, int _age,
             const std::string& _user, const std::string& _pass,
             const std::string& _duty)
    : Person(_id, _name, _age, _user, _pass), duty(_duty) {}

void Staff::displayInfo() const {
    std::cout << "[Staff] ID: " << id
              << ", Name: " << name
              << ", Age: " << age
              << ", Duty: " << duty << std::endl;
}

void Staff::trackDonation(const std::string& donorName, int amount) {
    std::cout << donorName << " da ung ho " << amount << " VND.\n";
}

void Staff::paySalary() {
    std::cout << "[STAFF] Salary paid to: " << getName() << std::endl;
}
// ================== SAVE ==================
void Staff::saveToStream(std::ostream& out) const {
    // Format 1 dong: id;name;age;username;password; duty;
    out << id << ";"
        << name << ";"
        << age << ";"
        << username << ";"
        << password << ";"
        << duty << ";\n";
}

// ================== LOAD ==================
bool Staff::loadFromStream(std::istream& in) {
    std::string line;
    if (!std::getline(in, line)) return false;  // het file => false

    std::stringstream ss(line);
    std::string ageStr;

    // Format: id;name;age;username;password;duty;
    std::getline(ss, id, ';');
    std::getline(ss, name, ';');
    std::getline(ss, ageStr, ';');
    age = std::stoi(ageStr);
    std::getline(ss, username, ';');
    std::getline(ss, password, ';');
    std::getline(ss, duty, ';');

    return true;
}
