#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	//number of rounds
    int round;
    cin>>round;
    //initializing the false or true value at the end
    bool isTrue[round];
    for(int i=0;i<round;i++){
    	isTrue[i]=false;
	}
	//going through each string and doing the calculations
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        
        string first="";
        string second="";
        string res="";
        //setting the first number
        int index=0;
        while(str[index]!=42 || str[index]!=43 || str[index]!=45 || str[index]!=47){
            first+=str[index];
            index++;
        }
        //setting the operator
        string operate="";
        operate+=str[index];
        
        index++;
        //setting the second number
        while(str[index]!=61){
            second+=str[index];
            index++;
        }
        index++;
        //setting the resault value that has been given and checking if it is true or false
        while(index < str.size()){
            res+=str[index];
        }
        cout<<first<<endl<<second<<res;
        //turning the strings into numbers
        int firstNum,secondNum,resault,test=0;

        stringstream ss;
        ss << first;
        ss >> firstNum;
        
        ss << second;
        ss >> secondNum;

        ss << res;
        ss >> resault;
		//doing the operations in the correct way using the integer value of them
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
        //checking if they are the same
        if(test==resault){
            isTrue[i]==true;
        }
    }
	//returning the truthiness or the falsiness of the equiations
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
