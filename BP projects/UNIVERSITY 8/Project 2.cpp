#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    int round;
    cin>>round;

    vector<string> list;

    int sum=0;

    for(int i=0;i<round;i++){
        string str,num="",name="";
        cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j] > 47 && str[j] < 58){
                num+=str[j];
            }
            else{
                name+=str[j];
            }
        }
        stringstream ss;
        ss << num;
        int number;
        ss >> number;
        sum+=number;
        list.push_back(name);
    }

    bool isPoison=false;

    for(int i=0;i<list.size();i++){
    	int red=0,green=0,yellow=0;
        for(int j=0;j<list[i].size();j++){
            //R
            if(list[i][j]==82){
                red++;
            }
            //Y
            else if(list[i][j]==89){
                yellow++;
            }
            //G
            else if(list[i][j]==71){
                green++;
            }
        }
        if(red>2 || (red>1 && yellow>1) || (5==yellow) || (5==red)){
            isPoison=true;
            break;
        }
    }

    if(sum>500){
        isPoison=true;
    }

    if(isPoison){
        cout<<"nakhor khatarnake!"<<endl;
        cout<<sum;
    }
    else{
        cout<<"bokhor khialet rahat!"<<endl;
        cout<<sum;
    }

    return 0;
}
