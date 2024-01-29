#include<iostream>
using namespace std;
int main(){
	int height,numberOfShape;
	cin>>height>>numberOfShape;
	for(int z=0;z<numberOfShape;z++){
		int index=height-1;
		for(int x=0;x<height;x++){
			for(int y=0;y<height;y++){
				if(y<index){
					cout<<" ";
				}
				else{
					cout<<"^";
				}
			}
			index--;
			cout<<endl;
			
		}
		index=height-1;
		for(int x=0;x<height;x++){
			for(int y=0;y<height;y++){
				if(y<index){
					cout<<"^";
				}
				else{
					cout<<" ";
				}
			}
			index--;
			if(index!=0){
			cout<<endl;
			}
		}
	}
	return 0;
}
