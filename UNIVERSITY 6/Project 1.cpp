#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    cin >> str1 >> str2;
    int i=0;
    bool isSame=true;
    while(isSame){
        if( (str2[i]==str1[i]-32 || str1[i]==str2[i]-32 || str1[i]==str2[i]) && i<str1.size()){
            continue;
        }
        else if(i==str1.size()-1){
            break;
        }
        else{
            isSame=false;
            break;
        }
        i++;
    }
    if(isSame){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}