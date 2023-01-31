//
// Created by Michin on 22.01.2023.
//

#include "Date.h"
Date::Date()
{
    time_t ttime = time(0);
    tm *ltm = localtime(&ttime);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day =  ltm->tm_mday;

}
std::string Date::get_date()
{
    return std::to_string(day)+"."+std::to_string(month)+"."+std::to_string(year);
}

