#include "TempleManagementSystem.h"
#include <iostream>
#include <limits>
#include <fstream>   // de doc/ghi file
#include <sstream>   // neu can
#include <cstdlib>   // system("cls")
#include <iomanip>   // setw
#include <algorithm>
using namespace std;

// ==== HAM PHU TRỢ ====
static void pauseAndClear() {
    // Bỏ hết phần còn sót trong buffer (nếu có)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n(Nhan Enter de tiep tuc...)";
    std::cin.get();
    system("cls");
}


// bảng sự kiện
static void printEventTable(const vector<ReligiousEvent>& events) {
    cout << left
         << setw(5)  << "STT"
         << setw(12) << "EventID"
         << setw(20) << "Ten SK"
         << setw(20) << "Thoi Gian"
         << setw(15) << "Dia diem"
         << setw(8)  << "Max"
         << "\n";

    cout << string(80, '-') << "\n";

    for (size_t i = 0; i < events.size(); ++i) {
        cout << left
             << setw(5)  << (i + 1)
             << setw(12) << events[i].getEventID()
             << setw(20) << events[i].getEventName()
             << setw(20) << events[i].getDateTime()
             << setw(15) << events[i].getLocation()
             << setw(8)  << events[i].getMaxParticipant()
             << "\n";
    }
}

static void printDevoteeTable(const vector<Devotee>& devotees) {
    cout << left
         << setw(5)  << "STT"
         << setw(10) << "ID"
         << setw(20) << "Ten"
         << setw(4)  << "Tuoi"
         << setw(10) << "Rank"
         << setw(8)  << "Diem"
         << setw(12) << "Username"
         << "\n";
    cout << string(80, '-') << "\n";

    for (size_t i = 0; i < devotees.size(); ++i) {
        cout << left
             << setw(5)  << (i + 1)
             << setw(10) << devotees[i].getID()
             << setw(20) << devotees[i].getName()
             << setw(4)  << devotees[i].getAge()
             << setw(10) << devotees[i].getRankName()
             << setw(8)  << devotees[i].getMeritPoint()
             << setw(12) << devotees[i].getUsername()
             << "\n";
    }
}

// ==== CONSTRUCTOR / DESTRUCTOR ====
TempleManagementSystem::TempleManagementSystem() {
    loadFromFile();
}

TempleManagementSystem::~TempleManagementSystem() {
    saveDataToFile();
}

// ===================== FILE IO =====================
void TempleManagementSystem::loadFromFile() {
    admins.clear();
    staffs.clear();
    devotees.clear();
    events.clear();

    // Admins
    {
        ifstream fin("data/admins.txt");
        if (fin.is_open()) {
            Admin temp;
            while (temp.loadFromStream(fin)) {
                admins.push_back(temp);
            }
            fin.close();
        }
    }

    // Staffs
    {
        ifstream fin("data/staffs.txt");
        if (fin.is_open()) {
            Staff temp;
            while (temp.loadFromStream(fin)) {
                staffs.push_back(temp);
            }
            fin.close();
        }
    }

    // Devotees
    {
        ifstream fin("data/devotees.txt");
        if (fin.is_open()) {
            Devotee temp;
            while (temp.loadFromStream(fin)) {
                devotees.push_back(temp);
            }
            fin.close();
        }
    }

    // Events
    {
        ifstream fin("data/events.txt");
        if (fin.is_open()) {
            ReligiousEvent temp;
            while (temp.loadFromStream(fin)) {
                events.push_back(temp);
            }
            fin.close();
        }
    }
}

void TempleManagementSystem::saveDataToFile() {
    // Admin
    {
        ofstream fout("data/admins.txt");
        if (fout.is_open()) {
            for (auto &ad : admins) {
                ad.saveToStream(fout);
            }
            fout.close();
        }
    }

    // Staff
    {
        ofstream fout("data/staffs.txt");
        if (fout.is_open()) {
            for (auto &st : staffs) {
                st.saveToStream(fout);
            }
            fout.close();
        }
    }

    // Devotee
    {
        ofstream fout("data/devotees.txt");
        if (fout.is_open()) {
            for (auto &dv : devotees) {
                dv.saveToStream(fout);
            }
            fout.close();
        }
    }

    // Event
    {
        ofstream fout("data/events.txt");
        if (fout.is_open()) {
            for (auto &ev : events) {
                ev.saveToStream(fout);
            }
            fout.close();
        }
    }
}

