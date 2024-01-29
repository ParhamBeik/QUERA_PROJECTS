#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> listOfNum;
    string element;
	int index=0 , isTrue = 0;
	while (isTrue<2)
	{
		cin>>element;
		listOfNum.push_back(element);
		if (element == "-1")
			isTrue++;
		else
		    isTrue = 0;
	}

	listOfNum.erase(listOfNum.end() - 2 , listOfNum.end());

    for (int i = listOfNum.size()-1; i > -1 ; i--)
	{
		if(listOfNum[i] != "-1")
		    cout<<listOfNum[i]<<" ";
		else
		    cout<<endl;
	}
	
    return 0;
}
