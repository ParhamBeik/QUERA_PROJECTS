#include <iostream>
using namespace std;
int main() {
    int number;
    cin >> number;
    int totalSum = 1;
    if (number > 4) {
        cout << 0 << endl;
    } else if (1 < number && number <= 4) {
        while(number!=1){  
            totalSum *= number;
            number -= 1;
        }
        cout << totalSum % 10 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}


