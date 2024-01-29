#include<iostream>
#include<math.h>
using namespace std;

int Tavan(int n){
    int numberSquered=1;
    for(int i=0;i<n;i++){
        numberSquered*=2;
    }
    return numberSquered+1;
}

// bool isPrime(int number){
//     int numberSqrt=sqrt(number)+1;
//     bool isNumPrime=true;
//     for(int i=2;i<numberSqrt;i++){
//         if(number%i==0 || number==1){
//             isNumPrime=false;
//         }
//     }
//     if(isNumPrime){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

int Resault(int n){
    int number=Tavan(n);
    int copyOfNumber=number,PrimeFactorCount=0,index=2;
    while(copyOfNumber!=1){
        int a=0;
        while(copyOfNumber%index==0){
            copyOfNumber=copyOfNumber/index;
            a++;
        }
        if(a>0){
            PrimeFactorCount++;
        }
        index++;
    }
    if(PrimeFactorCount%3==0){
        return number;
    }
    else{
        while(PrimeFactorCount%3!=0){
            number++;
            copyOfNumber=number,PrimeFactorCount=0,index=2;
            while(copyOfNumber!=1){
                int a=0;
                while(copyOfNumber%index==0){
                    copyOfNumber=copyOfNumber/index;
                    a++;
                }
                if(a>0){
                    PrimeFactorCount++;
                }
                index++;
            }
        }
        return number;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<Resault(n);
    return 0;
}