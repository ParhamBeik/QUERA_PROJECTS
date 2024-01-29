#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    fstream DNA1 , DNA2;
    string in,out;
    cin >> in >> out;
    DNA1.open( in , ios::in);
    DNA2.open( out , ios::out);

    try{
        if( !(DNA1.is_open()) ){
            throw string("FASTA file does not exist!");
        }
        int animalCount=0;
        vector<string> animalName;
        vector<string> str;
        vector<string> rest;
        string line , res="";
        while(getline(DNA1,line)){
            int stringSize;
            if(str.size()==0){
            	stringSize=0;
			}
			else{
				stringSize=str[0].size();
			}
            if(line[0]=='>'){
                if(res.size()>0){
                    str.push_back(res);
                    res="";
                }
                //COUNTING ANIMALS
                animalCount++;
                //GETTING THE NAME OF THE ANIMAL
                int index=1;
                string name="";
                while(!(line[index]==' ')){
                    name+=line[index];
                    index++;
                }
                animalName.push_back(name);
            }
            //GETTING THE WHOLE STRING
            else{
                res+=line;
            }
            if(res.size()==stringSize && res!=""){
                str.push_back(res);
            }
        }
        DNA1.close();
        //CHECKING IF THE LENGTH OF THE STRINGS ARE THE SAME
        int stringSize=str[0].size() , index=1;
        while(!(index==str.size())){
            if(!(str[index].size()==stringSize)){
                throw string("The sequences are not the same length!");
            }
            index++;
        }
        //SETTING THE USELESS STRINGS AT THE END TO THE REST
    	int div=stringSize%10;
        //PRINTING OUT THE RESAULT
        DNA2<<" "<<animalCount;
        DNA2<<" "<<stringSize<<endl;

        for(int i=0;i<animalName.size();i++){
            DNA2 << animalName[i];
            for(int k=0;k<11-animalName[i].size();k++){
            	DNA2<<" ";
			}
            for(int j=0;j<str[i].size()-div;j++){
            	if(j%10==9){
            		DNA2<<str[i][j]<<" ";
				}
				else{
					DNA2<<str[i][j];
				}
			} 
			DNA2<<endl;
        }
        DNA2<<endl;
        for(int i=0;i<animalName.size();i++){
            DNA2<<"           ";
            for(int j=str[i].size()-1-div;j<str[i].size();j++){
				DNA2<<str[i][j];
			} 
			DNA2<<endl<<endl;
        }
        DNA2.close();
    }
    catch(string &error){ 
        cerr << error;
    }
    return 0;
}
