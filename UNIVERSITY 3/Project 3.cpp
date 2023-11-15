#include <iostream>
#include<sstream>
#include <string>
using namespace std;
void ReverseFiboNumbers(int number){
    stringstream ss;
    ss<<number;
    string StringOfNum;
    ss>>StringOfNum;
    int lenght=StringOfNum.length();
    for(int i=0;i<lenght/2;i++){
        swap(StringOfNum[i],StringOfNum[lenght-i-1]);
    }
    int IntOfNumber=stoi(StringOfNum);
    cout<<IntOfNumber<<" ";
}

void MakingPrimeNumbers(int numberOfRounds) {
    int firstNum = 0;
    int secondNum = 1;
    for (int i = 0; i < numberOfRounds; i++) {
        int thirdNum = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = thirdNum;
        ReverseFiboNumbers(thirdNum);
    }
}

int main() {
    int rounds;
    cin >> rounds;
    cout << 0 << " "<< 1 << " ";
    MakingPrimeNumbers(rounds - 2);
    return 0;
}


