//
// Created by Michin on 24.01.2023.
//

#ifndef KALENDARZ_ASTRONOMICZNY_EVENTMANAGER_H
#define KALENDARZ_ASTRONOMICZNY_EVENTMANAGER_H
#include "List.h"
#include "Date.h"
#include <map>

class EventManager {
    std::map<std::string, int> events;
    std::string key = "brak wydarzen";
public:
    std::string findEvent(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, Date & today);
    void instructions();
    void iterate(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, Date & today);
    void save(std::string & event);
    void toFile();
};


#endif //KALENDARZ_ASTRONOMICZNY_EVENTMANAGER_H
