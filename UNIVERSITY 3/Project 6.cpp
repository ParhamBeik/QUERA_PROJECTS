#include<iostream>
#include<math.h>
using namespace std;

int Tavan(int n){
    long long int numPow=pow(2,n);
    return numPow+1;
}

bool isPrime(long long int number){
    int count=0;
    for(long long int i=2;i<number;i++){
        if(number%i==0){
            count++;
        }
    }
    if(count==0 && number!=1){
        return true;
    }
    else{
        return false;
    }
}

int TheResault(int n){
    long long int number=Tavan(n),numberOfPrimeMaghsoom=0;
    for(long long int i=2;i<=number;i++){
        if(number%i==0 && isPrime(i)){
            numberOfPrimeMaghsoom++;
        }
    }
    while(numberOfPrimeMaghsoom%3!=0){
        numberOfPrimeMaghsoom=0;
        for(int i=2;i<=number;i++){
            if(number%i==0 && isPrime(i)){
                numberOfPrimeMaghsoom++;
            }
        }
        if(numberOfPrimeMaghsoom%3==0){
            return number;
        }
        else{
            number++;
        }
    }
    return number;
}

int main(){
    int n;
    cin>>n;
    cout<<TheResault(n);
    return 0;
}