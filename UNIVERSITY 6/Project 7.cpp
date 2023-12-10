#include<iostream>
#include<string>
using namespace std;
int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        string str;
        cin>>str;
        int index=-1;
        string newStr="";
        for(int j=str.size()-1;j>-1;j--){
            if(index%3!=2){
                newStr+=str[j];
            }
            else{
                newStr+=46;
                newStr+=str[j];
            }
            index++;
        }
        string res="";
        for(int i=newStr.size()-1;i>-1;i--){
            res+=newStr[i];
        }
        cout<<res<<endl;
    }


    
    return 0;
}
