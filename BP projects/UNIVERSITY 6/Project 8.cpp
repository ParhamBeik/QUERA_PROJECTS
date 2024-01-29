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
        //adding F to vector
        if(str[i]=='F'){
            list.push_back(str[i]);
        }
        //adding I to vector
        else if(str[i]=='I'){
            list.push_back(str[i]);
        }
        //pairing W to F and erasing F from vector
        else if(str[i]=='W'){
            if(list[list.size()-1]!='F'){
                isValid=false;
                break;
            }
            list.pop_back();
        }
        //pairing E to I and erasing E from vector
        else if(str[i]=='E'){
            if(list[list.size()-1]!='I'){
                isValid=false;
                break;
            }
            list.pop_back();
        }
        if(list.size()==0){
            break;
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
