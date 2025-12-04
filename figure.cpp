#include "figure.hpp"

Figure::Figure()
{
   std::cout << "Figure created simple!" << std::endl; 

}

Figure::Figure(const Figure & copy)
{
   std::cout << "Figure created copy!" << std::endl; 
   name = copy.getName();
}

void Figure::show()
{
   std::cout <<  getInfo();
}

Figure::~Figure()
{
   std::cout << "Figure deleted!" << std::endl; 
}

void Figure::setName(std::string new_name)
{
      name = new_name;
}

std::string Figure::getName() const
{
return name;
}


