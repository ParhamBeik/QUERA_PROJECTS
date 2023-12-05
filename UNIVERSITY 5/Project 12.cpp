#include<iostream>
#include<vector>
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

    vector<int> list;

    string res="S";
    int count=0;
    int i=0,j=0;

    while(res!="E"){
        //going forward
        bool isTrue1=true;
        for(int a=0;a<list.size();a++){
            if(a%2==0 && list[a]==i && list[a+1]==j){
                isTrue1=false;
            }
        }
        if(j+1>0 && j+1<5 && a[i][j+1]=="." && isTrue1){
            res=a[i][j+1];
            count++;
            list.push_back(i);
            list.push_back(j);
            j++;
        }
        else if(j+1>0 && j+1<5 && a[i][j+1]=="E" && isTrue1){
            res=a[i][j+1];
            count++;
            list.push_back(i);
            list.push_back(j);
            j++;
            cout<<count;
            break;
        }
        //going downward
        else if(i-1>0 && i-1<5 && a[i-1][j]=="." && isTrue1){
            res=a[i-1][j];
            count++;
            list.push_back(i);
            list.push_back(j);
            i--;
        }
        else if(i-1>0 && i-1<5 && a[i-1][j]=="E" && isTrue1){
            res=a[i-1][j];
            count++;
            list.push_back(i);
            list.push_back(j);
            i--;
            cout<<count;
            break;
        }
        //going leftwards
        else if(j-1>0 && j-1<5 && a[i][j-1]=="." && isTrue1){
            res=a[i][j-1];
            count++;
            list.push_back(i);
            list.push_back(j);
            j--;
        }
        else if(j-1>0 && j-1<5 && a[i][j-1]=="E" && isTrue1){
            res=a[i][j-1];
            count++;
            list.push_back(i);
            list.push_back(j);
            j--;
            cout<<count;
            break;
        }
        //going upwards
        else if(i+1>0 && i+1<5 && a[i+1][j]=="." && isTrue1){
            res=a[i+1][j];
            count++;
            list.push_back(i);
            list.push_back(j);
            i++;
        }
        else if(i+1>0 && i+1<5 && a[i+1][j]=="E" && isTrue1){
            res=a[i+1][j];
            count++;
            list.push_back(i);
            list.push_back(j);
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
