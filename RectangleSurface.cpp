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
    int vectorSize=listOfNums.size();

    for(int i=0;i<vectorSize;i++){
        int place , forwardPlace , backwardPlace , side , surface ;
        place=i;
        forwardPlace=i;
        backwardPlace=i;
        side=-1;
        surface=0;
        while(listOfNums[place]<=listOfNums[forwardPlace] && forwardPlace<vectorSize){
            side++;
            forwardPlace++;
        }
        while(listOfNums[place]<=listOfNums[backwardPlace] && backwardPlace>=0){
            side++;
            backwardPlace--;
        }
        surface=side*listOfNums[place];
        listOfSurfaces.push_back(surface);
    }
    
    cout<<*max_element(listOfSurfaces.begin(), listOfSurfaces.end());

    return 0;
}
