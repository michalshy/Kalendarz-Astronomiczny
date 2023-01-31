//
// Created by Michin on 22.01.2023.
//

#ifndef KALENDARZ_ASTRONOMICZNY_LISTELEMENT_H
#define KALENDARZ_ASTRONOMICZNY_LISTELEMENT_H
#include <memory>

template<class T>
class ListElement {

    T element;
    ListElement<T>* next = nullptr;

public:
    ListElement();
    explicit ListElement(T value);
    void set_element(T arg);
    void set_next(ListElement<T>* _next);
    T get_element(){ return element; }
    ListElement<T>* get_next(){ return next; }
    ~ListElement()=default;
};


template<class T>
void ListElement<T>::set_element(T arg)
{
    element = arg;
}
template<class T>
void ListElement<T>::set_next(ListElement<T>* _next) {
        next = _next;
}

template<class T>
ListElement<T>::ListElement() {
    next = nullptr;
}

template<class T>
ListElement<T>::ListElement(T value) {
    element = value;
}


#endif //KALENDARZ_ASTRONOMICZNY_LISTELEMENT_H
