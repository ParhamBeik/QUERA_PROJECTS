#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int startingNumber,finishingNumber;

    cin >> startingNumber;
    cin >> finishingNumber;

    int exponantial=(finishingNumber-startingNumber)/2;

    long long int totalSum = 1;
    if(startingNumber!=finishingNumber){
        if ((startingNumber % 2 == 0 && finishingNumber % 2 != 0) || (startingNumber % 2 != 0 && finishingNumber % 2 == 0)) {
            cout << 0 ;
        } else if (startingNumber % 2 == 0 && finishingNumber % 2 == 0) {
            totalSum=pow(2,exponantial);
        } else if (startingNumber % 2 != 0 && finishingNumber % 2 != 0) {
            totalSum=pow(2,exponantial);
        }
        if (totalSum != 1) {
            cout << totalSum ;
        }
    }
    else{
        cout<<1;
    }
    return 0;
}

