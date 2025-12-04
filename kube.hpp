#ifndef __Kube__
#define __Kube__

#include "object_d3.hpp"

class Kube: public Object_d3{
    public:
        ~Kube();
        Kube();
        Kube(const Figure &copy);
        uint32_t getSquare();
        uint32_t getVolume();
        std::string getSizes();
        std::string getImg();
        std::string getType() const;
        void setSizes(uint32_t sizes[], uint32_t len);
        bool save(std::ofstream& file);// сохранение в файл
        int load(std::ifstream& file);// загрузка из файла
        uint32_t getHeight();
        uint32_t getWidth();
        uint32_t getLong();
        const std::string type = "kube";
    private:
        uint32_t height = 0;
        uint32_t width = 0;
        uint32_t long_ = 0;

};

#include "Kube.cpp"
#endif