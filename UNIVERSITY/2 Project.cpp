#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int maxNumber = number;
    int minNumber = number;
    while (number != -1) {
        int newNumber;
        cin >> newNumber;
        number = newNumber;
        if (newNumber > maxNumber && newNumber != -1) {
            maxNumber = newNumber;
        }
        else if (newNumber < minNumber && newNumber != -1) {
            minNumber = newNumber;
        }
    }
    cout << maxNumber - minNumber << endl;
    return 0;
}