// ================== LOGIN FUNCS ==================
bool TempleManagementSystem::loginAsAdmin(const std::string& user, const std::string& pass) {
    for (auto& ad : admins) {
        if (ad.login(user, pass)) {
            currentAdmin = &ad;
            return true;
        }
    }
    return false;
}

bool TempleManagementSystem::loginAsStaff(const std::string& user, const std::string& pass) {
    for (auto& st : staffs) {
        if (st.login(user, pass)) {
            currentStaff = &st;
            return true;
        }
    }
    return false;
}

bool TempleManagementSystem::loginAsDevotee(const std::string& user, const std::string& pass) {
    for (auto& dv : devotees) {
        if (dv.login(user, pass)) {
            currentDevotee = &dv;
            return true;
        }
    }
    return false;
}

// ================== REGISTER DEVOTEE ==================
void TempleManagementSystem::registerDevotee() {
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    std::string id, name, user, pass, phone, addr;
    int age;
    std::cout << "----- Register New Devotee -----\n";
    std::cout << "ID: ";
    std::getline(std::cin, id);
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Age: ";
    std::cin >> age;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    std::cout << "Username: ";
    std::getline(std::cin, user);
    std::cout << "Password: ";
    std::getline(std::cin, pass);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);
    std::cout << "Address: ";
    std::getline(std::cin, addr);

    Devotee newDev(id, name, age, user, pass, phone, addr, 0);
    devotees.push_back(newDev);
    std::cout << "Devotee registered successfully!\n";
    pauseAndClear();
}

// ================== MAIN MENU ==================
void TempleManagementSystem::mainMenu() {
    while (true) {
        system("cls");
        std::cout << "\n===== TEMPLE MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Login as Admin\n";
        std::cout << "2. Login as Staff\n";
        std::cout << "3. Login as Devotee\n";
        std::cout << "4. Register new Devotee\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";

        int choice;
        std::cin >> choice;
        if (!std::cin || choice < 0) {
            std::cout << "Invalid choice! \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            pauseAndClear();
            continue;
        }

        switch (choice) {
        case 1: {
            system("cls");
            std::string user, pass;
            std::cout << "Username: ";
            std::cin >> user;
            std::cout << "Password: ";
            std::cin >> pass;
            if (loginAsAdmin(user, pass)) {
                std::cout << "Login Admin success!\n";
                pauseAndClear();
                adminMenu();
                currentAdmin = nullptr;
            } else {
                std::cout << "Login failed.\n";
                pauseAndClear();
            }
            break;
        }
        case 2: {
            system("cls");
            std::string user, pass;
            std::cout << "Username: ";
            std::cin >> user;
            std::cout << "Password: ";
            std::cin >> pass;
            if (loginAsStaff(user, pass)) {
                std::cout << "Login Staff success!\n";
                pauseAndClear();
                staffMenu();
                currentStaff = nullptr;
            } else {
                std::cout << "Login failed.\n";
                pauseAndClear();
            }
            break;
        }
        case 3: {
            system("cls");
            std::string user, pass;
            std::cout << "Username: ";
            std::cin >> user;
            std::cout << "Password: ";
            std::cin >> pass;
            if (loginAsDevotee(user, pass)) {
                std::cout << "Login Devotee success!\n";
                pauseAndClear();
                devoteeMenu();
                currentDevotee = nullptr;
            } else {
                std::cout << "Login failed.\n";
                pauseAndClear();
            }
            break;
        }
        case 4:
            registerDevotee();
            break;
        case 0:
            std::cout << "Exiting...\n";
            return;
        default:
            std::cout << "Invalid choice.\n";
            pauseAndClear();
            break;
        }
    }
}

