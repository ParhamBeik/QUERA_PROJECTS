#include<iostream>
using namespace std;
int main(){
	int num,step=0,number=1;
	cin>>num;
	int index=num-1;
	
	for(int i=0;i<num;i++){
		for(int j=0;j<2*num-1;j++){
			if((j==(index+step)) || (j==(index-step))){
				cout<<number;
			}
			else{
				cout<<" ";
			}
		}
		number++;
		step++;
		cout<<endl;
	}
	
	step=num-2,number=num-1;
	index=num-1;
	for(int i=0;i<num-1;i++){
		for(int j=0;j<2*num-1;j++){
			if((j==(index+step)) || (j==(index-step))){
				cout<<number;
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
