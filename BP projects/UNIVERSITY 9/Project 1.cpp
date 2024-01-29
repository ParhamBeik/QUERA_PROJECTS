#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int round;
    cin>>round;
    int nums[round];
    for(int i=0;i<round;i++){
        cin>>nums[i];
    }
    bool isAbove;
    try{
        if(round>13){
            isAbove=true;
            throw(round-13);
        }
        else if(round<13){
            isAbove=false;
            throw(13-round);
        }
        else{
            int sum=0;
            for(int i=0;i<round;i++){
                sum+=nums[i];
            }
            cout<<sum;
        }
    }
    catch(int num){
        if(isAbove){
            cout<<"tedad " << num << " ta bishtar ast nomokham";
        }
        else{
            cout<<"tedad " << num << " ta kamtar ast nomokham";
        }
    }


    return 0;
}