//
// Created by Michin on 24.01.2023.
//

#ifndef KALENDARZ_ASTRONOMICZNY_INPUTMANAGER_H
#define KALENDARZ_ASTRONOMICZNY_INPUTMANAGER_H
#include "List.h"
#include <string>
#include <fstream>
class InputManager {
public:
    InputManager() = default;
    void read(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, const std::string &path);
    ~InputManager()=default;
};


#endif //KALENDARZ_ASTRONOMICZNY_INPUTMANAGER_H
