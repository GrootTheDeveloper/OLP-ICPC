#ifndef IREPORTABLE_H
#define IREPORTABLE_H

#include <string>

class IReportable {
public:
    virtual std::string generateReport() const = 0;
    virtual ~IReportable() {}
};

#endif
