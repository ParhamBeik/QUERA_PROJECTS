#include<iostream>
using namespace std;
int main() {
    int number;
    cin >> number;
    int numberMinusOne = number - 1;
    int firstSum = 1;
    int secondSum = 1;
    
    if (number % 2 == 0) {
        for (int variable = 2; variable <= number; variable += 2) {
            firstSum *= variable;
        }
        for (int variable = 1; variable <= numberMinusOne; variable += 2) {
            secondSum *= variable;
        }
    } else {
        for (int variable = 1; variable <= number; variable += 2) {
            firstSum *= variable;
        }
        for (int variable = 2; variable <= numberMinusOne; variable += 2) {
            secondSum *= variable;
        }
    }
    
    cout << firstSum - secondSum << endl;
    
    return 0;
}

