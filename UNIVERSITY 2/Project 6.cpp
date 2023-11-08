#include<iostream>
using namespace std;
int main(){
	int numberOfRows;
	cin>>numberOfRows;
	if(numberOfRows>0){
		for(int x=1;x<=numberOfRows;x++){
			int indexCount;
			if(x%2==1){
				indexCount=0;
			}
			else{
				indexCount=1;
			}
			for(int y=0;y<x;y++){
				if(indexCount%2==0){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
				indexCount+=1;
			}
			cout<<endl;
		}
	}
	else{
		cout<<"Impossible";
	}
	return 0;
}
