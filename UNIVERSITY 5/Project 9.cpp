#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++){
		list[i]=i+1;
	}
	
	int index=1;
	for(int i=0;i<n-1;i++){
		if(list[index%n]!=0){
			if((index%n)%2==1){
				list[index%n]=0;
				index++;
			}
			else{
				index++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<list[i]<<" ";
	}
	return 0;
}
