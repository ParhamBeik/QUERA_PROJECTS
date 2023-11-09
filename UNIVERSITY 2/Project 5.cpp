#include<iostream>
using namespace std;
int main(){
	int day,month,remainder;
	cin>>day>>month;
	if(month<=6 && month>=1){
		remainder=(31*(month-1)+day-1)%7;
	}
	else{
		remainder=(31*5+(month-1)*30+day-3)%7;
	}
	switch(remainder){
		case 0:
			cout<<"Sunday";
			break;
		case 1:
			cout<<"Monday";
			break;
		case 2:
			cout<<"Tuesday";
			break;
		case 3:
			cout<<"Wednesday";
			break;
		case 4:
			cout<<"Thursday";
			break;
		case 5:
			cout<<"Friday";
			break;
		case 6:
			cout<<"Saturday";
			break;
	}
	
	
	return 0;
}
