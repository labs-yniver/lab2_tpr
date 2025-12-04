#include "quadrate.hpp"

Quadrate::~Quadrate()
{
   std::cout << "Quadrate deleted!" << std::endl; 
}

Quadrate::Quadrate()
{
   std::cout << "Quadrate created simple!" << std::endl; 

}

Quadrate::Quadrate(const Figure & copy)
{
    if(copy.getType() != type){
        throw std::string("No correct type for copy");
    }
    
    Quadrate *cpy = (Quadrate*)(&copy);
    std::cout << "Quadrate created copy!" << std::endl; 
    height = cpy->getHeight();
    width = cpy->getWidth();
    setName(copy.getName());
}

uint32_t Quadrate::getSquare()
{
return height*width;
}

std::string Quadrate::getSizes()
{
return std::string("Size Quadrate: height = ")+std::to_string(height)+
std::string("; width = ")+std::to_string(width)+std::string(";") ;
}

std::string Quadrate::getImg()
{
    std::string str = "\n";
    str = str + std::string("+------+\n");
    str = str + std::string("|      |\n");
    str = str + std::string("|      |\n");
    str = str + std::string("+------+\n");
return str;
}

std::string Quadrate::getType() const
{
    return type;
}

void Quadrate::setSizes(uint32_t sizes[], uint32_t len)
{
    if(len<2){
        throw std::string("Error seting size Quadrate");
    }
    height = sizes[0];
    width = sizes[1];
}

bool Quadrate::save(std::ofstream & file)
{
    std::string line;
    file<<type<<std::endl;
    file<<getName()<<std::endl;
    file<<std::to_string(height)<<std::endl;
    file<<std::to_string(width)<<std::endl;
        return 1;
}

int Quadrate::load(std::ifstream & file)
{
    auto cur = file.tellg();  
    std::string line;
    if(!std::getline(file, line)){return -1;};
    std::cout<<"qad exemmmmmple line = "<<line<<std::endl;
    if(line.compare(type) != 0){
        file.seekg(cur, std::ifstream::beg);
        return 0;
    }
    if(!std::getline(file, line)){return -1;};
    setName(line);
    if(!std::getline(file, line)){return -1;};
    height = std::stoul(line);
    if(!std::getline(file, line)){return -1;};
    width = std::stoul(line);
        return 1;

}

uint32_t Quadrate::getHeight()
{
return height;
}

uint32_t Quadrate::getWidth()
{
return width;
}
