#include<iostream>
using namespace std;
int main(){
	int n,index,step=0,number=1;
	cin>>n;
	index=(4*n-3)/2;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<(4*n-3);j++){
			if( (j>=index-step-number+1 && j<=index-step) || (j<=index+step+number-1 && j>=index+step)){
				cout<<(number%10);
			}
			else{
				cout<<" ";
			}
		}
		number++;
		step++;
		cout<<endl;
	}
	
	step=n-2;
	number=n-1;
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<(4*n-3);j++){
			if( (j>=index-step-number+1 && j<=index-step) || (j<=index+step+number-1 && j>=index+step)){
				cout<<(number%10);
			}
			else{
				cout<<" ";
			}
		}
		number--;
		step--;
		cout<<endl;
	}
	
	return 0;
}
