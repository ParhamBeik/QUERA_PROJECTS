#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int num;
    cin>>num;
    //making the sequence of numbers for the star lines between each shape
    int number=2;
    vector<int> list;
    while(number<=num){
        list.push_back(pow(2,number));
        number++;
    }
    
    //making the shape for one
    if(num==1){   
        cout<<"*"<<endl<<"* *"<<endl<<"  *";
    }
    //making the shape for the rest2
    else{   
        cout<<"*"<<endl<<"* *"<<endl<<"  *"<<endl;
		
		int number=1,index=0;
		
		for(int x=0;x<list.size();x++){
			for(int y=0;y<list[index];y++){
				cout<<"* ";
			}
			cout<<endl;

		    if(x!=list.size()-1){
		    	for(int j=0;j<4*number;j++){
			    	cout<<" ";
			    }
			    cout<<"*"<<endl;
			    for(int z=0;z<4*number;z++){
					cout<<" ";
			    }
			    cout<<"* *"<<endl;
			    for(int x=0;x<4*number;x++){
			    	cout<<" ";
				}
			    cout<<"  *"<<endl;
			}
		    number++;
		    index++;
    	}
//    	number=1,index=0;
//		
//		for(int x=0;x<list.size();x++){
//			
//			for(int j=0;j<4*number;j++){
//				cout<<" ";
//			}
//			cout<<"*"<<endl;
//			for(int z=0;z<4*number;z++){
//				cout<<" ";
//			}
//			cout<<"* *"<<endl;
//			for(int x=0;x<4*number;x++){
//				cout<<" ";
//			}
//			cout<<"  *"<<endl;
//			
//			if(x!=list.size()-1){
//				for(int j=0;j<pow(2,number+2);j++){
//					cout<<" ";
//				}
//				for(int y=0;y<list[index];y++){
//					cout<<"* ";
//				}
//			}
//			cout<<endl;
//		    number++;
//		    index++;
//    	}
//    	
    }
    return 0;
}
