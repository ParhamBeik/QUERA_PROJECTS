#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int round;
    cin>>round;
    string str[round];
    int list[round];
    
    for(int i=0;i<round;i++){
        string var,res="";
        cin>>var;
        for(int j=var.size()-1;j>-1;j--){
            if(j== var.size()-1 && var[j]==48){
                continue;
            }
            else{
                res+=var[j];
            }
        }
        str[i]=res;
    }

    for(int i=0;i<round;i++){
        stringstream ss;
        ss << str[i];
        int number;
        ss >> number;
        list[i]=number;
    }

	

    return 0;
}
