#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++){
		list[i]=i+1;
	}
	
	int index=0,step=1;
	for(int i=0;i<n-1;i++){
		if(list[step%n]!=0){
			if((index)%2==0){
				list[step%n]=0;
				index++;
				step++;
			}
			else{
				index++;
				step++;
			}
		}
		else{
			step++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<list[i]<<" ";
	}
	return 0;
}
