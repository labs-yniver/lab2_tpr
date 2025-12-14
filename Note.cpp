#include "Note.hpp"

Note::Note()
{
    set_fname("pass");
    set_phone("pass");
    set_date(0,0,0);
}

Note::Note(std::string fname, std::string phone, int day, int month, int year)
{

    set_fname(fname);
    set_phone(phone);
    set_date(day,month,year);

}

Note::Note(const Note & copy)
{

    set_fname(copy.get_fname());
    set_phone(copy.get_phone());
    set_date(copy.get_date(0),copy.get_date(1),copy.get_date(2));
}

void Note::set_fname(std::string val)
{
    fname = val;
}

void Note::set_phone(std::string val)
{
    phone = val;
}

void Note::set_date(int day, int month, int year)
{
    if(day>0 && day<=31){
        date[0] = day;
    }else{
        throw "Date is not in range days";
    }
    if(month>0 && month<=12){
        date[1] = month;
    }else{
        throw "month is not in range months";
    }
    
    if(year>0 && year<=2025){
        date[2] = year;
    }else{
        throw "year is not in range years";
    }
}

std::string Note::get_fname() const
{
return fname;
}

std::string Note::get_phone() const
{
return phone;
}

std::string Note::get_date_string() const
{
    std::string res;
    res += std::to_string(date[0]) + std::string(".");
    res += std::to_string(date[1]) + std::string(".");
    res += std::to_string(date[2]);
return res;
}

int Note::get_date(int index) const
{
    if(index>=0 && index<3){
        return date[index];
    }else{
        throw "Date is not in range days";
    }
}


void Note::show() const
{ 
    std::cout << to_string();
}

std::string Note::to_string() const
{
    
    std::string res;
    res += std::string("fname = ") + fname + std::string(";\n");
    res += std::string("phone = ") + phone + std::string(";\n");
    res += std::string("date = ") + get_date_string() + std::string(";\n");
    return res;
}
