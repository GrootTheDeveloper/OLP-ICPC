#ifndef IEVENTPARTICIPANT_H
#define IEVENTPARTICIPANT_H

#include <vector>
#include <string>
class ReligiousEvent;

class IEventParticipant {
public:
    virtual void listEventsJoined(const std::vector<ReligiousEvent>& allEvents) const = 0;
    virtual ~IEventParticipant() {}
};

#endif
