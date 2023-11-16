#include<iostream>
using namespace std;
int main(){
    int timeLimit,forwardStep,backStep,startPosition,finishPosition,totalPosition;
    cin >> timeLimit >> forwardStep >> backStep >> startPosition >> finishPosition >> totalPosition;

    int forwardResault,backwardResault;

    if(startPosition<finishPosition){
        forwardResault=timeLimit-((finishPosition-startPosition)*forwardStep);
    }
    else{
        forwardResault=timeLimit-((totalPosition-startPosition+finishPosition)*forwardStep);
    }

    if(startPosition<finishPosition){
        backwardResault=timeLimit-((startPosition+totalPosition-finishPosition)*backStep);
    }
    else{
        backwardResault=timeLimit-((startPosition-finishPosition)*backStep);
    }
    

    if(forwardResault>=0){
        cout<<"J : "<<forwardResault<<endl;
    }
    if(backwardResault>=0){
        cout<<"A : "<<backwardResault<<endl;
    }
    if(forwardResault<0 && backwardResault<0){
        cout<<-1;
    }
    return 0;
}