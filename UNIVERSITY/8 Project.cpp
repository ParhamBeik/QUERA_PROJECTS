#include <iostream>
using namespace std;
int main() {
    long long int startingNumber;
    long long int finishingNumber;
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
        for (long int i = 0; i < numberOfEven; i++) {
            totalSumEven *= 2;
        }
        for (long int i = 0; i < numberOfOdd; i++) {
            totalSumOdd *= 2;
        }
        cout << totalSumEven - totalSumOdd << endl;
    } else if (startingNumber % 2 == 1 && finishingNumber % 2 == 1) {
        for (long int i = 0; i < numberOfEven; i++) {
            totalSumEven *= 2;
        }
        for (int i = 0; i < numberOfOdd; i++) {
            totalSumOdd *= 2;
        }
        cout << totalSumOdd - totalSumEven << endl;
    } else if ((startingNumber % 2 == 0 && finishingNumber % 2 == 1 && startingNumber != 0) || (startingNumber % 2 == 1 && finishingNumber % 2 == 0 && startingNumber != 0)) {
        cout << 0 << endl;
    } else if ((finishingNumber % 2 == 1 && startingNumber == 0) || (finishingNumber % 2 == 0 && startingNumber == 0)) {
        cout << 0 << endl;
    }
    return 0;
}


