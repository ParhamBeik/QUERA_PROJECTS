#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
	int rows,columns;
	cin>>rows;

	int** table = new int*[rows];
	vector<int> listOfColumns;

	for(int i=0; i<rows ;i++){
		cin>>columns;
		listOfColumns.push_back(columns);
		table[i] = new int[columns];

		for(int j=0; j<columns ;j++){
			int number;
			cin>>number;
			table[i][j] = number;
		}
	}

	string str;
	cin>>str;
	
	int i=0,j=0;

	for(int x=0 ; x<str.size() ; x++){
		//R
		if(str[x]==82){
			j++;
			if(j > listOfColumns[i]){
				i++;
				if(i<rows){
					j=0;
				}
				else{
					i--;
					j--;
				}
			}
		}
		//L
		else if(str[x]==76){
			j--;
			if(j < 0){
				i--;
				if(i>=0){
					j=listOfColumns[i]-1;
				}
				else{
					i++;
					j++;
				}
			}
		}
		//D
		else if(str[x]==68){
			i++;
			if(i<rows){
				if(j>listOfColumns[i]-1){
					j=listOfColumns[i]-1;
				}
			}
			else{
				i--;
			}
		}
		//U
		else if(str[x]==85){
			i--;
			if(i>=0){
				if(j>listOfColumns[i]-1){
					j=listOfColumns[i]-1;
				}
			}
			else{
				i++;
			}
		}
	}

	cout << i << " " << j << " " << table[i][j];
	return 0;
}
