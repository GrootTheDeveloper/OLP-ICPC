#include "Person.h"

Person::Person() : age(0) {}

Person::Person(const std::string& _id, const std::string& _name, int _age,
               const std::string& _user, const std::string& _pass)
    : id(_id), name(_name), age(_age), username(_user), password(_pass) {}

bool Person::login(const std::string& user, const std::string& pass) {
    return (user == username && pass == password);
}
