#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int rounds;
    cin>>rounds;
    vector<int> listOfNums;
    for(int i=0;i<rounds;i++){
        int num;
        cin>>num;
        listOfNums.push_back(num);
    }
    sort(listOfNums.begin(), listOfNums.end());
    vector<int> listOfSurfaces;
    for(int x=0;x<listOfNums.size();x++){
        int element=listOfNums[x],count=0,surface=0;
        for(int y=0;y<listOfNums.size();y++){
            if(listOfNums[y]>=element){
                count++;
            }
        }
        surface=count*element;
        listOfSurfaces.push_back(surface);
    }
    
    cout<<*max_element(listOfSurfaces.begin(), listOfSurfaces.end());

    return 0;
}