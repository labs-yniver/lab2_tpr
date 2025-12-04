#include "Element.h"

template<class T>
Element<T>::~Element(){
    if(this){
        if(this->next){
            delete this->next;
        }
    }   
}

template<class T>
T Element<T>::getData() const {
    if(this){
        return data;
    }
    return 0;
}

template<class T>
Element<T>* Element<T>::getNext() const {
    
    if(this){
        return next;
    }
    return 0;
}


template<class T>
void Element<T>::setData(T val){
    
    if(this){
    data = val;
    }
}
template<class T>
void Element<T>::setNext(Element<T>* val){
    
    if(this){
    next = val;
    }
}


template<class T>
Element<T>* Element<T>::getPrev() const{
    if(this){
        return prev;
    }
    return 0;
}


template<class T>
void Element<T>::setPrev(Element<T>* val){
    if(this){
    prev = val;
    }
}