#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string* word = new string;
    cin>>*word;
    *word+="*";

    int* round = new int;
    round[0]=0;
    
    while((*word)[*round]!=42){
        round[0]++;
    }
	
    while(round[0] != 0){
    	cout<<(*word)[round[0]-1];
        round[0]--;
    }
    return 0;
}
