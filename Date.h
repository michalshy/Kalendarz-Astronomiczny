//
// Created by Michin on 22.01.2023.
//

#ifndef KALENDARZ_ASTRONOMICZNY_DATE_H
#define KALENDARZ_ASTRONOMICZNY_DATE_H
#include <iostream>
#include <string>
#include <ctime>


class Date {

    int day;
    int year;
    int month;

public:
    Date();
    std::string get_date();
    ~Date() = default;
    Date* operator ++ ()
    {
        if(month<12)
        {
            if(month<=7)
            {
                if(month%2==0 && month!=2)
                {
                    if(day==30)
                    {
                        day = 1;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
                else if(month==2)
                {
                    if(day == 28)
                    {
                        day=1;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
                else
                {
                    if(day==31)
                    {
                        day = 1;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
            }
            else
            {
                if(month%2==0)
                {
                    if(day==31)
                    {
                        day = 1;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
                else
                {
                    if(day==30)
                    {
                        day = 1;
                        month++;
                    }
                    else
                    {
                        day++;
                    }
                }
            }
        }else if(month==12)
        {
            if(day == 31)
            {
                std::cout<<"koniec roku!"<<std::endl;
            }
            else
            {
                day++;
            }
        }
        return this;
    }
    Date* operator --()
    {
        if(month>1)
        {
            if(month<=7)
            {
                if(month%2==0)
                {
                   if(day==1)
                   {
                       day=31;
                       month--;
                   }
                   else
                   {
                       day--;
                   }
                }
                else if(month!=3)
                {
                    if(day==1)
                    {
                        day=30;
                        month--;
                    }
                    else
                    {
                        day--;
                    }
                }
                else
                {
                    if(day==1)
                    {
                        day=28;
                        month--;
                    }
                    else
                    {
                        day--;
                    }
                }
            }
            else
            {
                if(month==8)
                {
                    if(day==1)
                    {
                        day=31;
                        month--;
                    }
                    else
                    {
                        day--;
                    }
                }
                else if(month%2==1)
                {
                    if(day==1)
                    {
                        day=31;
                        month--;
                    }
                    else
                    {
                        day--;
                    }
                }
                else
                {
                    if(day==1)
                    {
                        day=30;
                        month--;
                    }
                    else
                    {
                        day--;
                    }
                }

            }
        }
        else
        {
            if(day==1)
            {
                std::cout<<"Nie cofamy sie w czasie!"<<std::endl;
            }
            else
            {
                day--;
            }
        }
        return this;
    }
};


#endif //KALENDARZ_ASTRONOMICZNY_DATE_H
