#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int round;
    cin>>round;
    string str[round] , test="",res="*";
    for(int i=0;i<round;i++){
        cin>>str[i];
    }
    for(int i=0;i<round;i++){
        for(int j=0;j<str[i].size();j++){
            test+=str[j];
        }
    }
    sort(test.begin(), test.end());
    int num=97;
    for(int i=0;i<test.size();){
        int count=0;
        while(test[i]==num){
            count++;
            i++;
            if(count==round){
                res+=num;
                num++;
                break;
            }
        }
        i++;
    }
    cout<<res;
    return 0;
}
