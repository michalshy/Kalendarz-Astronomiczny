//
// Created by Michin on 24.01.2023.
//

#include "InputManager.h"

void InputManager::read(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, const std::string &path)
{
    std::string line;
    std::fstream file;
    file.open(path);
    int index = 0;
    while(std::getline(file,line))
    {
        if(index%2==0)
        {
            dates->add_element(line);
            index++;
        }
        else
        {
            events->add_element(line);
            index++;
        }
    }
}
