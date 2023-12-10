#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int round;
    cin>>round;
    
    bool isTrue[round];
    for(int i=0;i<round;i++){
    	isTrue[i]=false;
	}
	
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        string first="";
        string second="";
        string res="";
        int index=0;
        while(str[index]!=42 || str[index]!=43 || str[index]!=45 || str[index]!=47){
            first+=str[index];
            index++;
        }
        string operate="";
        operate+=str[index];
        
        index++;
        while(str[index]!=61){
            second+=str[index];
            index++;
        }
        index++;
        while(index < str.size()){
            res+=str[index];
        }
        int firstNum,secondNum,resault,test=0;

        stringstream ss;
        ss << first;
        ss >> firstNum;
        
        ss << second;
        ss >> secondNum;

        ss << res;
        ss >> resault;

        if(operate=="*"){
            test=firstNum*secondNum;
        }
        else if(operate=="+"){
            test=firstNum+secondNum;
        }
        else if(operate=="-"){
            test=firstNum-secondNum;
        }
        else if(operate=="/"){
            test=firstNum/secondNum;
        }
        
        if(test==resault){
            isTrue[i]==true;
        }
    }
	
	for(int i=0;i<round;i++){
		if(isTrue[i]){
			cout<<"True"<<endl;
		}
		else{
			cout<<"False"<<endl;
		}
	}

    return 0;
}
