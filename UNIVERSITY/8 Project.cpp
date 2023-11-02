#include <iostream>
using namespace std;
int main() {
    int startingNumber;
    int finishingNumber;
    cin >> startingNumber;
    cin >> finishingNumber;

    if (startingNumber % 2 == 0 && finishingNumber % 2 == 0) {
        int totalSum = 1;
        for (int i = 0; i < (finishingNumber - startingNumber) / 2; i++) {
            totalSum *= 2;
        }
        cout << totalSum << endl;
    }
    else if ((startingNumber % 2 == 0 && finishingNumber % 2 == 1) || (startingNumber % 2 == 1 && finishingNumber % 2 == 0)) {
        cout << 0 << endl;
    }
    return 0;
}

