#include<iostream>
#include<string>
using namespace std;

struct Sleep {
    int security;
    string State;
    Sleep* nextLayer;
};

void check(Sleep* node,int round){
	
	bool isAlive[round];
    
	for(int i=round-1;i > -1;i--){
		if(node->security < 3 && node->State == "nightmare"){
			isAlive[i]=false;
		}
		else{
			isAlive[i]=true;
		}
		node = node->nextLayer;
	}

	int count=0;

    for(int i=round-1;i > -1;i--){
    	if(!(isAlive[i])){
    		count++;
		}
	}
	if(count%2==0){ 
		if(count >= round/2){
			cout << "he is dead";
		}
		else{
			cout << "he is still alive";
		}	
	}
	else{
		if(count >= round/2 + 1){
			cout << "he is dead";
		}
		else{
			cout << "he is still alive";
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
    
    check(head,round);
    
    return 0;
}