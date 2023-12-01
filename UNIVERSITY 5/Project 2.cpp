#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	double a[n],b[n];
	double c[n];
	
	for(int i=0;i<n;i++){
		double number;
		cin>>number;
		a[i]=number;
	}
	for(int i=0;i<n;i++){
		double number;
		cin>>number;
		b[i]=number;
	}
	
	for(int i=0;i<n;i++){
		double total=0;
		int index=i;
		for(int j=0;j<=i;j++){
			total+=a[j]*b[index];
			index--;
		}
		c[i]=total;
	}
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
	for(int i=0;i<n;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
