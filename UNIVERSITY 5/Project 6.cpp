#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int first,second;
	vector<double> list;
	//initializing first ladder
	cin>>first;
	for(int i=0;i<first;i++){
		double num;
		cin>>num;
		list.push_back(num);
	}
	//initializing second ladder
	cin>>second;
	for(int i=0;i<second;i++){
		double num;
		cin>>num;
		list.push_back(num);
	}
	//putting all the heights together or in a sense sticking to ladder together
	sort(list.begin(), list.end());
	//assigning the high and low of the the two ladders
	double high=0,low=10000;
	for(int i=0;i<first+second-1;i++){
		if( (list[i+1]-list[i]) > high){
			high=list[i+1]-list[i];
		}
		if( ((list[i+1]-list[i]) < low) && (list[i+1]-list[i])!=0){
			low=list[i+1]-list[i];
		}
	}
	//printing the low and the high differenciation of the ladders
	if(first==1 && second==1 && list[0]==list[1]){
		cout<<0<<" "<<0;
	}
	else{
		cout<<low<<" "<<high;
	}
	return 0;
}