// ============ MENU ADMIN ============
void TempleManagementSystem::adminMenu() {
    if (!currentAdmin) return;

    while (true) {
        system("cls");
        std::cout << "\n=== ADMIN MENU ===\n";
        std::cout << "1. Manage Events\n";
        std::cout << "2. Manage Devotees\n";
        std::cout << "0. Logout\n";
        std::cout << "Choose: ";

        int choice;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            pauseAndClear();
            continue;
        }
        switch (choice) {
        case 1:
            adminManageEvent();
            break;
        case 2:
            adminManageDevotee();
            break;
        case 0:
            std::cout << "Logging out Admin...\n";
            pauseAndClear();
            return;
        default:
            std::cout << "Invalid choice.\n";
            pauseAndClear();
            break;
        }
    }
}

// =========== ADMIN MANAGE EVENT ===========
void TempleManagementSystem::adminManageEvent() {
    while (true) {
        system("cls");
        std::cout << "\n=== QUAN LY SU KIEN (ADMIN) ===\n";
        std::cout << "1. Xem danh sach su kien (bang)\n";
        std::cout << "2. Tao su kien moi\n";
        std::cout << "3. Dang ky Devotee vao su kien\n";
        std::cout << "4. Xem danh sach Devotee da dang ky\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Lua chon cua ban: ";

        int choice;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            pauseAndClear();
            continue;
        }

        if (choice == 0) {
            pauseAndClear();
            break;
        }

        switch (choice) {
        case 1: {
            system("cls");
            std::cout << "\n=== DANH SACH SU KIEN (Bang) ===\n";
            printEventTable(events);
            pauseAndClear();
            break;
        }
        case 2: {
            system("cls");
            std::cin.ignore();
            std::string id, name, dt, loc, desc;
            int maxp;

            std::cout << "Ma su kien: "; std::getline(std::cin, id);
            std::cout << "Ten su kien: "; std::getline(std::cin, name);
            std::cout << "Thoi gian: "; std::getline(std::cin, dt);
            std::cout << "Dia diem: "; std::getline(std::cin, loc);
            std::cout << "Mo ta: "; std::getline(std::cin, desc);
            std::cout << "So luong tham gia toi da: "; std::cin >> maxp;

            events.emplace_back(id, name, dt, loc, desc, maxp);
            std::cout << "Tao su kien thanh cong!\n";
            pauseAndClear();
            break;
        }
        case 3: {
            system("cls");
            if (events.empty() || devotees.empty()) {
                std::cout << "Khong co su kien hoac Devotee de xu ly.\n";
                pauseAndClear();
                break;
            }

            std::cout << "\n=== DANH SACH SU KIEN ===\n";
            printEventTable(events);

            std::cout << "\nChon so thu tu su kien: ";
            int eIdx;
            std::cin >> eIdx;

            std::cout << "\n=== DANH SACH DEVOTEE ===\n";
            printDevoteeTable(devotees);

            std::cout << "\nChon so thu tu Devotee: ";
            int dIdx;
            std::cin >> dIdx;

            if (eIdx > 0 && eIdx <= (int)events.size() &&
                dIdx > 0 && dIdx <= (int)devotees.size()) {
                events[eIdx - 1].registerDevotee(devotees[dIdx - 1].getID());
                std::cout << "Dang ky thanh cong!\n";
            } else {
                std::cout << "Lua chon khong hop le.\n";
            }
            pauseAndClear();
            break;
        }
        case 4: {
            system("cls");
            std::cout << "\n=== CHON SU KIEN DE XEM DANH SACH DANG KY ===\n";
            for (size_t i = 0; i < events.size(); ++i) {
                std::cout << i + 1 << ". " << events[i].getEventName() << "\n";
            }

            std::cout << "Chon so: ";
            int eIdx;
            std::cin >> eIdx;

            if (eIdx > 0 && eIdx <= (int)events.size()) {
                events[eIdx - 1].showRegisteredDevotees(devotees);
            } else {
                std::cout << "Lua chon khong hop le.\n";
            }
            pauseAndClear();
            break;
        }
        default:
            std::cout << "Lua chon khong hop le.\n";
            pauseAndClear();
        }
    }
}

