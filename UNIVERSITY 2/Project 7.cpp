#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int firstNumber,secondNumber,sqrtFirstNumber,sqrtSecondNumber,thirdOfFirstNumber,thirdOfSecondNumber;
	string name;
	cin>>name>>firstNumber>>secondNumber;
	
	sqrtFirstNumber=sqrt(firstNumber);
	sqrtSecondNumber=sqrt(secondNumber);
	
	thirdOfFirstNumber=cbrt(firstNumber);
	thirdOfSecondNumber=cbrt(secondNumber);
	
	vector<string> nameOfOpperation;
	vector<int> listOfSquares;
	vector<int> listOfCubics;
	
	nameOfOpperation.push_back("square");
	nameOfOpperation.push_back("cubic");
	
	if(name==nameOfOpperation[0]){
		for(int i=sqrtFirstNumber+1;i<=sqrtSecondNumber;i++){
			listOfSquares.push_back(i*i);
		}
		for(int i=0;i<=listOfSquares.size();i++){
			if(firstNumber<listOfSquares[i]<secondNumber){
				cout<<listOfSquares[i]<<" ";
			}
			else{
				cout<<"None";
			}
		}
	}
	else{
		for(int i=thirdOfFirstNumber+1;i<=thirdOfSecondNumber;i++){
			listOfCubics.push_back(i*i*i);
		}
		for(int i=0;i<=listOfCubics.size();i++){
			if(firstNumber<listOfSquares[i]<secondNumber){
				cout<<listOfCubics[i]<<" ";
			}
			else{
				cout<<"None";
			}
		}
	}
	return 0;
}
