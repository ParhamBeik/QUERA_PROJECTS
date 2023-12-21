#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string* word = new string;
    cin>>*word;
    *word+="*";

    int* round;
    round= new int;
    round[0]=0;
    
    while((*word)[*round]!=42){
        round[0]++;
    }
	
    for(int i=round[0]-1;i>-1;i--){
    	cout<<(*word)[i];
    }
    return 0;
}
