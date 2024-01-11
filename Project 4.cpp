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

template<typename S>
void shuffle(S list[],int size){
    srand(0);
    for(int i=size-1;i>=0;i--){
        int j = rand() % (i+1);
        swap(&list[i],&list[j]);
    }
    for(int i=0;i<size;i++){
        cout << list[i] << endl;
    }
}

int main(){
    string type;
    int round;
    cin >> type;
    if(type=="long"){
        cin >> type;
    }
    cin >> round;

    if(type=="string"){
        string list[round];
        for(int i=0;i<round;i++){
            cin >> list[i];
        }
        shuffle(list,round);
    }
    else if(type=="int"){
        int list[round];
        for(int i=0;i<round;i++){
            cin >> list[i];
        }
        shuffle(list,round);
    }
    else if(type=="long"){
        long long list[round];
        for(int i=0;i<round;i++){
            cin >> list[i];
        }
        shuffle(list,round);
    }
    else if(type=="double"){
        double list[round];
        for(int i=0;i<round;i++){
            cin >> list[i];
        }
        shuffle(list,round);
    }

    return 0;
}