#ifndef __ClassKeeper__
#define __ClassKeeper__
#include <stdio.h>
#include <iostream>
#include "List.h"
#include "Figure.hpp"
#include "quadrate.hpp"
#include "kube.hpp"

using namespace std;

class Keeper: public List<Figure*>{
    
    private:
    public:
bool save_to_file(std::string file_name);
bool load_from_file(std::string file_name);
void showAll();

};
#include "Keeper.cpp"
#endif // __ClassList__

