#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	long long int firstNumber,secondNumber;
	string name;
	cin>>name>>firstNumber>>secondNumber;
	
	vector<int> listOfCubics;
	vector<int> listOfSquared;
	
	if(name=="cubic"){
		for(int x=1;x<secondNumber+1;x++){
			int xCubiced=pow(x,3);
			if(firstNumber<xCubiced && xCubiced<secondNumber){
				listOfCubics.push_back(xCubiced);
			}
		}
		if(listOfCubics.size()==0){
			cout<<"None";
		}
		else{
			for(int i=0;i<listOfCubics.size();i++){
				cout<<listOfCubics[i]<<" ";
			}
		}
	}
	else{
		for(int x=1;x<secondNumber+1;x++){
			int xSquared=pow(x,2);
			if(firstNumber<xSquared && xSquared<secondNumber){
				listOfSquared.push_back(xSquared);
			}
		}
		if(listOfSquared.size()!=0){
			for(int i=0;i<listOfSquared.size();i++){
				cout<<listOfSquared[i]<<" ";
			}
		}
		else{
			cout<<"None";
		}
	}
	
	return 0;
}
