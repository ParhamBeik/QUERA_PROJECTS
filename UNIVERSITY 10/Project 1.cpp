#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> allActions;
vector<string> actions;

void Deposit(int &bal,int sum){
    bal+=sum;
    string act1="";
    stringstream ss;
    ss << sum;
    string num = ss.str();
    act1+="You have successfully deposited ";
    act1+=num;
    act1+="$ to your account";

    string act2="";
    act2+="Deposit of ";
    act2+=num;
    act2+='$';

    allActions.push_back(act1);
    actions.push_back(act2);
}

void Withdrawal(int &bal,int sub){
    bal-=sub;

    string act1="";
    stringstream ss;
    ss << sub;
    string num = ss.str();
    act1+="You have successfully withdrawn ";
    act1+=num;
    act1+="$ from your account";
    
    string act2="";
    act2+="Withdrawal of ";
    act2+=num;
    act2+='$';

    allActions.push_back(act1);
    actions.push_back(act2);
}

void Report(){
    allActions.push_back("Report");
}

void Balance(int bal){
    stringstream ss;
    ss << bal;
    string act = ss.str();
    act+='$';
    allActions.push_back(act);
}

struct Costumer{
    string name;
    string email;
    int id;
    int bankBalance;
};

int main(){
    struct Costumer costumer1;
    cin >> costumer1.name >> costumer1.email >> costumer1.id >> costumer1.bankBalance;
    

    string func="";
    do{
        //GETTING THE NAME AND THE FUNCTION
        int number;
        cin >> func;
        if(func=="Deposit" || func=="Withdrawal"){
            cin >> number;
        }
        //CALING THE FUNCTIONS
        if(func=="Balance"){
            Balance(costumer1.bankBalance);
        }
        else if(func=="Deposit"){
            Deposit(costumer1.bankBalance,number);
        }
        else if(func=="Withdrawal"){
            if(number < costumer1.bankBalance){
                Withdrawal(costumer1.bankBalance,number);
            }
            else{
                allActions.push_back("Insufficient Balance!");
            }
        }
        else if(func=="Report"){
            Report();
        }
    }while(func!="-1");

    for(int i=0;i<allActions.size();i++){
        if(allActions[i]!="Report"){
            cout << allActions[i] << endl;
        }
        else{
            for(int j=0;j<actions.size();j++){
                cout << actions[j] << endl;
            }
        }
    }
    return 0;
}