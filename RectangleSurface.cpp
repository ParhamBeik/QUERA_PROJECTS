#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int rounds;
    cin>>rounds;
    vector<int> listOfNums;
    for(int i=0;i<rounds;i++){
        int num;
        cin>>num;
        listOfNums.push_back(num);
    }
    vector<int> listOfSurfaces;
    for(int x=0;x<listOfNums.size();x++){
        long long int element=listOfNums[x],count=0,surface=0;
        for(int y=0;y<listOfNums.size();){
            while(listOfNums[y]>=element){
                y++;
                count++;
                break;
            }
        }
        surface=count*element;
        listOfSurfaces.push_back(surface);
    }
    for(int x=listOfNums.size()-1;x<-1;x--){
        long long int element=listOfNums[x],count=0,surface=0;
        for(int y=listOfNums.size()-1;y<-1;){
            while(listOfNums[y]>=element){
                y--;
                count++;
                break;
            }
        }
        surface=count*element;
        listOfSurfaces.push_back(surface);
    }
    
    cout<<*max_element(listOfSurfaces.begin(), listOfSurfaces.end());

    return 0;
}