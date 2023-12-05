#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int num;
    cin>>num;

    int number=2;
    vector<int> list;
    while(number<=num){
        list.push_back(pow(2,number));
        number++;
    }
    int i=0;
    while(number>=2){
    	if(i==0){
    		number=number-2;
		}
        list.push_back(pow(2,number));
        number--;
        i++;
    }

    if(num==1){   
        cout<<"*"<<endl<<"* *"<<endl<<"  *";
    }
    else{   
        cout<<"*"<<endl<<"* *"<<endl<<"  *"<<endl;

        int number=1,index=0,copyNum=num;
        for(int i=0;i<(num-1)*2-1;i++){
        	
        	int a=0;
            for(int y=0;y<list[index];y++){
                if(index<=num/2){
                	cout<<"* ";
				}
				else if(index>num/2){
					if(a==0){
						for(int j=0;j<4*(number-1);j++){
		                cout<<" ";
		            	}
					}
		            cout<<"* ";
		            a++;
				}
            }
            
            cout<<endl;

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
            
            index++;
            number++;
        }
    }
    return 0;
}
