#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        int index=i;
        if(str[i]==70){
            bool isTrue=false;
            while(!(isTrue) && index<str.size()){
                if(str[index+1]==70){
                    isTrue=true;
                }
                index++;
            }
            if(isTrue==true){
                break;
            }
        }
        else if(str[i]==73){
            bool isTrue=true;
            while(isTrue && index<str.size()){
                if(str[index+1]==73){
                    isTrue=false;
                }
                index++;
            }
            if(isTrue==false){
                break;
            }
        }
    }



    
    return 0;
}