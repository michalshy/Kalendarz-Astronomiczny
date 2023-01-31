//
// Created by Michin on 24.01.2023.
//

#include <conio.h>
#include "EventManager.h"
#include <fstream>
#include <vector>
#include <algorithm>


    std::string EventManager::findEvent(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, Date & today)
    {

        std::string uDate = today.get_date();
        int index = dates->searchByT(uDate);
        std::string temp = events->search(index);
        if(temp==key)
        {
            save(temp);
        }
        std::vector<std::string> event;
        event.push_back(temp);
        std::ofstream out("data.txt");
        std::ostream_iterator<char> wy(out, " ");
        copy(temp.begin(), temp.end(), wy);
        return temp;
    }

    void EventManager::instructions()
    {
        std::cout<<"Use keys A and D to move between dates and hold ALT while pressing any key to exit"<<std::endl;
        std::cout<<"--------------------------------------------------------------------------------------"<<std::endl<<std::endl;
    }

    void EventManager::iterate(std::shared_ptr<List<std::string>> dates, std::shared_ptr<List<std::string>> events, Date & today)
    {
        instructions();
        std::cout<<today.get_date()<<std::endl;
        std::cout<<findEvent(dates,events,today);
        char choice = ' ';
        choice = _getch();
        switch (choice)
        {
            case 'a':
                today.operator--();
                break;
            case 'd':
                today.operator++();
                break;
            default:
                break;
        }
        system("cls");
    }
    void EventManager::save(std::string &event)
    {
        events.insert(std::pair<std::string,int>(event,1));
    }


    void EventManager::toFile()
    {
        std::ofstream file;
        file.open("output.txt");

        std::string output;
        for(auto& kv: events)
        {
            file << kv.first << " - " << kv.second << std::endl;
        }
        file.close();
    }
