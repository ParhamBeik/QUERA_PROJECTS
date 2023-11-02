#include <iostream>
#include <vector>
using namespace std;
int main() {
    int startingNumber;
    int finishingNumber;
    int base;
    cin >> startingNumber;
    cin >> finishingNumber;
    cin >> base;

    vector<int> listOfNumbers;
    for (int number = startingNumber + 1; number < finishingNumber; number++) {
        listOfNumbers.push_back(number);
    }

    vector<int> sumOfTheDigitsOfNumbers;
    vector<int> listOfDigits;
    
    for (int number = startingNumber + 1; number < finishingNumber; number++) {
        int sumOfDigits = 0;
        while (number != 0) {
            listOfDigits.push_back(number % base);
            number = number / base;
        }
        for (int digit : listOfDigits) {
            sumOfDigits += digit;
        }
        sumOfTheDigitsOfNumbers.push_back(sumOfDigits);
        listOfDigits.clear();
    }

    int maxIndex = 0;
    for (int i = 1; i < sumOfTheDigitsOfNumbers.size(); i++) {
        if (sumOfTheDigitsOfNumbers[i] > sumOfTheDigitsOfNumbers[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << listOfNumbers[maxIndex];

    return 0;
}

