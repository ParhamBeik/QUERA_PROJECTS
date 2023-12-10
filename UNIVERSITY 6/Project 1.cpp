#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    cin >> str1 >> str2;
    int size=str1.size();
    
    if(size==str2.size()){
        bool isSame=true;
        for(int i=0;i<size;i++){
            if(str2[i]==str1[i]-32 || str1[i]==str2[i]-32){
                continue;
            }
            else{
                isSame=false;
            }
        }
        if(isSame){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}
