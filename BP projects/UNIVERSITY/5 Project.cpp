#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> nameOfTotalPlayers = {"X", "Y"};
    string nameOfPlayerStarted;
    cin >> nameOfPlayerStarted;
    int startingNumber;
    cin >> startingNumber;
    if (startingNumber == 1) {
        cout << startingNumber << endl;
    }
    int numberOfRounds = 0;
    int index = 0;
    while (startingNumber != 1) {
        if (index == 0) {
            cout << startingNumber << " ";
            index += 1;
        }
        if (startingNumber % 2 == 0) {
            startingNumber = startingNumber / 2;
            if (startingNumber != 1) {
                cout << startingNumber << " ";
            } else {
                cout << startingNumber << endl;
            }
            numberOfRounds += 1;
        } else {
            startingNumber = startingNumber * 3 + 1;
            if (startingNumber != 1) {
                cout << startingNumber << " ";
            } else {
                cout << startingNumber << endl;
            }
            numberOfRounds += 1;
        }
    }
    cout << nameOfTotalPlayers[0] << endl;
    return 0;
}

