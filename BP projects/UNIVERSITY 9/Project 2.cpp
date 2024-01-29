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
    //READING THE FILES ALL AT ONCE AND OUTPUTING THE RESAULT TO THE RESAULTFILE.JSON
    int counter=0;
    nameFile.open("names.txt", ios::in);
    phoneFile.open("phones.txt", ios::in);
    resaultFile.open("result.json" , ios::out);

    if(phoneFile.is_open() && nameFile.is_open() && resaultFile.is_open()){
    	string var;
        string name , phone;

        //WRITING TO THE RESULT FILE
        resaultFile << "{";
        while(getline(nameFile,name) && getline(phoneFile,phone)){
        	//CHANGING THE +98 PHONE NUMBERS TO 0 PHONE NUMBERS
        	if(phone.size()==13 && phone[0]=='+' && phone[1]=='9' && phone[2]=='8'){
               string test="0";
               for(int i=3;i<phone.size();i++){
                test+=phone[i];
               }
               phone=test;
            }
            //CHECKING IF THE PHONE NUMBER IS NULL OR NOT
            if(!(phone.size()==11 & phone[0]=='0' && phone[1]=='9')){
                phone="null";
            }
            //CHECKING ALL THE POSSIBLE VARIATIONS OF THE NAME AND PHONE NUMBER
            if(phone=="null"){
                if(counter==0){
            	    resaultFile  << endl << "    " << '"' << name << '"' << ": " << phone ;
                }
                else{    
            	    resaultFile << ',' << endl << "    "  << '"' << name << '"' << ": " << phone ;
                }
			}
			else if(phone !="null"){
				if(counter==0){
                    resaultFile << endl << "    " << '"' << name << '"' << ": " << '"' << phone  << '"' ;
                }
                else{
                    resaultFile << ','<< endl << "    " << '"' << name << '"' << ": " << '"' << phone  << '"' ;
                }
			}
            counter++;
        }
        resaultFile << endl << "}";
        phoneFile.close();
        nameFile.close();
        resaultFile.close();
    }
    else{
        cerr << "sth went wrong";
    }

    return 0;
}
