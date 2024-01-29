#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    string name="";
    int size=str.size() ,index=0;
    for(int i=0;i<size;i++){
        bool isM=false;
        for(int a=0;a<name.size();a++){
            if(name[a]==109){
                isM=true;
            }
        }
        if(str[i]==109 && !(isM) && index==0){
            name+=str[i];
            index++;
        }

        bool isA=false;
        for(int a=0;a<name.size();a++){
            if(name[a]==97){
                isA=true;
            }
        }
        if(str[i]==97 && !(isA) && index==1){
            name+=str[i];
            index++;
        }

        bool isN=false;
        for(int a=0;a<name.size();a++){
            if(name[a]==110){
                isN=true;
            }
        }
        if(str[i]==110 && !(isN) && index==2){
            name+=str[i];
            index++;
        }

        bool isG=false;
        for(int a=0;a<name.size();a++){
            if(name[a]==103){
                isG=true;
            }
        }
        if(str[i]==103 && !(isG) && index==3){
            name+=str[i];
            index++;
        }

        bool isO=false;
        for(int a=0;a<name.size();a++){
            if(name[a]==111){
                isO=true;
            }
        }
        if(str[i]==111 && !(isO) && index==4){
            name+=str[i];
            index++;
        }
    }
    if(name=="mango"){
        cout<<"asal lamasab, asal";
    }
    else{
        cout<<"asal nist";
    }
    return 0;
}
