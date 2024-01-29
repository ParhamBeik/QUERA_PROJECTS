#include<iostream>
using namespace std;
int main(){
	int x,y,index=0;
	cin>>x>>y;
	for(int i=0;i<x;i++){
		int totalOfDay,dayNum,totalOfPrevDay;
		totalOfDay=0;
		for(int j=0;j<y;j++){
			cin>>dayNum;
			totalOfDay+=dayNum;
		}
		if(index==0){
			totalOfPrevDay=totalOfDay;
		}
		if(index!=0){
			if(totalOfDay<totalOfPrevDay){
				cout<<"Better Call Saul"<<endl;
			}
			else{
				cout<<"Better Not to Call Saul"<<endl;
			}
		}
		index++;
		if(index!=0){
			totalOfPrevDay=totalOfDay;
		}
	}

	return 0;
}
