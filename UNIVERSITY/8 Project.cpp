#include <iostream>
using namespace std;
int main() {
    int startingNumber;
    int finishingNumber;
    cin >> startingNumber;
    cin >> finishingNumber;
    int numberOfOddNumbers = 0;
    int numberOfEvenNumbers = 0;
    for (int number = startingNumber; number <= finishingNumber; number++) {
        if (number % 2 == 0) {
            numberOfEvenNumbers += 1;
        } else {
            numberOfOddNumbers += 1;
        }
    }
    int totalSum = 1;
    if ((startingNumber % 2 == 0 && finishingNumber % 2 == 1) || (startingNumber % 2 == 1 && finishingNumber % 2 == 0)) {
        cout << 0 ;
    } else if (startingNumber % 2 == 0 && finishingNumber % 2 == 0) {
        for (int index = 0; index < numberOfOddNumbers; index++) {
            totalSum *= 2;
        }
    } else if (startingNumber % 2 == 1 && finishingNumber % 2 == 1) {
        for (int index = 0; index < numberOfEvenNumbers; index++) {
            totalSum *= 2;
        }
    }
    if (totalSum != 1) {
        cout << totalSum ;
    }
    return 0;
}

