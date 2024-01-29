#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++){
		list[i]=i+1;
	}
	
	int index=0,step=1,count;
	count=0;
	for(int i=0;i<n;i++){
		if(list[i]!=0){
			count++;
		}
	}
	while(count!=1){
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
		count=0;
		for(int i=0;i<n;i++){
			if(list[i]!=0){
				count++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(list[i]!=0){
			cout<<list[i];
		}
	}
	return 0;
}