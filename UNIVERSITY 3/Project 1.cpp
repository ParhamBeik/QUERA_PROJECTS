#include<iostream>
using namespace std;

void primeNumbers(int number){
	int count=0;
	for(int i=2;i<=number;i++){
		for(int x=2;x<=i;x++)
			if(i%x==0 && i!=x){
				count++;
			}
		if(count==0){
			cout<<i;
		}
	}
}

int main(){
	int number;
	cin>>number;
	primeNumbers(number);
    return 0;
}
