#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,total=0;
	cin>>n;
	vector<int> listOfDays;
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		total+=number;
		listOfDays.push_back(number);
	}
	int middle=(total+1)/2,month=0,day=0;
	
	int sum=0;
	
	for(int i=0;i<n;i++){
		if(sum!=middle){
			day=0;
		}
		for(int j=0;j<listOfDays[i];j++){
			sum++;
			if(sum!=middle){
				day++;
			}
		}
		if(sum!=middle){
			month++;
		}
	}
	
	cout<<month<<" "<<day;
	return 0;
}
