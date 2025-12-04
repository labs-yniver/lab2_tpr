#include "List.h"

template<class T>
List<T>::List(){
    head = 0;
}

template<class T>
List<T>::List(int var){
    head = 0;
    for(int i = 0;i<(var);++i){
        this->add(0);
    }
}

template<class T>
void List<T>::add(T var)
{
    Element<T> *newi = new Element<T>;
    newi->setNext(0);
    newi->setData(var);
    newi->setPrev(0);
    Element<T> *curr = head;
    if(curr==0){
        head = newi;
        last = newi;
        return;
    }
    // newi->setPrev(curr);
    while(curr->getNext())
        curr = curr->getNext();
        
    newi->setPrev(curr);
    curr->setNext(newi);
    // curr->getNext()->setPrev(curr);
    last = newi;
}


template<class T>
void List<T>::print(){
    Element<T> *curr = head;
    if(curr == 0){
        cout<<"pass"<<endl;
        return;
    }
    char *c;
    if  ((type_index (typeid(curr->getData())).hash_code()==type_index (typeid(c)).hash_code())){
        while(curr->getNext()){
            printf("data = %s, prev = %p, next = %p\n",curr->getData(),(void*)curr->getPrev(),(void*)curr->getNext());
            curr= curr->getNext();
        }
        printf("data = %s, prev = %p, next = %p\n",curr->getData(),(void*)curr->getPrev(),(void*)curr->getNext());

    }else{
        while(curr->getNext()){
            cout<<"data = ";
            cout<<curr->getData()<<", ";
            cout<<"prev = ";
            cout<<(void*)curr->getPrev()<<", ";
            cout<<"next = ";
            cout<<(void*)curr->getNext()<<"\n";
            // printf("data = %d, prev = %p, next = %p\n",curr->getData(),(void*)curr->getPrev(),(void*)curr->getNext());
            curr= curr->getNext();
        }
        
            cout<<"data = "<<curr->getData()<<", ";
            cout<<"prev = "<<(void*)curr->getPrev()<<", ";
            cout<<"next = "<<(void*)curr->getNext()<<"\n";
    }
        // printf("data = %d, prev = %p, next = %p\n",curr->getData(),(void*)curr->getPrev(),(void*)curr->getNext());
}

template<class T>
Element<T>* List<T>::at(int index){
    Element<T>* curr = head;
    if(curr == 0){
        return curr;
    }
    for(int cur_index = 0;cur_index<(index)&&curr->getNext();cur_index++)
        curr= curr->getNext();
    return curr;
    
}


template<class T>
int List<T>::remove(int index){
    Element<T>* curr = head;
    if(curr==0){
        return 0;
    }
    if(index==0){
        curr = curr->getNext();
        head->setNext(0);
        delete head;
        head = curr;
        return 1;
    }
    for(int cur_index = 1;cur_index<(index)&&curr->getNext();cur_index++)
        curr= curr->getNext();
    if(curr->getNext()==0){
        return 0;
    }
    Element<T>* next_item = curr->getNext();
    curr->setNext(next_item->getNext());
    next_item->setNext(0);
    delete next_item;
    curr->getNext()->setPrev(curr);
    while(curr->getNext()){curr = curr->getNext();}
    last = curr;
    return 1;
}

template<class T>
void List<T>::setHead(Element<T>* el){
    head = el;
}

template<class T>
List<T>::~List(){
    delete head;
}


template<class T>
Element<T>* List<T>::getHead() const{
    return head;
}


template<class T>
Element<T>* List<T>::getLast() const{
    return last;
}

template<class T>
void List<T>::setLast(Element<T>* el){
    last = el;
}

template<class T>
void List<T>::copy(List<T> &res) const {
    if(res.getHead()!=0){
        delete res.getHead();
        res.setHead(0);
    }
    Element<T>* curr = this->getHead();
    if(curr == 0){
        res.setHead(0);
        return;
    }
    res.add(curr->getData());
    while(curr->getNext()){
        curr = curr->getNext();
        res.add(curr->getData());
    }
    return;
}

template<class T>
List<T> List<T>::operator+(const List &l2) const{
    List res;
    if(this->getHead()==0){
        res.setHead(0);
        return res;
    }
    this->copy(res);
    Element<T> * curr = l2.getHead();
    if(curr!=0){
        res.add(curr->getData());
        while(curr->getNext()){
            curr = curr->getNext();
            res.add(curr->getData());
        }
    }
    return res;
}

template<class T>
 List<T> List<T>::operator+(const T &val){
    add(val);//аргумент это то куда копируем
    List<T> *l = new List<T>;
    this->copy(*l);
    return *l;
 }


template<class T>
 List<T>::List( const List &l){
    l.copy(*this);//аргумент это то куда копируем
 }




template<class T>
List<T>& List<T>::operator =(const List &l){
    l.copy(*this);//аргумент это то куда копируем
    return *this;
}


template <class T>
int List<T>::len()  const{
    if(head==0){
        return 0;
    }
    Element<T> * curr = head;
    int i = 1;
    while(curr->getNext()!=0){
        ++i;
        curr = curr->getNext();
    }
    return i;
}

template <class T>
bool List<T>::operator == (const List<T> &l) const
{

    return len() == l.len();
}

template <class T>
bool List<T>::operator != (const List<T> &l) const
{
    return len() != l.len();
}