#include<iostream>
#include<string>
using namespace std;
int main(){
    string table="",res="",str="";
    do{
        str.clear();
        cin>>str;
        for(int i=0;i<str.size();i++){
            if(str[i]!=45 && str[i+1]!=49){
                table+=str[i];
            }
        }

        for(int i=str.size()-1;i>-1;i--){
            res+=table[i];
        }
        table+="\n";
        res+="\n";

    }while(str.size()>2);

    cout<<res;
    return 0;
}