// =========== ADMIN MANAGE DEVOTEE ===========
void TempleManagementSystem::adminManageDevotee() {
    while (true) {
        system("cls");
        std::cout << "\n=== QUAN LY DEVOTEE ===\n";
        std::cout << "1. Xem danh sach Devotee\n";
        std::cout << "2. Tang diem cong duc\n";
        std::cout << "3. Thong ke xep hang cong duc\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Lua chon cua ban: ";

        int choice;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            pauseAndClear();
            continue;
        }

        switch (choice) {
        case 0: {
            pauseAndClear();
            return;
        }
        case 1: {
            system("cls");
            std::cout << "\n=== DANH SACH DEVOTEE (Bang) ===\n";
            printDevoteeTable(devotees);
            pauseAndClear();
            break;
        }
        case 2: {
            system("cls");
            if (devotees.empty()) {
                std::cout << "Chua co Devotee nao.\n";
                pauseAndClear();
                break;
            }

            printDevoteeTable(devotees);

            std::cout << "\nChon so thu tu Devotee: ";
            int idx;
            std::cin >> idx;
            if (idx <= 0 || idx > (int)devotees.size()) {
                std::cout << "Lua chon khong hop le.\n";
                pauseAndClear();
                break;
            }

            std::cout << "Nhap so diem cong duc muon cong them: ";
            int add;
            std::cin >> add;
            devotees[idx - 1].addMerit(add);
            std::cout << "Cong them " << add
                      << " diem cong duc cho " << devotees[idx - 1].getName() << "\n";
            pauseAndClear();
            break;
        }
        case 3: {
            std::cout << "\n=== THONG KE XEP HANG CONG DUC ===\n\n";
        
            std::vector<Devotee> sortedDevotees = devotees;
            std::sort(sortedDevotees.begin(), sortedDevotees.end(), [](const Devotee& a, const Devotee& b) {
                return a.getMeritPoint() > b.getMeritPoint(); // giảm dần
            });
        
            std::cout << std::left
                      << std::setw(6)  << "STT"
                      << std::setw(10) << "ID"
                      << std::setw(20) << "Ten"
                      << std::setw(5)  << "Tuoi"
                      << std::setw(15) << "SDT"
                      << std::setw(20) << "Dia chi"
                      << std::setw(10) << "Diem"
                      << std::setw(15) << "Hang"
                      << "\n";
        
            std::cout << std::string(101, '-') << "\n";
        
            for (size_t i = 0; i < sortedDevotees.size(); ++i) {
                const auto& dv = sortedDevotees[i];
                std::cout << std::left
                          << std::setw(6)  << i + 1
                          << std::setw(10) << dv.getID()
                          << std::setw(20) << dv.getName()
                          << std::setw(5)  << dv.getAge()
                          << std::setw(15) << dv.getPhone()
                          << std::setw(20) << dv.getAddress()
                          << std::setw(10) << dv.getMeritPoint()
                          << std::setw(15) << dv.getRankName()
                          << "\n";
            }
        
            pauseAndClear();
            break;
        }
        default:
            std::cout << "Lua chon khong hop le.\n";
            pauseAndClear();
        }
    }
}

