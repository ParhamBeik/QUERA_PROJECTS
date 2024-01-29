#include<iostream>
using namespace std;

int KMM(int first,int second){
    int kmm=1,copyOfSecond=second;
    for(int x=2;x<=copyOfSecond;x++){
        while(second%x==0 && first%x==0){
            kmm*=x;
            second/=x;
            first/=x;
        }        
    }
    return kmm;
}

void BMM(int first,int second){
    int kmm=KMM(first,second),bmm,difference ;
    bmm=first*second/kmm;
    difference=(bmm-kmm)*2;
    if(first!=second){
        cout<<difference<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

int main(){
    int rounds,firstNum,secondNum;
    cin>>rounds;
    for(int i=0;i<rounds;i++){            
        cin>>firstNum>>secondNum;
        BMM(firstNum,secondNum);
    }  
    return 0;
}