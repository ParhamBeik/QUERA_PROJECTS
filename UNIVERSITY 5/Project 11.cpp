#include<iostream>
using namespace std;
int main(){
    int round;
    cin>>round;
    //the number of matrixes 
    for(int i=0;i<round;i++){
        int n;
        cin>>n;
        double a[n][n],aT[n][n],res1[n][n],res2[n][n];
        //initializing each matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double num;
                cin>>num;
                a[i][j]=num;
                aT[j][i]=num;
            }
        }
        //multiplying the matrix with it's orthangical version
        for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				for(int z=0;z<n;z++){
					res1[x][y]+=(a[x][z]*aT[z][y]);
				}
			}
		}
        for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				for(int z=0;z<n;z++){
					res2[x][y]+=(aT[x][z]*a[z][y]);
				}
			}
		}
        //checking if the resault matrixes are equal to the I matrix
        bool isTrue=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j && res1[i][j]!=1){
                    isTrue=false;
                }
                else if(i!=j && res1[i][j]!=0){
                    isTrue=false;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j && res2[i][j]!=1){
                    isTrue=false;
                }
                else if(i!=j && res2[i][j]!=0){
                    isTrue=false;
                }
            }
        }
        if(isTrue){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
