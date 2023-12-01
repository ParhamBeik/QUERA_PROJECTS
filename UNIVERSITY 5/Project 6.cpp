#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int first,second;
	vector<double> list;
	cin>>first;
	for(int i=0;i<first;i++){
		double num;
		cin>>num;
		list.push_back(num);
	}
	cin>>second;
	for(int i=0;i<second;i++){
		double num;
		cin>>num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());
	
	double high=0,low=0;
	for(int i=0;i<first+second-1;i++){
		if(i==0){
			high=list[i+1]-list[i];
			low=high;
		}
		if( (list[i+1]-list[i]) > high){
			high=list[i+1]-list[i];
		}
		if( ((list[i+1]-list[i]) < low) && (list[i+1]-list[i])!=0){
			low=list[i+1]-list[i];
		}
	}
	
	cout<<low<<" "<<high;
	return 0;
}
