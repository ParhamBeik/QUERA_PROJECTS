#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int round;
    cin>>round;
    
    vector<int> listOfIndexes;
    vector<int> listOfCharIndexes;
    vector<int> listOfOrderedIndexes;
    
    for(int a=0;a<round;a++){
        string str;
        cin>>str;
        listOfIndexes.clear();
        listOfCharIndexes.clear();
        listOfOrderedIndexes.clear();
        string listOfChars="abcdefghijklmnopqrstuvwxyz";

        for(int i=0;i<str.size();i++){
            if(str[i]!=48){
                listOfIndexes.push_back(str[i]);
                listOfCharIndexes.push_back(i);
            }
        }

        int min=1;
        for(int i=0;i<listOfIndexes.size();i++){
            for(int j=0;j<listOfIndexes.size();j++){
                if(listOfIndexes[j]==min){
                    listOfOrderedIndexes.push_back(listOfIndexes[j]);
                    min++;
                    break;
                }
            }
        }

        for(int i=0;i<listOfIndexes.size();i++){
            cout<<listOfChars[listOfCharIndexes[listOfOrderedIndexes[i]]];
        }
        cout<<" ";
    }
    return 0;
}
