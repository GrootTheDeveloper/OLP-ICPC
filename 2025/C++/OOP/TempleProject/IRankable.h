#ifndef IRANKABLE_H
#define IRANKABLE_H

#include <string>

class IRankable {
public:
    virtual std::string getRankName() const = 0;
    virtual ~IRankable() {}
};

#endif
