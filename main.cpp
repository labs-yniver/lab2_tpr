#include <iostream>
#include "Keeper.hpp"
#include "Note.hpp"

using namespace std;

bool g_old_element = false;

Note* getNote(Keeper **keeper);
void workWithNote(Note **fig, Keeper **keeper);

int main(){
    // Note *n;
    Keeper *keeper = new Keeper;
    // n = new Note("bcd","123",1,1,1);
    // keeper->add(n);
    // n = new Note("cd","123",1,2,1);
    // keeper->add(n);
    // n = new Note("abcd","123",1,2,1);
    // keeper->add(n);

    // // keeper->showAll();
    // cout<<endl<<keeper->get_string_month(2)<<endl;
    // cout<<endl<<endl;
    // keeper->sort();
    // // keeper->showAll();
    // cout<<endl<<keeper->get_string_month(2)<<endl;
    while(1){
        Note *fig = getNote(&keeper);
        if(fig == nullptr){
            continue;
        }
        if(g_old_element == false){
            keeper->add(fig);
        }
        g_old_element = false;
        workWithNote(&fig,&keeper);

    }
    return 0;
}

void workWithNote(Note **fig, Keeper **keeper){
    int comand = 0;
    while(1){
        cout<<"Choose:\n0. Exit\n1. Show data\n2. Set name;\n3. Set phone\n4. Set date\n";
        cin>>comand;
        if(comand == 0){
            break;
        }else if(comand==1){
            (*fig)->show();
        }else if(comand == 2){
            string name;
            cout<<string("Print new family and name ");
            cin>>name;
            (*fig)->set_fname(name);
        }else if(comand == 3){
            string phone;
            cout<<string("Print new phone ");
            cin>>phone;
            (*fig)->set_phone(phone);
        }else if(comand == 4){
            int day, month, year;
            cout<<string("Print new day month year ");
            cin>>day;
            cin>>month;
            cin>>year;
            (*fig)->set_date(day, month, year);
        }else{
            cout<<"Not correct input\n";
            continue;  
        }

    }
}



Note* getNote(Keeper **keeper){
    Note *fig = nullptr;
    int comand = 0;
    cout<<"Choose:\n1. Get element from Keeper;\n2. Get new element\n";
    cout<<"3. Clear Keeper\n4.Sort \n5.Print Note by month \n6. Show all \n";
    cout<<"7. Delete item";
        cin>>comand;
        if(comand==1){
            if((*keeper)->len()==0){
                cout<<"Can't get element from Keeper, len = 0\n";
                return nullptr;   
            }else{
                cout<<string("Choose num of element from 0 to ")+to_string((*keeper)->len()-1)+string("\n");
                cin>>comand;
                if(comand<0 || comand>((*keeper)->len()-1)){
                    cout<<"Not correct input\n";
                    return nullptr;  
                }
                fig = (*keeper)->at(comand)->getData();
                g_old_element = true;
            }
        }else if(comand == 2){
            cout<<"Choose:\n1. Create new;\n2. Copy from keeper\n";
            cin>>comand;
            if(comand==1){
            cout<<"NEW1\n";
                fig = new Note();
                //fig = new Note("","",1,1,1);
            cout<<"NEW2\n";
            }else if(comand == 2){
                if((*keeper)->len()==0){
                    cout<<"Can't get element from Keeper, len = 0\n";
                    return nullptr;;   
                }else{
                    cout<<string("Choose num of element from 0 to ")+to_string((*keeper)->len()-1)+string("\n");
                    cin>>comand;
                    if(comand<0 || comand>((*keeper)->len()-1)){
                        cout<<"Not correct input\n";
                        return nullptr;  
                    }
                    Note *copy= (*keeper)->at(comand)->getData();
                    fig = new Note(*copy);
                }
            }else{
                cout<<"Not correct input\n";
                return nullptr; 
            }

            cout<<"NEW3\n";
        }else if(comand == 3){
            delete (*keeper);
            (*keeper) = new Keeper;
        }else if(comand == 4){
            (*keeper)->sort();
        }else if(comand == 5){
            cout<<"Choose month(number):\n";
            cin>>comand;
            if(comand>0 && comand <13){
                (*keeper)->get_string_month(comand);
            }else 
            {
                cout<<"Not correct input\n";
                return nullptr; 
            }
        }else if(comand == 6){
            (*keeper)->showAll();
            return nullptr;; 
        }else if(comand == 7){
            if((*keeper)->len()==0){
                cout<<"Can't get element from Keeper, len = 0\n";
                return nullptr;
            }
            cout<<string("Choose num of element from 0 to ")+to_string((*keeper)->len()-1)+string("\n");
            cin>>comand;
            if(comand<0 || comand>((*keeper)->len()-1)){
                cout<<"Not correct input\n";
                return nullptr;  
            }
            (*keeper)->remove(comand);
            return nullptr;
        }else{
            cout<<"Not correct input\n";
            return nullptr;
        }
        return fig;
}
