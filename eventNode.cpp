#include "event.cpp"
class EventNode {
public:
    Event event;
    EventNode* next;

    EventNode(Event e) : event(e), next(nullptr) {}
};