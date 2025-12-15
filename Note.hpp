#ifndef __ClassNote__
#define __ClassNote__
#include <stdio.h>
#include <iostream>


class Note{
    public:
        Note();
        Note(std::string fname, std::string phone, int day, int month, int year);
        Note(const Note &copy);

        void set_fname(std::string val);
        void set_phone(std::string val);
        void set_date(int day, int month, int year);

        std::string get_fname() const;
        std::string get_phone() const;
        std::string get_date_string() const;
        int get_date(int index) const;

        void show() const;
        std::string to_string() const;

        int get_index_for_sort_fname(int index = 0);
    private:
        std::string fname = "";
        std::string phone = "";
        int date[3];
};
#include "Note.cpp"
#endif // __ClassList__

