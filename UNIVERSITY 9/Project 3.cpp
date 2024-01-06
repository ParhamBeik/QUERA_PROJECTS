#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int round;
    cin>>round;
    vector<string> rightPlate;
    vector<string> FalsePlate;
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        try{
            // CHECKING THE LETTERS OF THE ALPHABET FOR THE CONDITIONS OF THE QUESTION
            if( ((str[2]>'A' && str[2]<'P') || (str[2]>'P' && str[2]<'T') || (str[2]>'T' && str[2]<='Z')) && str.size()==10 && str[6]=='I' && str[7]=='R'){
                int count=0;
                for(int j=0;j<str.size();j++){
                    if(j==9 && str[j]>='0' && str[j]<='9'){
                        count++;
                    }
                    else if(j!=2 && j!=6 && j!=7 && j!=9 && str[j]!='0'){
                        if(str[j]>'0' && str[j]<='9'){
                            count++;
                        }
                    }
                }
                if(count==7){
                    rightPlate.push_back(str);
                }
                else{
                    throw string(str);
                }
            }
            else{
                throw string(str);
            }
        }
        // HANDLING EXCEPTION
        catch(string &falsePlate){
            FalsePlate.push_back(falsePlate);
        }
    }
    
    int index=1;
    while (index>0){
		index=0;
        for(int i=0; i+1 < rightPlate.size(); i++){
            if(stoi(rightPlate[i].substr(0 , 2)) < stoi(rightPlate[i+1].substr(0 , 2))){
                index++;
                string str;
                str = rightPlate[i];
                rightPlate[i] = rightPlate[i+1];
                rightPlate[i+1] = str;
            }
        }
    }
    
    //PRINTING THE VALUE FOR THE RIGHT PLATES BY ORDER
    cout<<"True vehicle registration plate numbers list:"<<endl;
    for(int i=0;i<rightPlate.size();i++){
        cout<<rightPlate[i]<<endl;
    }
    //PRINTING THE VALUE FOR THE RIGHT PLATES BY ORDER
    cout<<"False vehicle registration plate numbers list:"<<endl;
    for(int i=0;i<FalsePlate.size();i++){
        cout<<FalsePlate[i]<<endl;
    }
    return 0;
}