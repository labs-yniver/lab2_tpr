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
