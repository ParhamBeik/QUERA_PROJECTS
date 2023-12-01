#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n1,n2,m1,m2;
	cin>>n1>>n2>>m1>>m2;
	int a[n1][n2],b[m1][m2],c[n1][m2];
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
		for(int x=0;x<n1;x++){
			for(int y=0;y<m2;y++){
				for(int i=0;i<n2;i++){
					int total=0;
					for(int j=0;j<m1;j++){
						total+=a[i][j]*b[j][i];
					}
					c[x][y]=total;
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
