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

void Keeper::sort(bool reverse)
{
    int n = this->len();
    if (n < 2) return; // Сортировка не нужна, если элементов меньше 2

    for (int i = 0; i < n - 1; ++i) {
        // Флаг для оптимизации: если за проход не было замен, массив уже отсортирован
        bool swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            Note *n_current = this->at(j)->getData();
            Note *n_next = this->at(j + 1)->getData();

            bool condition;
            if (reverse) {
                // Для убывания: если текущий меньше следующего — меняем
                condition = n_current->get_index_for_sort_fname() < n_next->get_index_for_sort_fname();
            } else {
                // Для возрастания: если текущий больше следующего — меняем
                condition = n_current->get_index_for_sort_fname() > n_next->get_index_for_sort_fname();
            }

            if (condition) {
                // Меняем данные местами
                this->at(j)->setData(n_next);
                this->at(j + 1)->setData(n_current);
                swapped = true;
            }
        }

        // Если за весь цикл по j не было ни одной перестановки, выходим раньше
        if (!swapped) break;
    }
}


std::string Keeper::get_string_month(int month)
{
    std::string res;
    bool pass = true;
    for(int i = 0;i<this->len();++i){
        Note *n = this->at(i)->getData();
        if(n->get_date(1) == month){
           pass = false; 
           res+=n->to_string();
           res+=std::string("\n");
        }
    }
    if(pass){
        res = std::string("Not found Notes wuth month:") + std::to_string(month) + std::string("\n");
    }
    return res;
}
