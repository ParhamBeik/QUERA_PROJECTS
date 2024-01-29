#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
    int round;
    cin>>round;
    
    cin.ignore();
    
    vector<int> list;

    bool isValid[round];
    for(int i=0;i<round;i++){
        isValid[i]=false;
    }
    
    for(int i=0;i<round;i++){
        for(int j=0;j<3;j++){
            string str;
            getline(cin >> ws, str);
            string first="",second="";
            bool isTrue=false;
            for(int z=0;z<str.size();z++){
                if(str[z]==45){
                    isTrue=true;
                }
                else if(str[z]>47 && str[z]<58 && isTrue){
                    second+=str[z];
                }
                else if(str[z]>47 && str[z]<58 && !(isTrue)){
                    first+=str[z];
                }
            }
            int firstNum,secondNum;
            stringstream aa;
            aa << first;
            aa >> firstNum;
            stringstream bb;
            bb << second;
            bb >> secondNum;
            for(int i=firstNum;i<=secondNum;i++){
                list.push_back(i);
            }
        }
        sort(list.begin(),list.end());
        bool isTrue=true;
        for(int k=15;k<=24;k++){
            int a=0;
            for(int w=0;w<list.size();w++){
                if(list[w]==k){
                    a++;
                    break;
                }
            }
            if(a==0){
                isTrue=false;
                break;
            }
        }
        if(!(isTrue)){
            isValid[i]=true;
        }
        list.clear();
    }
    
    for(int i=0;i<round;i++){
        if(isValid[i]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
