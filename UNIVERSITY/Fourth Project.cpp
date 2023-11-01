#include<iostream>
using namespace std;
int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x2 || x1 == x3 || x2 == x3) {
        cout << "Vertical!" << endl;
    } else if (y1 == y2 || y1 == y3 || y2 == y3) {
        cout << "Horizontal, I can finally cogitate!" << endl;
    } else {
        cout << "Not this time then!" << endl;
    }

    return 0;
}




