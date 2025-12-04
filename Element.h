#ifndef __ClassElement__
#define __ClassElement__
template <class T>
class Element{
    private:
        T data;
        Element<T> *next = 0;
        Element<T> *prev = 0;
    public:
        T getData() const;
        void setData(T val);
        Element* getNext() const;
        Element* getPrev() const;
        void setNext(Element* val);
        void setPrev(Element* val);
    ~Element();
};
#include "Element.cpp"
#endif // __ClassElement__