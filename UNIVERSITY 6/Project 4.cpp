#include<iostream>
#include<string>
using namespace std;
int main(){
    string colors;
    cin>>colors;
    
    int num;
    cin>>num;
    
    int count[colors.size()];
    
    for(int i=0;i<colors.size();i++){
        count[i]=0;
    }
    
    for(int i=0;i<num;i++){
        string bowl;
        cin>>bowl;
        for(int j=0;j<colors.size();j++){
            for(int k=0;k<bowl.size();k++){
                if(bowl[k]==colors[j]){
                    count[j]++;
                }
            }
        }
    }

    int sum=0;
    for(int i=0;i<colors.size();i++){
        sum+=count[i];
    }

    char variable;
    cin>>variable;
	
    double probability=0;
    
    for(int i=0;i<colors.size();i++){
        if(variable==colors[i]){
            probability=(double)count[i]/(double)sum;
        }
    }
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);
    cout<<probability;

    return 0;
}
