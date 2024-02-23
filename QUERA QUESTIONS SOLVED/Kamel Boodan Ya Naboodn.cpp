#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num;
    cin >> num;
    int i=1 , sum=0 , r;
    while(i < num){
        r = num%i;
        if(r==0){
            sum += i;
        }
        i++;
    }
    if(sum==num){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;  
} 