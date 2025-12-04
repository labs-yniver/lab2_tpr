#ifndef __ClassList__
#define __ClassList__
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include "Element.h"
#include <typeinfo>
#include <typeindex> 
#include <type_traits>
using namespace std;

template <class T>
class List{
    
    private:
        Element<T> *head = 0;
        Element<T> *last = 0;
    public:
        void print();
        ~List();
        List();
        explicit List(int var);
        List(const List<T> &l);
        void copy(List<T> &res) const;
        List<T> operator+(const List<T> &l2) const;
        List<T> operator+(const T &val);
        List& operator=(const List<T> &l2);
        Element<T>* getHead() const;
        void setHead(Element<T>* el);
        Element<T>* getLast() const;
        void setLast(Element<T>* el);
        
        void add(T var);
        Element<T>* at(int index);
        int remove(int index);
        int len()  const;
        bool operator == (const List<T> &l) const;
        bool operator != (const List<T> &l) const;

        
};
#include "List.cpp"
#endif // __ClassList__