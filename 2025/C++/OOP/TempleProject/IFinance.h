// IFinance.h
#ifndef IFINANCE_H
#define IFINANCE_H
#include <string>
class IFinance {
public:
    virtual void paySalary() = 0;
    virtual void trackDonation(const std::string& donorName, int amount) = 0;

    virtual ~IFinance() {}
};

#endif
