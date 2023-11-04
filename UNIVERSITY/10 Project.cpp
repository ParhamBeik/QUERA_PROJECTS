#include <iostream>
using namespace std;
int main() {
    int startingNumber, finishingNumber, base;
    cin >> startingNumber >> finishingNumber >> base;
    
    int maxValue = 0;
    int numberWithMaxValue = 0;
    
    for (int number = startingNumber + 1; number < finishingNumber; number++) {
        int valueOfDigit = 0;
        int copyOfNumber = number;
        
        while (number != 0) {
            valueOfDigit += number % base;
            number = number / base;
        }
        
        if (valueOfDigit > maxValue) {
            maxValue = valueOfDigit;
            numberWithMaxValue = copyOfNumber;
        }
    }
    
    cout << numberWithMaxValue << endl;
    
    return 0;
}

