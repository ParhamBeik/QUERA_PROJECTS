#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isValid(string parenth){
	int openIndex=0,closeIndex=0,open=0,close=0;
	for(int i=0;i<parenth.size();i++){
		if(parenth[i]=='('){
			open++;
			openIndex+=i;
		}
		else if(parenth[i]==')'){
			close++;
			closeIndex+=i;
		}
	}
	if(closeIndex>openIndex && open==close){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int round;
    cin>>round;
    vector<string> paranthesis;
    vector<string> validParenthesis;
    //getting the strings and adding the already valid ones to the validParenthesis vector
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        paranthesis.push_back(str);
        if(isValid(str)){
        	validParenthesis.push_back(str);
		}
    }
	//making the different variations of the strings and checking if they are valid or not
    for(int i=0;i<round-1;i++){
        for(int j=i+1;j<round;j++){
            string test=paranthesis[i]+paranthesis[j];
            if(isValid(test)){
	        	validParenthesis.push_back(test);
			}
        }
    }
	//sorting the vector by length
    for (int i=1 ;i<validParenthesis.size(); i++)
    {
        string temp = validParenthesis[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < validParenthesis[j].length())
        {
            validParenthesis[j+1] = validParenthesis[j];
            j--;
        }
        validParenthesis[j+1] = temp;
    }
    //printing out the elements of the validParenthesis vector
    for(int i=0;i<validParenthesis.size();i++){
        	cout<<validParenthesis[i]<<endl;
    }
	return 0;
}
