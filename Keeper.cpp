#include "Keeper.hpp"


void Keeper::showAll()
{
    if(this->len()==0){
        std::cout<<"Pass Keeper";
    }
    for(int i =0;i<this->len();++i){
        this->at(i)->getData()->show();
    }
}

void Keeper::sort(bool reverse)
{
    
}

std::string Keeper::get_string_month(int month)
{
    std::string res;
    bool pass = true;
    for(int i = 0;i<this->len();++i){
        Note *n = this->at(i)->getData();
        if(n->get_date(1) == month){
           pass = false; 
           res+=n->to_string();
           res+=std::string("\n");
        }
    }
    if(pass){
        res = std::string("Not found Notes wuth month:") + std::to_string(month) + std::string("\n");
    }
    return res;
}
