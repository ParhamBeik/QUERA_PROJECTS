#include<iostream>
#include<vector>
using namespace std;
int main(){
    int numberOfInputs;
    cin>>numberOfInputs;
    vector<int> listOfNumbers;
    for(int number=0;number<numberOfInputs;number++){
        int eachNumberInputed;
        cin>>eachNumberInputed;
        listOfNumbers.push_back(eachNumberInputed);
    }
    for(int number=0;number<numberOfInputs;number++){
        if(listOfNumbers[number]==0){
            cout<<"Zero"<<endl;
        }
        else if(listOfNumbers[number]>0 && listOfNumbers[number]%2==0){
            cout<<"Positive Even"<<endl;
        }
        else if(listOfNumbers[number]>0 && listOfNumbers[number]%2==1){
            cout<<"Positive Odd"<<endl;
        }
        else if(listOfNumbers[number]<0 && listOfNumbers[number]%2==0){
            cout<<"Negative Even"<<endl;
        }
        else if(listOfNumbers[number]<0 && listOfNumbers[number]%2!=0){
            cout<<"Negative Odd"<<endl;
        }
    }


    return 0;
}
