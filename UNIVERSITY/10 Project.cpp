#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long int startingNumber;
    long long int finishingNumber;
    long long int base;
    cin >> startingNumber;
    cin >> finishingNumber;
    cin >> base;

    vector<int> listOfNumbers;
    for (long long int number = startingNumber + 1; number < finishingNumber; number++) {
        listOfNumbers.push_back(number);
    }

    vector<int> sumOfTheDigitsOfNumbers;
    vector<int> listOfDigits;
    for (long int number : listOfNumbers) {
        long int sumOfDigits = 0;
        while (number != 1) {
            listOfDigits.push_back(number % base);
            number /= base;
        }
        for (long int digit : listOfDigits) {
            sumOfDigits += digit;
        }
        sumOfTheDigitsOfNumbers.push_back(sumOfDigits);
    }

    long long int maxIndex = 0;
    for (long int i = 1; i < sumOfTheDigitsOfNumbers.size(); i++) {
        if (sumOfTheDigitsOfNumbers[i] > sumOfTheDigitsOfNumbers[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << listOfNumbers[maxIndex] << endl;

    return 0;
}


