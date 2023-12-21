#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
void resize (int*& dynamicArray, int& capacity, int newCapacity) {
	capacity = sqrt(capacity);
	capacity = pow(2,capacity);
    while(capacity < newCapacity){
        capacity = capacity * 2;
    }
    dynamicArray=new int[capacity];
}
void append (int*& dynamicArray, int& size, int& capacity, int value) {
    dynamicArray[size]=value;
}
int main(){
    int beginSize,add;
    cin >> beginSize >> add;

    int* dynamicArray;

    if(beginSize >= add){
    	dynamicArray=new int(sizeof(beginSize));
        for(int i=0;i<add;i++){
            int num;
            cin>>num;
            append(dynamicArray,i,beginSize,num);
        }
    }
    else if(beginSize < add){
        resize(dynamicArray,beginSize,add);
    	dynamicArray=new int(sizeof(beginSize));
        for(int i=0;i<add;i++){
            int num;
            cin>>num;
            append(dynamicArray,i,beginSize,num);
        }
    }

    cout << beginSize << " " << add << endl;

    for(int i=0;i<add;i++){
        cout<<dynamicArray[i]<<" ";
    }
    return 0;
}
