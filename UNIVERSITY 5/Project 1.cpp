#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int number=n;
	int list[number];
	list[0]=5;
	for(int i=1;i<=n-1;i++){
		if(i%2==1){
			list[i]=list[i-1]*list[i-1];
		}
		else{
			list[i]=list[i-1]-21;
		}
	}
	cout<<list[number-1];
	return 0;
}
