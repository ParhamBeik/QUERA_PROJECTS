#include<iostream>
using namespace std;

void primeNumbers(int firstNum,int secondNum){
	int total=0;
	cout<<"nums: ";
	for(int i=firstNum;i<=secondNum;i++){
		int count=0;
		for(int x=2;x<secondNum;x++)
			if(i%x==0 && i!=x){
				count++;
			}
		if(count==0){
			if(i!=1){
				cout<<i<<" ";
				total+=i;
			}
		}
	}
	cout<<endl<<"sum: "<<total;

}

int main(){
	int firstNumber,secondNumber;
	cin>>firstNumber>>secondNumber;
	primeNumbers(firstNumber,secondNumber);
    return 0;
}
