#include <iostream>
#include <string>
using namespace std;

void ReverseFiboNumbers(string number){

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


