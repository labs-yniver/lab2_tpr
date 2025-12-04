#include "Keeper.hpp"

inline bool Keeper::save_to_file(std::string file_name)
{
    std::ofstream out_f(file_name, std::ios::out | std::ios::binary);
    if (!out_f.is_open())
    {
        throw std::string("Error write to file");
    }
    for(int i =0;i<this->len();++i){
        this->at(i)->getData()->save(out_f);
    }
    out_f.close();



return false;
}

inline bool Keeper::load_from_file(std::string file_name)
{
    std::ifstream in_f(file_name, std::ios::in | std::ios::binary);
     if (!in_f.is_open())
    {
        throw std::string("Error read file");
    }
        
    std::string str;
    while(!in_f.eof()){
        Figure *fig = nullptr;
        int res_load = 0;
        for(int i = 0;i<2;++i){
            res_load = 0;
            if(i==0){
                fig = new Quadrate;
            }else if(i==1){
                fig = new Kube;
            }else{
                return 0 ;
            }
            res_load  = fig->load(in_f);
            if(res_load == 1){
                this->add(fig);
                break;
            }else if(res_load == -1){
                in_f.close();
                return true;
            }else if(res_load == 0){
                delete fig;
                fig = nullptr;
            }else{
                return 0;
            }
        }
    }
    in_f.close();
return true;
}

void Keeper::showAll()
{
    if(this->len()==0){
        std::cout<<"Pass Keeper";
    }
    for(int i =0;i<this->len();++i){
        this->at(i)->getData()->show();
    }
}
