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
        distanceOfTwo=(float)sqrt((akbarX-asgharX)*(akbarX-asgharX)+(akbarY-asgharY)*(akbarY-asgharY));
        return distanceOfTwo;
    }
    else if(round==2){
        float distanceOfTwo=0.00;
        akbarX=3,akbarY=2,asgharX=-2,asgharY=2;
        distanceOfTwo=(float)sqrt((akbarX-asgharX)*(akbarX-asgharX)+(akbarY-asgharY)*(akbarY-asgharY));
        return distanceOfTwo;
    }
    else{
        akbarX=3,akbarY=2,asgharX=-2,asgharY=2;
        float distanceOfTwo=0.00;
        akbarX+=(int)((round-2)/2)*1;
        akbarY+=(int)((round-2)/2)*2;
        asgharX-=(int)((round-2)/2)*2;
        distanceOfTwo=(float)sqrt((akbarX-asgharX)*(akbarX-asgharX)+(akbarY-asgharY)*(akbarY-asgharY));
        return distanceOfTwo;
    }
}
int main(){
    int numberOfRound;
    float resault;
    cin>>numberOfRound;
    resault=distance(numberOfRound);
    cout.precision(2);
    cout<<fixed<<resault;
    return 0;
}