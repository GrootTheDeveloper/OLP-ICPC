#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include "IFinance.h"
#include <fstream>  

class Staff : public Person, public IFinance {
private:
    std::string duty; // Nhiem vu (ban le, ban tu thien, ban hanh chanh, ...)

public:
    Staff();
    Staff(const std::string& _id, const std::string& _name, int _age,
          const std::string& _user, const std::string& _pass,
          const std::string& _duty);

    void setDuty(const std::string& _duty) { duty = _duty; }
    std::string getDuty() const { return duty; }

    // Ham ao 
    void displayInfo() const override;
    void paySalary() override;  
   // void doAccounting() override;
   void trackDonation(const std::string& donorName, int amount) override;

    // === Save/Load to file (theo stream) ===
    bool loadFromStream(std::istream& in);      // doc 1 dong
    void saveToStream(std::ostream& out) const; // ghi 1 dong
};

#endif
