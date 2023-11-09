#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	int numberOfRounds,index=0;
	string theConversation=" Be to che ";
	cin>>numberOfRounds;
	
	vector<string> listOfNames;
	
	listOfNames.push_back("Akbar :");
	listOfNames.push_back("Asghar :");
	
	vector<string> listOfCharacters;
	
	listOfCharacters.push_back("ke ");
	listOfCharacters.push_back(" ke ");
	listOfCharacters.push_back("be man che");
	listOfCharacters.push_back("be to che");

	for(int x=0;x<numberOfRounds;x++){
		if(index%2==0){
			cout<<listOfNames[0]<<theConversation<<endl;
			if(index==0){
			theConversation+=listOfCharacters[0];
			theConversation+=listOfCharacters[2];
			}
			else{
			theConversation+=listOfCharacters[1];
			theConversation+=listOfCharacters[2];
			}
		 index++;
		}
		else{
			cout<<listOfNames[1]<<theConversation<<endl;
			theConversation+=listOfCharacters[1];
			theConversation+=listOfCharacters[3];
			index++;
		}
	}
	return 0;
}
