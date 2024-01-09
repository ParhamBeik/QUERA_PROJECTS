#include<iostream>
#include<string>
using namespace std;

struct Sleep {
    int security;
    string State;
    Sleep* nextLayer;
};

bool check(Sleep* node,int round){
	
	bool isAlive[round];
    
	for(int i=0;i<round;i++){
		if(node->security <= 2 && node->State == "nightmare"){
			isAlive[i]==false;
		}
		else{
			isAlive[i]=true;
		}
		node = node->nextLayer;
	}

	int count=0;

    for(int i=0;i<round;i++){
    	if(!(isAlive[i])){
    		count++;
		}
	}

	if(count%2==0){
		if(count >= round/2){
			return false;
		}
		else{
			return true;
		}	
	}
	else{
		if(count >= round/2 + 1){
			return false;
		}
		else{
			return true;
		}	
	}
}

int main(){
	int round;
    cin >> round;
    Sleep* head = new Sleep();
    Sleep* temp = new Sleep();

    head=nullptr;
    temp=nullptr;

    for(int i=0;i<round;i++){
        int level;
        string mode;
        cin >> level >> mode;
        Sleep* temp = new Sleep();
        temp->security = level;
        temp->State = mode;
        temp->nextLayer = head;
        head = temp;
    }
    
    for(int i=0;i<round;i++){
    	
	}
    bool isAlive = check(head,round);
   
    if(isAlive){
   		cout << "he is still alive";
	}
	else{
		cout << "he is dead";
	}
    
    return 0;
}