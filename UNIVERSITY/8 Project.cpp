#include <iostream>
using namespace std;
int main() {
    long int startingNumber;
    long int finishingNumber;
    cin >> startingNumber;
    cin >> finishingNumber;
    long long int numberOfEven = 0;
    long long int numberOfOdd = 0;
    for (int number = startingNumber; number <= finishingNumber; number++) {
        if (number % 2 == 0) {
            numberOfEven += 1;
        } else {
            numberOfOdd += 1;
        }
    }
    long long int totalSumOdd = 1;
    long long int totalSumEven = 1;
    if (startingNumber % 2 == 0 && finishingNumber % 2 == 0) {
        for (int i = 0; i < numberOfEven; i++) {
            totalSumEven *= 2;
        }
        for (int i = 0; i < numberOfOdd; i++) {
            totalSumOdd *= 2;
        }
        cout << totalSumEven - totalSumOdd ;
    } else if (startingNumber % 2 == 1 && finishingNumber % 2 == 1) {
        for (int i = 0; i < numberOfEven; i++) {
            totalSumEven *= 2;
        }
        for (int i = 0; i < numberOfOdd; i++) {
            totalSumOdd *= 2;
        }
        cout << totalSumOdd - totalSumEven ;
    } else if ((startingNumber % 2 == 0 && finishingNumber % 2 == 1) || (startingNumber % 2 == 1 && finishingNumber % 2 == 0)) {
        cout << 0 ;
    }
    return 0;
}