// ============ STAFF MENU ============
void TempleManagementSystem::staffMenu() {
    if (!currentStaff) return;

    while (true) {
        system("cls");
        std::cout << "\n=== STAFF MENU ===\n";
        std::cout << "1. Xem danh sach cac su kien (Bang)\n";
        std::cout << "2. Dang ky su kien cho Devotee\n";
        std::cout << "3. Xem danh sach Devotee trong su kien\n";
        std::cout << "4. Ghi nhan ung ho tu Devotee\n";
        std::cout << "0. Logout\n";
        std::cout << "Choose: ";
        int choice;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            pauseAndClear();
            continue;
        }
        if (choice == 0) {
            std::cout << "Logging out Staff...\n";
            pauseAndClear();
            return;
        }
        switch (choice) {
        case 1: {
            system("cls");
            std::cout << "\n=== DANH SACH SU KIEN (Bang) ===\n";
            printEventTable(events);
            pauseAndClear();
            break;
        }
        case 2: {
            system("cls");
            std::cout << "\n=== DANH SACH SU KIEN ===\n";
            printEventTable(events);

            std::cout << "\n=== DANH SACH DEVOTEE ===\n";
            printDevoteeTable(devotees);

            std::cout << "\nEventID: ";
            std::string eID;
            std::cin >> eID;
            std::cout << "DevoteeID: ";
            std::string dID;
            std::cin >> dID;

            ReligiousEvent* foundEv = nullptr;
            Devotee* foundDev = nullptr;

            for (auto& ev : events) {
                if (ev.getEventID() == eID) {
                    foundEv = &ev;
                    break;
                }
            }
            for (auto& dv : devotees) {
                if (dv.getID() == dID) {
                    foundDev = &dv;
                    break;
                }
            }

            if (!foundEv) {
                std::cout << " Event not found.\n";
            } else if (!foundDev) {
                std::cout << " Devotee not found.\n";
            } else {
                if (foundEv->registerDevotee(foundDev->getID())) {
                    std::cout << " Registered successfully.\n";
                } else {
                    std::cout << " Cannot register Devotee to this event.\n";
                }
            }
            pauseAndClear();
            break;
        }
        case 3: {
            system("cls");
            if (events.empty()) {
                std::cout << "Khong co su kien nao.\n";
                pauseAndClear();
                break;
            }

            std::cout << "\n=== CHON SU KIEN ===\n";
            printEventTable(events);

            std::cout << "Nhap so thu tu su kien: ";
            int idx;
            std::cin >> idx;

            if (idx <= 0 || idx > (int)events.size()) {
                std::cout << "Lua chon khong hop le.\n";
                pauseAndClear();
                break;
            }

            events[idx - 1].showRegisteredDevotees(devotees);
            pauseAndClear();
            break;
        }
        case 4: {
            std::string donorID;
            int amount;
        
            std::cout << "Nhap ID cua Devotee ung ho: ";
            std::cin >> donorID;
            std::cout << "Nhap so tien ung ho: ";
            std::cin >> amount;
        
            std::string donorName = "Khong ro";
            for (const auto& dv : devotees) {
                if (dv.getID() == donorID) {
                    donorName = dv.getName();
                    break;
                }
            }
        
            currentStaff->trackDonation(donorName, amount);
            pauseAndClear();
            break;
        }        
        default:
            std::cout << "Invalid choice.\n";
            pauseAndClear();
            break;
        }
    }
}

// ============ DEVOTEE MENU ============
void TempleManagementSystem::devoteeMenu() {
    if (!currentDevotee) return;

    while (true) {
        system("cls");
        std::cout << "\n=== DEVOTEE MENU ===\n";
        std::cout << "1. Xem tat ca su kien\n";
        std::cout << "2. Dang ky tham gia su kien\n";
        std::cout << "3. Xem thong tin ca nhan\n";
        std::cout << "4. Xem danh sach su kien da tham gia\n";
        std::cout << "0. Dang xuat\n";
        std::cout << "Lua chon cua ban: ";

        int choice;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            system("cls");
            std::cout << "\n=== DANH SACH SU KIEN ===\n";
            printEventTable(events);
            pauseAndClear();
            break;
        case 2: {
            system("cls");
            if (events.empty()) {
                std::cout << "Chua co su kien nao de dang ky.\n";
                pauseAndClear();
                break;
            }
            std::cout << "\n=== CHON SU KIEN DE DANG KY ===\n";
            printEventTable(events);

            std::cout << "Nhap so thu tu cua su kien (0 de huy): ";
            int eventIndex;
            std::cin >> eventIndex;
            if (eventIndex <= 0 || eventIndex > (int)events.size()) {
                std::cout << "Huy dang ky.\n";
                pauseAndClear();
                break;
            }
            if (events[eventIndex - 1].registerDevotee(currentDevotee->getID())) {
                currentDevotee->addMerit(5);
                std::cout << "Dang ky thanh cong! Ban nhan duoc +5 diem cong duc.\n";
            }
            pauseAndClear();
            break;
        }
        case 3:
            system("cls");
            std::cout << "\n=== THONG TIN CA NHAN ===\n";
            currentDevotee->displayInfo();
            pauseAndClear();
            break;

        case 4:
            std::cout << "\n=== SU KIEN DA THAM GIA ===\n";
            currentDevotee->listEventsJoined(events);
            pauseAndClear();
        break;        
        case 0:
            std::cout << "Dang xuat...\n";
            pauseAndClear();
            return;
        default:
            std::cout << "Lua chon khong hop le.\n";
            pauseAndClear();
        }
    }
}
