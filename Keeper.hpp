#ifndef __ClassKeeper__
#define __ClassKeeper__
#include <stdio.h>
#include <iostream>
#include "Note.hpp"
#include "List.h"

using namespace std;

class Keeper: public List<Note *>{
    
    private:
    public:
void showAll();

};
#include "Keeper.cpp"
#endif // __ClassList__

