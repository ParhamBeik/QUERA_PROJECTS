#include<iostream>
#include<string>
using namespace std;
int main(){
    string a[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string character;
            cin>>character;
            a[i][j]=character;
        }
    }

    string res="S";
    bool flag[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            flag[i][j]=false;
        }
    }
    int count=0;
    int i=0,j=0;

    while(res!="E"){
        //going forward
        if(j+1>0 && j+1<5 && a[i][j+1]=="." && flag[i][j+1]==false){
            res=a[i][j+1];
            flag[i][j]=true;
            count++;
            j++;
        }
        else if(j+1>0 && j+1<5 && a[i][j+1]=="E" && flag[i][j+1]==false){
            res=a[i][j+1];
            flag[i][j]=true;
            count++;
            j++;
            cout<<count;
            break;
        }
        //going downward
        else if(i-1>0 && i-1<5 && a[i-1][j]=="." && flag[i-1][j]==false){
            res=a[i-1][j];
            flag[i][j]=true;
            count++;
            i--;
        }
        else if(i-1>0 && i-1<5 && a[i-1][j]=="E" && flag[i-1][j]==false){
            res=a[i-1][j];
            flag[i][j]=true;
            count++;
            i--;
            cout<<count;
            break;
        }
        //going leftwards
        else if(j-1>0 && j-1<5 && a[i][j-1]=="." && flag[i][j-1]==false){
            res=a[i][j-1];
            flag[i][j]=true;
            count++;
            j--;
        }
        else if(j-1>0 && j-1<5 && a[i][j-1]=="E" && flag[i][j-1]==false){
            res=a[i][j-1];
            flag[i][j]=true;
            count++;
            j--;
            cout<<count;
            break;
        }
        //going upwards
        else if(i+1>0 && i+1<5 && a[i+1][j]=="." && flag[i+1][j]==false){
            res=a[i+1][j];
            flag[i][j]=true;
            count++;
            i++;
        }
        else if(i+1>0 && i+1<5 && a[i+1][j]=="E" && flag[i+1][j]==false){
            res=a[i+1][j];
            flag[i][j]=true;
            count++;
            i++;
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
