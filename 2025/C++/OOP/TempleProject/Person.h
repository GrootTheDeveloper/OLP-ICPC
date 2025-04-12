#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include "ILoginable.h"

class Person : public ILoginable {
protected:
    std::string id;
    std::string name;
    int age;
    std::string username;
    std::string password;

public:
    Person();
    Person(const std::string& _id, const std::string& _name, int _age,
           const std::string& _user, const std::string& _pass);

    virtual ~Person() {}

    //Getter/Setter cơ bản
    std::string getID() const { return id; }
    void setID(const std::string& _id) { id = _id; }

    std::string getName() const { return name; }
    void setName(const std::string& _name) { name = _name; }

    int getAge() const { return age; }
    void setAge(int _age) { age = _age; }

    virtual bool login(const std::string& user, const std::string& pass);

    // Hàm ảo thuần túy => Person trở thành lớp abstract
    virtual void displayInfo() const = 0; 
};

#endif
