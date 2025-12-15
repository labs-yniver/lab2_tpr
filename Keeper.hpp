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
        void sort(bool reverse = false);
        std::string get_string_month(int month);

};
#include "Keeper.cpp"
#endif // __ClassList__

