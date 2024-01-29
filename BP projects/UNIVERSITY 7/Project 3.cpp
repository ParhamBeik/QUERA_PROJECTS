#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int round;
    cin>>round;

    int* listOfNums = (int*) malloc(sizeof(int)*round);

    for(int i=0;i<round;i++){
        cin>>*(listOfNums+i);
    }
    
    for(int i=0;i<round;i++){
        cout<<*(listOfNums+i)<<" ";
    }
    delete listOfNums;
    return 0;
}
