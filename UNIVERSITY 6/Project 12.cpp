#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int round;
    cin>>round;
    vector<string> listOfName;
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        listOfName.push_back(str);
    }
    string res="";
    for(int i=0;i<round;i++){
        string str=listOfName[0][0];
        for(j:listOfName[i+1]){
            if(j==str){
                str+=j;
            }
        }
    }
    return 0;
}
