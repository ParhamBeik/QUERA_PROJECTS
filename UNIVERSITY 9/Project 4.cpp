#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void minify (ifstream& fin, ofstream& fout){
    string minified="";
    string line;
    while(getline(fin,line)){
        for(int i=0;i<line.size();i++){
            if((line[i]>='a' && line[i]<='z')||(line[i] >= 'A' && line[i] <= 'Z')||line[i]=='>'||line[i] =='<'||line[i]=='/'){
                minified+=line[i];
            }
        }
    }
    fout << minified;

}
void prettify (ifstream& fin, ofstream& fout){
    string minified="" , prettified;
    string line;
    while(getline(fin,line)){
        for(int i=0;i<line.size();i++){
            if((line[i]>='a' && line[i]<='z')||(line[i] >= 'A' && line[i] <= 'Z')||line[i]=='>'||line[i] =='<'||line[i]=='/'){
                minified+=line[i];
            }
        }
    }
	fout << prettified;
}
int main() {
    string in , out , func;
    cin >> in >> out >> func;
    
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open( in , ifstream::in);
    outputFile.open( out , ofstream::out);

    try{
        if( !(inputFile.is_open()) ){
            throw string("Input file opening failed!");
        }
        else if( !(outputFile.is_open()) ){
            throw string("Output file opening failed!");
        }
        else if( !(func == "prettify" || func == "minify") ){
            throw string("Invalid command!");
        }

        if(func == "minify"){
            minify(inputFile,outputFile);
            inputFile.close();
            outputFile.close();
        }
        else{
            prettify(inputFile,outputFile);
            inputFile.close();
            outputFile.close();
        }

    }
    catch(string &error){
        cerr << error;
    }
    return 0;
}
