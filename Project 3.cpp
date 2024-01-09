#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename T>
void swap (T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    string type;
    int round;
    cin >> type >> round;
	
    if(type=="string"){
        string list[round];
        for(int i=0;i<round;i++){
            cin >> list[i]; 
        }
        string func;
        int index1,index2;
        do{
            cin >> func;
            if(func!="exit"){
                cin >> index1 >> index2;
                swap(&list[index1] , &list[index2]);
            }
        }while(func!="exit");
        
        for(int i=0;i<round;i++){
	        cout << list[i] << endl; 
	    }
    }
    else{
        int list[round];
        for(int i=0;i<round;i++){
            cin >> list[i]; 
        }
        string func;
        int index1,index2;
        do{
            cin >> func;
            if(func!="exit"){
                cin >> index1 >> index2;
                swap(&list[index1] , &list[index2]);
            }
        }while(func!="exit");
        
        for(int i=0;i<round;i++){
	        cout << list[i] << endl; 
	    }
    }

    return 0;
}