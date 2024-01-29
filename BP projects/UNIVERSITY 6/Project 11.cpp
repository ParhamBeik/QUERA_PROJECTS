#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int round;
    cin>>round;
    string answer="";
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<round;i++){
        string str,res="";
        cin>>str;
        int count=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!=48){
                count++;
            }
        }
        int min=49;
        for(int i=0;i<count;i++){
            int index=0;
            while(str[index]!=min){
                index++;
            }
            min++;
            res+=alphabet[index];
        }
        res+=" ";
        answer+=res;
    }
    cout<<answer;
    return 0;
}
