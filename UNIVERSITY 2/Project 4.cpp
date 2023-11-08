#include<iostream>
#include<vector>
using namespace std;
int main(){
	int firstSide,secondSide,thirdSide;
	cin>>firstSide>>secondSide;
	vector<int> listOfSidesPossible;
	for(int i=1;i<101;i++){
		thirdSide=i;
		if(firstSide<secondSide+thirdSide && secondSide<firstSide+thirdSide && thirdSide<firstSide+secondSide){
			listOfSidesPossible.push_back(thirdSide);
		}
	}
	for(int i=0;i<listOfSidesPossible.size();i++){
		cout<<listOfSidesPossible[i]<<" ";
	}
	return 0;
}
