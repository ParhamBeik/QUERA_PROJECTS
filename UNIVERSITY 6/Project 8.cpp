#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int list[str.size()],count1=0,count3=0;
    for(int i=0;i<str.size();i++){
        // F
        if(str[i]==70){
            list[i]=1;
            count1++;
        }
        // W
        else if(str[i]==87){
            list[i]=2;
        }
        // I
        else if(str[i]==73){
            list[i]=3;
            count3++;
        }
        // E
        else if(str[i]==69){
            list[i]=4;
        }
    }
	
	bool check[str.size()-1];
	for(int i=0;i<str.size()-1;i++){
		check[i]=false;
	}
	
    for(int i=0;i<str.size();i++){
        int num=list[i];
        for(int j=i+1;j<str.size();j++){
            if(num==1){
                if(list[j]==2){
                    check[i]=true;
                    break;
                }
                else if(list[j]==1){
                    check[i]=false;
                    break;
                }
            }
            else if(num==3){
                if(list[j]==4){
                    check[i]=true;
                    break;
                }
                else if(list[j]==3){
                    check[i]=false;
                    break;
                }
            }
        }
    }

    int sum=0;
    for(int i=0;i<str.size()-1;i++){
        if(check[i]){
            sum++;
        }
    }

    if(sum==count1+count3){
        cout<<"compile shod";
    }
    else{
        cout<<"syntax error";
    }
    return 0;
}
