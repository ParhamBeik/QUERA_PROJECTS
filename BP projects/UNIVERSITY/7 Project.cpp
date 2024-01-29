#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> listOfNumbers;
    int number;
    cin >> number;
    listOfNumbers.push_back(number);
    int newNumber = number;
    while (newNumber != -1) {
        cin >> newNumber;
        if (newNumber != -1) {
            listOfNumbers.push_back(newNumber);
        }
    }
    long long int totalSum = 0;
    for (int number : listOfNumbers) {
        totalSum += number;
    }
    cout << totalSum << endl;
    return 0;
}

