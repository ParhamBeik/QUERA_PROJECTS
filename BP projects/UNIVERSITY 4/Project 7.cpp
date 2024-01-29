#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num,zeroCount=0,oneCount=0,size=0;
    string str;
    cin>>num>>str;
    size=str.size();
    for(int i=0;i<size;i++){
        if(str[i]==48){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }
    for(int i=pow(2,oneCount);i<=pow(2,num)-pow(2,zeroCount)+1;i++){
        cout<<i<<" ";
    }
    return 0;
}