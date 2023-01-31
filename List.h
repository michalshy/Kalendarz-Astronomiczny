//
// Created by Michin on 22.01.2023.
//

#ifndef KALENDARZ_ASTRONOMICZNY_LIST_H
#define KALENDARZ_ASTRONOMICZNY_LIST_H
#include "ListElement.h"
#include <iostream>
#include <algorithm>

template<class T>
class List {
    ListElement<T>* head;
    int size;
public:
    List();
    explicit List(ListElement<T>*);
    List(const List &listCopy);
    List(const List &&listMove) noexcept ;

    ListElement<T>* get_head(){ return head; }
    void set_head(ListElement<T>* arg);

    void add_element(T value);
    T search(int index);
    int searchByT(T arg);
    void pop();

    std::ostream & operator << (std::ostream &out)
    {
        if(head = nullptr)
        {
            []()noexcept { throw std::out_of_range("empty list!"); };
        }
        else
        {
            ListElement<T>* current = head;
            std::cout<<current->get_element()<<std::endl;
            while(current->get_next()!= nullptr)
            {
                std::cout<<current->get_element()<<std::endl;
                current = current->get_next();
            }
        }
    }
    std::istream & operator >> (std::istream &in)
    {
        T value;
        std::cin>>value;
        add_element(value);
    }


    ~List();
};

template<class T>
void List<T>::set_head(ListElement<T>* arg) {
    head = arg;
}

template<class T>
List<T>::List() {
    head = nullptr;
    size = 0;
}

template<class T>
List<T>::List(ListElement<T> * arg) {
    head = arg;
    size = 1;
}

template<class T>
List<T>::List(const List &listCopy) {
    head = listCopy.head;
    size = listCopy.size;
}

template<class T>
List<T>::List(const List &&listMove) noexcept {
    head(std::move(listMove.head));
    size(std::move(listMove.size));
    listMove.head = nullptr;
    listMove.size = 0;
}

template<class T>
List<T>::~List() {
    for(int i=0; i<size; i++)
    {
        pop();
    }
}

template<class T>
void List<T>::add_element(T value) {
    if(head== nullptr)
    {
        head = new ListElement<T>(value);
        size++;
    }
    else
    {
        ListElement<T>* current = head;
        while(current->get_next() != nullptr)
        {
            current = current->get_next();
        }
        ListElement<T>* temp = new ListElement<T>(value);
        current->set_next(temp);
        size++;
    }

}

template<class T>
T List<T>::search(int index) {
    ListElement<T>* current = head;
    for(int i=0; i<index; i++)
    {
        current=current->get_next();
    }
    return current->get_element();
}

template<class T>
void List<T>::pop() {
    if(head== nullptr)
    {
        []()noexcept { throw std::out_of_range("empty list!"); };
    }
    else if(head->get_next()== nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        ListElement<T>* current = head;
        ListElement<T>* next = head->get_next();
        while(next->get_next()!= nullptr)
        {
            current=current->get_next();
            next = next->get_next();
        }
        current->set_next(nullptr);
        delete next;
    }

}

template<class T>
int List<T>::searchByT(T arg) {
    int index = 0;
    ListElement<T>* current = head;
    while(current->get_element()!=arg)
    {
        current=current->get_next();
        index++;
    }
    return index;
}


#endif //KALENDARZ_ASTRONOMICZNY_LIST_H
