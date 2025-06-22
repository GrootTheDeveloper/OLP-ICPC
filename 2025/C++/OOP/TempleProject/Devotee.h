#ifndef DEVOTEE_H
#define DEVOTEE_H

#include "Person.h"
#include <string>
#include <fstream> // de dung istream, ostream neu can
#include "IRankable.h"
#include "IEventParticipant.h"
class ReligiousEvent; // Forward declaration

class Devotee : public Person, public IRankable, public IEventParticipant {
private:
    std::string phone;
    std::string address;
    int meritPoint; // Diem "phuoc bau", "cong duc" tich luy
    std::string rank;
    void updateRank();

public:
    Devotee();
    Devotee(const std::string& _id, const std::string& _name, int _age,
            const std::string& _user, const std::string& _pass,
            const std::string& _phone, const std::string& _address,
            int _meritPoint = 0, const std::string& _rank = "Dong");

    // Getter & setter
   // std::string getRank() const { return rank; }
    int getMeritPoint() const { return meritPoint; }

    void addMerit(int point) {
        meritPoint += point;
        updateRank();
    }
    bool login(const std::string& username, const std::string& password) override;  // BẮT BUỘC PHẢI CÓ
    
    std::string getRankName() const override;
    void listEventsJoined(const std::vector<ReligiousEvent>& allEvents) const override;

    void setPhone(const std::string& _phone) { phone = _phone; }
    std::string getPhone() const { return phone; }

    void setAddress(const std::string& _address) { address = _address; }
    std::string getAddress() const { return address; }

    // Getter tu Person
    std::string getID() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }

    // Ham ao
    void displayInfo() const override;

    // Ham load/save
    bool loadFromStream(std::istream& in);
    void saveToStream(std::ostream& out) const;
};

#endif
