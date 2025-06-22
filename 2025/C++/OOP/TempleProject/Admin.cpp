#include "Admin.h"
#include <iostream>
#include <sstream>  // stringstream

Admin::Admin() : Person(), role("Unknown") {}

Admin::Admin(const std::string& _id, const std::string& _name, int _age,
             const std::string& _user, const std::string& _pass,
             const std::string& _role)
    : Person(_id, _name, _age, _user, _pass), role(_role) {}

void Admin::displayInfo() const {
    std::cout << "[Admin] ID: " << id
              << ", Name: " << name
              << ", Age: " << age
              << ", Role: " << role << std::endl;
}

// ============ LOAD FROM STREAM ============
bool Admin::loadFromStream(std::istream& in) {
    std::string line;
    if (!std::getline(in, line)) return false; // het file

    std::stringstream ss(line);
    std::string ageStr;

    // Dinh dang moi dong: id;name;age;username;password;role;
    std::getline(ss, id, ';');
    std::getline(ss, name, ';');
    std::getline(ss, ageStr, ';');
    age = std::stoi(ageStr);
    std::getline(ss, username, ';');
    std::getline(ss, password, ';');
    std::getline(ss, role);

    return true; 
}

// ============ SAVE TO STREAM ============
void Admin::saveToStream(std::ostream& out) const {
    // Dinh dang 1 dong
    // id;name;age;username;password;role;
    out << id << ";"
        << name << ";"
        << age << ";"
        << username << ";"
        << password << ";"
        << role << ";\n";
}
