#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string str;
    cin>>str;
    string table="",res="";
    for(int i=0;i<str.size();i++){
        if(str[i]!=45 && str[i+1]!=49){
            table+=str[i];
        }
    }

    for(int i=str.size()-1;i>-1;i--){
        res+=table[i];
    }

    cout<<res;
    return 0;
}
