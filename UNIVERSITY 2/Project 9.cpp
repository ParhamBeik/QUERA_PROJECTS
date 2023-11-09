#include<iostream>
using namespace std;
int main(){
	int height;
	cin>>height;
	
	int index=(2*height-1);
	for(int x=1;x<=height;x++){
		int n=x;
		int count=0;
		for(int y=1;y<=(2*height-1);y++){
			if(y<index){
			cout<<" ";
			}
			else{
				if(n!=1 && count==0){
					cout<<n;
					n--;
				}
				else if(n!=1 && count!=0){
					cout<<n;
					n++;
				}
				else{
					cout<<n;
					n++;
					count++;
				}
			}
		}
		index-=2;
		cout<<endl;
	}
	
	index=2;
	for(int x=1;x<=height-1;x++){
		int n=height-x;
		int count=0;
		for(int y=1;y<=(2*height-1);y++){
			if(y>index){
				if(n!=1 && count==0){
					cout<<n;
					n--;
				}
				else if(n!=1 && count!=0){
					cout<<n;
					n++;
				}
				else{
					cout<<n;
					n++;
					count++;
				}
			}
			else{
				cout<<" ";
			}
		}
		index+=2;
		cout<<endl;
	}
	
	
	return 0;
}
