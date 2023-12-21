#include<iostream>
using namespace std;
int main(){
    int round;
    cin>>round;
	int* listOfNums;
	listOfNums = new int[round];
	
    for(int i=0;i<round;i++){
        int num;
        cin>>num;
        (listOfNums)[i]=num;
    }

    for(int i=0;i<round;i++){
        cout<<(listOfNums)[i]<<" ";
    }
    
    delete listOfNums;
    return 0;
}
