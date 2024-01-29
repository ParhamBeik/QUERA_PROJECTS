#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
	int num,power;
	cin>>num>>power;
	
	vector<int> listOfNums;
	while(power!=0){
		listOfNums.push_back(pow(num,power));
		power=power/2;
	}
	
	for(int i=listOfNums.size();i>=0;i--){
		if(listOfNums[i]>1){
			cout<<listOfNums[i]<<" ";
		}
		else{
			cout<<1<<" ";
		}
	}
	return 0;
}
