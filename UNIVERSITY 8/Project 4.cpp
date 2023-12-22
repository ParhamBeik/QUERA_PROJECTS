#include<string>
#include<iostream>
using namespace std;
int main(){
    int round;
    cin>>round;
    
    int a[round],b[round];

    for(int i=0;i<round;i++){
        cin>>a[i];
    }
    for(int i=0;i<round;i++){
        cin>>b[i];
    }

    int sum=0;
    for(int i=0;i<round;i++){
        if(a[i] != b[i]){
        	int bucket=b[i],index=0;
        	while(b[index]!=a[i]){
        		index++;
			}
			b[i]=b[index];
			b[index]=bucket;
        	sum++;
		}
    }
	
	cout<<sum;
    
    return 0;
}
