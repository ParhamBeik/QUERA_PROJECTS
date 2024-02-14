#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    cin >> num;
    int copyNum=num , sum=1;
    while(copyNum > 1){
        for(int i=2;i <= sqrt(num);i++){
           while(copyNum%i==0){
            copyNum/=i;
            sum+=copyNum;
           }
        }
    }
    if(sum==num){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;  
} 