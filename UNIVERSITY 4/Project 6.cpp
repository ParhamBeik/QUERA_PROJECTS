#include<iostream>
using namespace std;
int main(){
	int num,step,number;
	cin>>num;
	int index=(num*(num+1))/2;
	
	number=1;
	step=0;
	
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num*(num+1)-1;j++){
			
		}
		step++;
		number++;
		cout<<endl;
	}
	
//	step=num-2,number=num-1;
//	index=num-1;
//	for(int i=1;i<=num;i++){
//		for(int j=1;j<=num*(num+1);j++){
//			if((j==(index+step)) || (j==(index-step))){
//				cout<<number;
//			}
//			else{
//				cout<<" ";
//			}
//		}
//		number--;
//		step--;
//		cout<<endl;
//
//	}
//	
	return 0;
}
