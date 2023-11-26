#include<iostream>
using namespace std;
int main(){
	int num,prevNum,total=0,heavyTotal=0,index=0;
	do{
		cin>>num;
		if(index==0){
			prevNum=num;
		}
		if((prevNum==0 && num==2) || (prevNum==2 && num==0)){
			heavyTotal++;
		}
		if(num!=prevNum){
			total++;
		}
		index++;
		prevNum=num;
	}
	while(num!=-1);
	cout<<total-1<<" "<<heavyTotal;
	return 0;
}
