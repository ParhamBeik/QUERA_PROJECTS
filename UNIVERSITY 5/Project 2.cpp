#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],b[n];
	double c[n];
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		a[i]=number;
	}
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		b[i]=number;
	}
	for(int j=0;j<n;j++){
		int total=0,index=n-1;
		for(int i=0;i<=j;i++){
			total+=a[i]*b[index];
			index--;
		}
		c[j]=total;
	}
	for(int i=0;i<n;i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
