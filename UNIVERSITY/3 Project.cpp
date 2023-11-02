#include <iostream>
using namespace std;
int main() {
    int firstItem, secondItem;
    cin >> firstItem;
    cin >> secondItem;

    if (firstItem <= 100000) {
        firstItem = firstItem * 0.95;
    } else if (100000 < firstItem && firstItem <= 300000) {
        firstItem = firstItem * 0.9;
    } else if (300000 < firstItem) {
        firstItem = firstItem * 0.85;
    }

    if (secondItem <= 100000) {
        secondItem = secondItem * 0.95;
    } else if (100000 < secondItem && secondItem <= 300000) {
        secondItem = secondItem * 0.9;
    } else if (300000 < secondItem) {
        secondItem = secondItem * 0.85;
    }

    cout << int(firstItem + secondItem);

    return 0;
}


