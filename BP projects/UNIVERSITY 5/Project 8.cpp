#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    a[0]=0;
    for(int i=1;i<n;i++){
        bool isInList=false;
        int test=a[i-1]-i;
        for(int j=0;j<=i;j++){
            if(test==a[j]){
                isInList=true;
            }
        }
        if(test>0 && isInList==false){
            a[i]=test;
        }
        else{
            a[i]=a[i-1]+i;
        }
    }
    for(int i=0;i<n;i++){
        int div=10,total=0,copy=a[i];
        while(copy!=0){
        	total+=copy%div;
        	copy/=div;
		}
		a[i]=total;
		cout<<a[i]<<", ";
    }
    return 0;
}
