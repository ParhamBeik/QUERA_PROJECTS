#include<iostream>
using namespace std;
int main(){
	int round;
	string newName;
	cin>>newName>>round;
	string name="- kieh?!",mark="?!";
	while(round!=0){
		cout<<name<<"\n";
		name+=mark;
		round--;
	}
	if(newName=="hichkas"){
		cout<<"- kieh!!!";
	}
	else{
		cout<<"Eh "<<newName<<" toee!";
	}
	return 0;
}
