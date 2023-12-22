#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void removeMin(vector<int>& vect,int size){
    int min=vect[0],minIndex=0;
    for(int i=0;i<size;i++){
        if(vect[i]<min){
            min=vect[i];
            minIndex=i;
        }
    }
    int bucket=vect[vect.size()-1];
    vect[vect.size()-1]=min;
    vect[minIndex]=bucket;
    vect.pop_back();
}
void removeMax(vector<int>& vect,int size){
    int max=vect[0],maxIndex=0;
    for(int i=0;i<size;i++){
        if(vect[i]>max){
            max=vect[i];
            maxIndex=i;
        }
    }
    int bucket=vect[vect.size()-1];
    vect[vect.size()-1]=max;
    vect[maxIndex]=bucket;
    vect.pop_back();
}
int main(){
    int size;
    cin>>size;
    vector<int> list;

    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        list.push_back(num);
    }

    

    for(int i=0;i<size;i++){
        if(i%2==0){
            removeMax(list,list.size());
        }
        else{
            removeMin(list,list.size());
        }

        sort(list.begin(),list.end());
        
        for(int j=0;j<list.size();j++){
            cout<<list[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}