#include "Object_d3.hpp"

Object_d3::~Object_d3()
{
   std::cout << "Object_d3 deleted!" << std::endl; 
}

Object_d3::Object_d3()
{
   std::cout << "Object_d3 create simple!" << std::endl; 

}

std::string Object_d3::getInfo()
{
   std::string str;
    str += "{" +std::string("\n");
    str += "type: "+getType() +std::string("\n");
    str += "name: "+getName() +std::string("\n");
    str += "img: "+getImg() +std::string("\n");
    str += "sizes: "+getSizes() +std::string("\n");
    str += "square: "+std::to_string( getSquare()) +std::string("\n");
    str += "volume: "+std::to_string( getVolume()) +std::string("\n");
    str += "}" +std::string("\n");
    return str;
}
