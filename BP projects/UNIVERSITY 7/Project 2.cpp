#include<iostream>
using namespace std;
int main(){
    int *p1, *p2, *p3;
    int n;

    p1=&n;
    p2=&n;
    p3=&n;

    cin >> n;

    cout<<*p1<<" "<<*p1<<" "<<*p1<<" ";
    return 0;
}
