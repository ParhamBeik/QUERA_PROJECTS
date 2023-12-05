#include<iostream>
using namespace std;
int main(){
    char a[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char character;
            cin>>character;
            a[i][j]=character;
        }
    }
    char res="S";
    int count=0;
    int i=0,j=0;
    while(res!="E"){
        if(j+1>0 && j+1<5 && a[i][j+1]=="."){
            res=a[i][j+1];
            count++;
            j++;
        }
        else if(i-1>0 && i-1<5 && a[i-1][j]=="."){
            res=a[i-1][j];
            count++;
            i--;
        }
        else if(j-1>0 && j-1<5 && a[i][j-1]=="."){
            res=a[i][j-1];
            count++;
            j--;
        }
        else if(i+1>0 && i+1<5 && a[i+1][j]=="."){
            res=a[i+1][j];
            count++;
            i++;
        }
        else if(a[i][j]=="E"){
            cout<<count;
            break;
        }
        else if(a[i][j]=="."){
            cout<<"Lost!";
            break;
        }
    }
    return 0;
}