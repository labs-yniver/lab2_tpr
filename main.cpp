#include <iostream>
#include "Kube.hpp"
#include "quadrate.hpp"
#include "Keeper.hpp"
#include "Keeper.hpp"

using namespace std;
void load_save(Kube &Kube);
Figure* getFigure(Keeper **keeper);
void workWithFigure(Figure **fig, Keeper **keeper);

int main(){
    Keeper *keeper = new Keeper;
    while(1){
        Figure *fig = getFigure(&keeper);
        if(fig == nullptr){
            continue;
        }
        keeper->add(fig);
        workWithFigure(&fig,&keeper);

    }
    return 0;
}

void workWithFigure(Figure **fig, Keeper **keeper){
    int comand = 0;
    while(1){
        cout<<"Choose:\n0. Exit\n1. Show data\n2. Set name;\n3. Set sizes\n";
        cin>>comand;
        if(comand == 0){
            break;
        }else if(comand==1){
            (*fig)->show();
        }else if(comand == 2){
            string name;
            cout<<string("Print new name ");
            cin>>name;
            (*fig)->setName(name);
        }else if(comand == 3){
            uint32_t sizes[3];
            int len = 2;
            if((*fig)->getType() == "kube"){
                len = 3;
            }
            cout<<string("Print ")+to_string(len)+string(" sizes: ");
            for(int i = 0;i<len;++i){
                cin>>sizes[i];
            }
            (*fig)->setSizes(sizes,len);
        }else{
            cout<<"Not correct input\n";
            continue;  
        }

    }
}



Figure* getFigure(Keeper **keeper){
    Figure *fig = nullptr;
    int comand = 0;
    cout<<"Choose:\n1. Get element from Keeper;\n2. Get new element\n";
    cout<<"3. Clear Keeper\n4. Save to file\n5. Load from file\n6. Show all \n";
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
            }
        }else if(comand == 2){
            cout<<"Choose:\n1. Create new;\n2. Copy from keeper\n";
            cin>>comand;
            if(comand==1){
                cout<<"Choose:\n1. Create quadrate;\n2. Create kube\n";
                cin>>comand;
                if(comand==1){
                    fig = new Quadrate;
                }else if(comand == 2){
                    fig = new Kube;
                }else{
                    cout<<"Not correct input\n";
                    return nullptr;;  
                }
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
                    Figure *copy;
                    copy = (*keeper)->at(comand)->getData();
                    if(copy->getType() == "kube"){
                        try{
                            fig = new Kube(*copy);
                        }catch(string str){
                            cout<<str;
                            return nullptr;
                        }
                    }else if(copy->getType() == "quadrate"){
                        try{
                        fig = new Quadrate(*copy);
                        }catch(string str){
                            cout<<str;
                            return nullptr;
                        }
                    }else{
                        cout<<"Error type\n";
                        return 0;
                    }
                }
            }else{
                cout<<"Not correct input\n";
                return nullptr; 
            }

        }else if(comand == 3){
            delete (*keeper);
            (*keeper) = new Keeper;
        }else if(comand == 4){
            string path;
            cout<<string("Choose file path ");
            cin>>path;
            if((*keeper)->len()==0){
                cout<<"Nothing for Save\n";
                return nullptr; 
            }
            try{
                (*keeper)->save_to_file(path);
            }catch(string str){
                cout<<str;
                return nullptr;;
            }
        }else if(comand == 5){
            string path;
            cout<<string("Choose file path ");
            cin>>path;
            try{
                if((*keeper)->load_from_file(path) == 0){
                  cout<<"Error read Keeper from file";  
                }
            }catch(string str){
                cout<<str;
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
