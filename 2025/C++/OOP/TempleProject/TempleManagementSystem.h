#ifndef TEMPLEMANAGEMENTSYSTEM_H
#define TEMPLEMANAGEMENTSYSTEM_H

#include <vector>
#include <string>
#include <memory>

#include "Admin.h"
#include "Staff.h"
#include "Devotee.h"
#include "ReligiousEvent.h"

class TempleManagementSystem {
private:
    std::vector<Admin> admins;
    std::vector<Staff> staffs;
    std::vector<Devotee> devotees;
    std::vector<ReligiousEvent> events;

    Admin* currentAdmin = nullptr;
    Staff* currentStaff = nullptr;
    Devotee* currentDevotee = nullptr;

public:
    TempleManagementSystem();
    ~TempleManagementSystem();

    // ==================== FILE IO ====================
    void loadFromFile();      // đọc admins, staffs, devotees, events
    void saveDataToFile();    // ghi admins, staffs, devotees, events

    // ==================== LOGIN ====================
    bool loginAsAdmin(const std::string& user, const std::string& pass);
    bool loginAsStaff(const std::string& user, const std::string& pass);
    bool loginAsDevotee(const std::string& user, const std::string& pass);

    // ==================== REGISTER ====================
    void registerDevotee();

    // ==================== MENU ====================
    void mainMenu();
    void adminMenu();
    void staffMenu();
    void devoteeMenu();

    // ==================== ADMIN MANAGE ====================
    void adminManageEvent();
    void adminManageDevotee();
};

#endif
