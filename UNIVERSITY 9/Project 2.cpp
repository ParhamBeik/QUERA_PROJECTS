#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int main(){
    fstream nameFile;
    nameFile.open("names.txt" , ios :: in);
    if(nameFile.is_open()){
        string name;
        while(getline(nameFile,name)){

        }
        nameFile.close();
    }
    

    fstream phoneFile;
    phoneFile.open("phones.txt" , ios :: in);
    if(phoneFile.is_open()){
        string phone;
        while(getline(nameFile,phone)){
            
        }
        phoneFile.close();
    }
    return 0;
}