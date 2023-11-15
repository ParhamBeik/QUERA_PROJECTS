#include<iostream>
#include<cmath>
using namespace std;
float distance(int round){
    int akbarX=1,akbarY=1,asgharX=-1,asgharY=1;
    if(round%2==1){
        float distanceOfTwo=0;
        akbarX+=(int)(round/2)*1;
        akbarY+=(int)(round/2)*2;
        asgharX-=(int)(round/2)*2;
        distanceOfTwo=sqrt(akbarX*akbarX+akbarY*akbarY+asgharX*asgharX+asgharY*asgharY);
        return distanceOfTwo;
    }
    else{
        akbarX=3,akbarY=2,asgharX=-2,asgharY=2;
        float distanceOfTwo=0;
        akbarX+=(int)(round/2)*1;
        akbarY+=(int)(round/2)*2;
        asgharX-=(int)(round/2)*2;
        distanceOfTwo=sqrt(akbarX*akbarX+akbarY*akbarY+asgharX*asgharX+asgharY*asgharY);
        return distanceOfTwo;
    }
}
int main(){
    int numberOfRound;
    float resault;
    cin>>numberOfRound;
    resault=distance(numberOfRound);
    cout<<resault;
    return 0;
}