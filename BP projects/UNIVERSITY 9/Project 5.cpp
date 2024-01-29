#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string check(char arr[3][3]){
    for(int i=0;i<3;i++){
        bool xWin=true;
        for(int j=0;j<3;j++){
            if(arr[i][j]!='X'){
                xWin=false;
                break;
            }
        }
        if(xWin){
            return "Winner: X";
        }
    }
    for(int i=0;i<3;i++){
        bool xWin=true;
        for(int j=0;j<3;j++){
            if(arr[j][i]!='X'){
                xWin=false;
                break;
            }
        }
        if(xWin){
            return "Winner: X";
        }
    }
    for(int i=0;i<3;i++){
        bool oWin=true;
        for(int j=0;j<3;j++){
            if(arr[i][j]!='O'){
                oWin=false;
                break;
            }
        }
        if(oWin){
            return "Winner: O";
        }
    }
    for(int i=0;i<3;i++){
        bool oWin=true;
        for(int j=0;j<3;j++){
            if(arr[j][i]!='O'){
                oWin=false;
                break;
            }
        }
        if(oWin){
            return "Winner: O";
        }
    }
    if(arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X'){
        return "Winner: X";
    }
    if(arr[2][0]=='X' && arr[1][1]=='X' && arr[0][2]=='X'){
        return "Winner: X";
    }
    if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O'){
        return "Winner: O";
    }
    if(arr[2][0]=='O' && arr[1][1]=='O' && arr[0][2]=='O'){
        return "Winner: O";
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]=='#'){
                return "Not finished";
            }
        }
    }
    return "Draw";
}
int main() {
    fstream TickTack;
    TickTack.open("input.txt",ios::in);

    vector<string> situation;

    if(TickTack.is_open()){
        string line;
        int counter=0;
        int x=0,y=0;
        char table[3][3];
        while(getline(TickTack,line)){
            x=x%3;
            y=y%3;
            for(int i=0;i<line.size();i++){
                if( !(line[i]==' ' || line[i]=='-') ){
                    table[x][y]=line[i];
                    // cout<<x<<"  "<<y<<endl;
                    y++;
                }
            }
            if(line[0]!='-'){
                x++;
            }
            if(counter%4==3){
                string res;
                res=check(table);
                situation.push_back(res);
                // for(int i=0;i<3;i++){
                //     for(int j=0;j<3;j++){
                //         cout << table[i][j] <<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<endl;
            }
            counter++;
        }
    }
    else{
        cerr << "sth went wrong";
    }

    for(int i=0;i<situation.size();i++){
        cout << situation[i] << endl;
    }
    
    TickTack.close();
    
    return 0;
}
