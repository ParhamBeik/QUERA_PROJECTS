#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
    string str;
    cin>>str;
    vector<char> list;
    int i=0;
    bool isValid=true;
    while(i!=str.size()-1){
        //F
        if(str[i]=='F'){
            list.push_back(str[i]);
        }
        //I
        else if(str[i]=='I'){
            list.push_back(str[i]);
        }
        //W
        else if(str[i]=='W'){
            if(list[list.size()-1]!='F'){
                isValid=false;
                break;
            }
            list.pop_back();
        }
        //E
        else if(str[i]=='E'){
            if(list[list.size()-1]!='I'){
                isValid=false;
                break;
            }
            list.pop_back();
        }
        
        i++;
    }

    if(isValid){
        cout<<"compile shod";
    }
    else{
        cout<<"syntax error";
    }

    return 0;
}
