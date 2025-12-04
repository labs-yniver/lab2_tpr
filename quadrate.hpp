#ifndef __Quadrate__
#define __Quadrate__

#include "object_d2.hpp"

class Quadrate: public Object_d2{
    public:
        ~Quadrate();
        Quadrate();
        Quadrate(const Figure &copy);
        uint32_t getSquare();
        std::string getSizes();
        std::string getImg();
        std::string getType() const;
        void setSizes(uint32_t sizes[], uint32_t len);
        bool save(std::ofstream& file);// сохранение в файл
        int load(std::ifstream& file);// загрузка из файла
        uint32_t getHeight();
        uint32_t getWidth();
        const std::string type = "quadrate";
    private:
        uint32_t height = 0;
        uint32_t width = 0;

};

#include "quadrate.cpp"
#endif