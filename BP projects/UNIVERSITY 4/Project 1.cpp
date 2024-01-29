#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long int number,firstNum,secondNum,bucket;
	cin>>number;
	bucket=cbrt(number);
	firstNum=pow(bucket,3);
	if(firstNum!=number){
		secondNum=pow(bucket+1,3);
		cout<<firstNum<<endl<<secondNum;
	}
	else{
		bucket=bucket-1;
		firstNum=pow(bucket,3);
		secondNum=pow(bucket+2,3);
		cout<<firstNum<<endl<<secondNum;
	}
		
	return 0;
}
