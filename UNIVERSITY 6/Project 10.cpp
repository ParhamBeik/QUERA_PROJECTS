#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;

    int index=0;
    while(index<str.size()){
        if(str[index]==98 && str[index+1]==101 && str[index+2]==101 && str[index+3]==112){
            str[index]=32;
            str[index+1]=127;
            str[index+2]=127;
            str[index+3]=127;
            index+=3;
        }
        else if(str[index]==98 && str[index+1]==108 && str[index+2]==105 && str[index+3]==112){
        	str[index]=32;
            str[index+1]=127;
            str[index+2]=127;
            str[index+3]=127;
            index+=3;
		}
        else if(str[index]==98 && str[index+1]==111 && str[index+2]==111 && str[index+3]==112){
        	str[index]=10;
            str[index+1]=127;
            str[index+2]=127;
            str[index+3]=127;
            index+=3;
		}
		index++;
    }
	string newStr="";
	int a=0;
	for(int i=0;i<str.size();i++){
		if(str[i]!=127 && a>0){
			newStr+=str[i];
		}
		a++;
	}
	
    cout<<newStr;
    return 0;
}
