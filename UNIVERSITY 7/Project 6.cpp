#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
void resize (int*& dynamicArray, int& capacity, int newCapacity) {
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
	
	beginSize = sqrt(beginSize);
	beginSize = pow(2,beginSize);
	
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
    	dynamicArray=new int(sizeof(beginSize));
        resize(dynamicArray,beginSize,add);
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
