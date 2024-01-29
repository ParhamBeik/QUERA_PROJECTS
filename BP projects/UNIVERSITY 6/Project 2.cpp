#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string name;
	int place;
	
	string list[n]={};
	
	for(int i=0;i<n;i++){
		cin>>name;
		cin>>place;
		list[place-1]=name;
	}
	
	for(int i=0;i<n;i++){
		cout<<list[i]<<endl;
	}
	
    return 0;
}
