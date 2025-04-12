#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <fstream> // de dung istream, ostream

class Admin : public Person {
private:
    std::string role;  // Vi du: "Tru tri", "Truong ban", ...

public:
    Admin();
    Admin(const std::string& _id, const std::string& _name, int _age,
          const std::string& _user, const std::string& _pass,
          const std::string& _role);

    void setRole(const std::string& _role) { role = _role; }
    std::string getRole() const { return role; }

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
