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
	int middle=(total+1)/2,month=1,day=0;
	
	int sum=0;
	int index=1;
	
	while(sum!=middle){
		sum++;

		int sumOfDays=0;
		for(int i=0;i<=index-1;i++){
			sumOfDays+=listOfDays[i];
		}
		
		int sumOfLessDays=0;
		for(int i=0;i<index-1;i++){
			sumOfLessDays+=listOfDays[i];
		}
		
		
		day=sum-sumOfLessDays;
		
		if(sum>sumOfDays){
			month++;
			index++;
		}
	}
	cout<<month<<" "<<day;
	return 0;
}
