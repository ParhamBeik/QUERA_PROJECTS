#include<iostream>
using namespace std;

int Jolo(int timeLimit,int forwardStep,int backStep,int startPosition,int finishPosition,int totalPosition){
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
    if(forwardResault<0 && backwardResault<0){
        cout<<-1;
    }
    return 0;
}

int Aghab(int timeLimit,int backStep,int startPosition,int finishPosition,int totalPosition){
    int backwardResault;
    if(startPosition<finishPosition){
        backwardResault=timeLimit-((startPosition+totalPosition-finishPosition)*backStep);
    }
    else{
        backwardResault=timeLimit-((startPosition-finishPosition)*backStep);
    }
    if(backwardResault>=0){
        cout<<"A : "<<backwardResault<<endl;
    }
    return 0;
}
int main(){
    int timeLimit,forwardStep,backStep,startPosition,finishPosition,totalPosition;
    cin >> timeLimit >> forwardStep >> backStep >> startPosition >> finishPosition >> totalPosition;

    Jolo(timeLimit,forwardStep,backStep,startPosition,finishPosition,totalPosition);
    Aghab(timeLimit,backStep,startPosition,finishPosition,totalPosition);

    return 0;
}