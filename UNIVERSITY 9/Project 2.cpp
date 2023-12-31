#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    fstream phoneFile;
    fstream nameFile;
    fstream resaultFile;

    phoneFile.open("phones.txt", ios::in);
    nameFile.open("names.txt", ios::in);
    resaultFile.open("resault.json" , ios::out);

    if(phoneFile.is_open() && nameFile.is_open() && resaultFile.is_open()){
    	string var;
    	int count=0;
    	while(getline(nameFile,var)){
    		count++;
		}
    	
    	int counter=0;
        string name , phone;
        resaultFile << "{" << endl;
        while(getline(nameFile,name) && getline(phoneFile,phone)){
        	
        	if(phone.size()==13 && phone[0]==43 && phone[1]==57 && phone[2]==56){
               string test="0";
               for(int i=3;i<phone.size();i++){
                test+=phone[i];
               }
               phone=test;
            }
            if(phone.size()!=11 || phone[0]!=48 || phone[1]!=57){
                phone="null";
            }
            
            if(phone=="null" && counter!=count ){
            	resaultFile << "    " << '"' << name << '"' << ": " << phone << ',' << endl;
			}
			else if(counter!=count){
				resaultFile << "    " << '"' << name << '"' << ": " << '"' << phone << '"' << ',' << endl;
			}
			else{
				resaultFile << "    " << '"' << name << '"' << ": " << '"' << phone << '"' << endl;
			}
			counter++;
        }
        resaultFile << "}";
        phoneFile.close();
        nameFile.close();
        resaultFile.close();
    }

    resaultFile.open("resault.json" , ios::in);

    if(resaultFile.is_open()){
        string res;
        while(getline(resaultFile,res)){
            cout << res <<endl;
        }
        resaultFile.close();
    }

    return 0;
}
