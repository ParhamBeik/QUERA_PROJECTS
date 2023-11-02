#include <iostream>
#include <vector>
using namespace std;
int main() {
    int firstNumber;
    int secondNumber;
    cin >> firstNumber;
    cin >> secondNumber;
    
    vector<int> listOfFirstOddNumbers;
    vector<int> listOfSecondOddNumbers;
    int variable = 10;
    
    while (variable <= firstNumber * 10) {
        listOfFirstOddNumbers.push_back(firstNumber % variable - firstNumber % (variable / 10));
        listOfSecondOddNumbers.push_back(secondNumber % variable - secondNumber % (variable / 10));
        variable *= 10;
    }
    
    int emptyBucket = 0;
    
    for (int index = 0; index < listOfFirstOddNumbers.size(); index += 2) {
        emptyBucket = listOfFirstOddNumbers[index];
        listOfFirstOddNumbers[index] = listOfSecondOddNumbers[index];
        listOfSecondOddNumbers[index] = emptyBucket;
        emptyBucket = 0;
    }
    
    int firstSum = 0;
    int secondSum = 0;
    
    for (int number : listOfFirstOddNumbers) {
        firstSum += number;
    }
    
    for (int number : listOfSecondOddNumbers) {
        secondSum += number;
    }
    
    cout << firstSum << endl;
    cout << secondSum << endl;
    
    return 0;
}

