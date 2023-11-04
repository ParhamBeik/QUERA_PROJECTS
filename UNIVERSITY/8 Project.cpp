#include <iostream>
using namespace std;
int main() {
    long long int startingNumber;
    long long int finishingNumber;
    cin >> startingNumber;
    cin >> finishingNumber;
    long long int numberOfOddNumbers = 0;
    long long int numberOfEvenNumbers = 0;
    for (int number = startingNumber; number <= finishingNumber; number++) {
        if (number % 2 == 0) {
            numberOfEvenNumbers += 1;
        } else {
            numberOfOddNumbers += 1;
        }
    }
    long long int totalSum = 1;
    if ((startingNumber % 2 == 0 && finishingNumber % 2 != 0) || (startingNumber % 2 != 0 && finishingNumber % 2 == 0)) {
        cout << 0 ;
    } else if (startingNumber % 2 == 0 && finishingNumber % 2 == 0) {
        for (long long int index = 0; index < numberOfOddNumbers; index++) {
            totalSum *= 2;
        }
    } else if (startingNumber % 2 != 0 && finishingNumber % 2 != 0) {
        for (long long int index = 0; index < numberOfEvenNumbers; index++) {
            totalSum *= 2;
        }
    }
    if (totalSum != 1) {
        cout << totalSum ;
    }
    return 0;
}

