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

template<typename T>
void printArray(T list[],int round){
    for(int i=0;i<round;i++){
	    cout << *(list+i) << endl; 
	}
}

void arrayLogic(string type ,int round){
    if(type=="int"){
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
        
        printArray(list,round);
    }
    else if(type=="long long"){
        long long list[round];
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
        
        printArray(list,round);
    }
    else if(type=="double"){
        double list[round];
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
        
        printArray(list,round);
    }
    else if(type=="char"){
        char list[round];
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
        
        printArray(list,round);
    }
    else if(type=="string"){
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
        
        printArray(list,round);
    }
    else if(type=="short"){
        short list[round];
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
        
        printArray(list,round);
    }
    
}
int main(){
    string type;
    int round;
    cin >> type >> round;
	
    arrayLogic(type,round);
    
    return 0;
}