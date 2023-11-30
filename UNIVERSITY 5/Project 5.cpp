#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int count,low=0,high=0,total=0;
	cin>>count;
	int list[count],reverseList[count];
	for(int i=0;i<count;i++){
		int num;
		cin>>num;
		
		if(i==0){
			low=num;
			high=count;
		}
		
		total+=num;
		list[i]=num;
		reverseList[count-1-i]=list[i];
		
		
		if(num>high){
			high=num;
		}
		if(num<low){
			low=num;
		}
	}
	float average=float(total)/float(count);
	
	for(int j=0;j<count;j++){
		for(int i=0;i<count-1;i++){
			if(list[i]>list[i+1]){
				int bucket=0;
				bucket=list[i];
				list[i]=list[i+1];
				list[i+1]=bucket;
			}
		}
	}
	
	cout<<"max : "<<high<<endl;
	cout<<"min : "<<low<<endl;
	cout<<"sum : "<<total<<endl;
	cout<<setprecision(3)<<"avg : "<<average<<endl;
	cout<<"reverse : ";
	for(int i=0;i<count;i++){
		cout<<reverseList[i]<<" ";
	}
	cout<<endl;
	cout<<"sorted : ";
	for(int i=0;i<count;i++){
		cout<<list[i]<<" ";
	}
	return 0;
}
