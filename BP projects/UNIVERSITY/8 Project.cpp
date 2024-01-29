#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long int startingNumber,finishingNumber;
    cin >> startingNumber ;
    cin >> finishingNumber ;
    long long int totalSum=2;
    long long int lengthOfNumbers = (finishingNumber - startingNumber);
    long long int exponential=lengthOfNumbers/2;
    if (lengthOfNumbers % 2 == 0) {
        totalSum = pow(totalSum, exponential);
        cout << totalSum ;
    } 
	else{
        cout << 0 ;
    }
    return 0;
}


