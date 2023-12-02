#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n1,n2,m1,m2;
	cin>>n1>>n2>>m1>>m2;
	int a[n1][n2];
	int b[m1][m2];
	int c[n1][m2];
	if(n2!=m1){
		cout<<"Infeasible";
	}
	else{
		for(int i=0;i<n1;i++){
			for(int j=0;j<n2;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<m1;i++){
			for(int j=0;j<m2;j++){
				cin>>b[i][j];
			}
		}
		for(int i=0;i<n1;i++){
			for(int j=0;j<m2;j++){
				for(int z=0;z<n2;z++){
					c[i][j]+=(a[i][z]*b[z][j]);
				}
				
			}
		}
		for(int i=0;i<n2;i++){
			for(int j=0;j<m1;j++){
				cout<<c[i][j]<<" ";
			}
		}
	}
	return 0;
}
