#include<iostream>
using namespace std;
int main(){
    int numberOfDefenders=0,numberOfHofbacks=0,numberOfAttackers=0;
    for(int i=0;i<15;i++){
        char character;
        cin>>character;
        
        if(character==43 && i%3==0){
            numberOfDefenders+=1;
        } 
        else if(character==43 && i%3==1){
            numberOfHofbacks+=1;
        } 
        else if(character==43 && i%3==2){
            numberOfAttackers+=1;
        } 
        else if(character==45 && i%3==0){
            continue;
        } 
        else if(character==45 && i%3==1){
            continue;
        } 
        else if(character==45 && i%3==2){
            continue;
        }	
    }
	if((numberOfAttackers+numberOfDefenders+numberOfHofbacks)==10){
        cout<<numberOfDefenders<<"-"<<numberOfHofbacks<<"-"<<numberOfAttackers;
    }
    else{
        cout<<"Invalid formation";
    }
    return 0;
}
