#include<iostream>
#include<string>
using namespace std;

void encode(string str){
    for(int i=0;i<str.size();i++){
        str[i]=str[i]+5;
    }
    cout<<str;
}
void decode(string str){    
    for(int i=0;i<str.size();i++){
        str[i]=str[i]-5;
    }
    cout<<str;
}
int main(){
    string func , text;
    cin >> func;
    getline(cin >> ws, text);

    if(func=="encode"){
        encode(text);
    }
    else{
        decode(text);
    }

    return 0;
}
