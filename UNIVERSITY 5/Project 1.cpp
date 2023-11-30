#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int list[n+1];
	list[0]=5;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			list[i]=list[i-1]*list[i-1];
		}
		else if(i%2==0){
			list[i]=list[i-1]-21;
		}
	}
	cout<<list[n];
	return 0;
}
