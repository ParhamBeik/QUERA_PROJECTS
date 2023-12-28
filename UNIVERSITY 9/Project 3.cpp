#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const string& s1, const string& s2) {
    return s1.substr(s1.size() - 2) > s2.substr(s2.size() - 2);
}
int main(){
    int round;
    cin>>round;
    vector<string> rightPlate;
    vector<string> FalsePlate;
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        try{
            if( ((str[2]>65 && str[2]<80) || (str[2]>80 && str[2]<84) || (str[2]>84 && str[2]<91)) && str.size()==10 && str[6]==73 && str[7]==82){
                int count=0;
                for(int j=0;j<str.size();j++){
                    if(j==9 && str[j]>47 && str[j]<58){
                        count++;
                    }
                    else if(j!=2 && j!=6 && j!=7 && j!=9 && str[j]!=48){
                        if(str[j]>48 && str[j]<58){
                            count++;
                        }
                    }
                }
                if(count==7){
                    rightPlate.push_back(str);
                }
                else{
                    throw(str);
                }
            }
            else{
                throw(str);
            }
        }
        catch(string falseName){
            FalsePlate.push_back(falseName);
        }
    }

    cout<<"True vehicle registration plate numbers list:"<<endl;
    sort(rightPlate.begin(), rightPlate.end(), compare);
    for(const auto& s:rightPlate){
        cout << s << endl;
    }
    cout<<"False vehicle registration plate numbers list:"<<endl;
    for(int i=0;i<FalsePlate.size();i++){
        cout<<FalsePlate[i]<<endl;
    }
    return 0;
}