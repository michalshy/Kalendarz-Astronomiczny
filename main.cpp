//
// Created by Michin on 22.01.2023.
//
#include <string>
#include <iostream>
#include <Windows.h>
#include "Date.h"
#include "List.h"
#include "InputManager.h"
#include "EventManager.h"

int main()
{
    InputManager iManager;
    EventManager eManager;
    Date today;
    List<std::string> dates;
    List<std::string> events;
    auto ptrD = std::make_shared<List<std::string>>(dates);
    auto ptrE = std::make_shared<List<std::string>>(events);
    iManager.read(ptrD,ptrE,"daty.txt");
    do
    {
        eManager.iterate(ptrD,ptrE,today);
    }while(!(GetKeyState(VK_MENU) & 0x8000));
    eManager.toFile();
}
