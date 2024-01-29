#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
using namespace std;
//Returning the Max and the Min
int getMin(int list[],int size){
    int min=list[0];
    for(int i=0;i<size;i++){
        if(list[i]<min){
            min=list[i];
        }
    }
    return min;
}
int getMax(int list[],int size){
    int max=list[0];
    for(int i=0;i<size;i++){
        if(list[i]>max){
            max=list[i];
        }
    }
    return max;
}
//Functions for finding the BMM for the array
int getGCD(int a,int b){
    int resault=min(a,b);
    while(resault > 0){
        if(a%resault==0 && b%resault==0){
            break;
        }
        resault--;
    }
    return resault;
}
//Function for finding the KMM for the array
long long gcd(long long int a,long long int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

long long lcm(int a,int b){
    return ( a / gcd(a,b)) * b;
}
//Main code
int main(){
    //Getting the number of strings
    int round;
    cin>>round;
    string str[round];
    int list[round];
    //Getting the reverse order of the strings of integers
    for(int i=0;i<round;i++){
        string var,res="";
        cin>>var;
        for(int j=var.size()-1;j>-1;j--){
            if(j== var.size()-1 && var[j]==48){
                continue;
            }
            else{
                res+=var[j];
            }
        }
        str[i]=res;
    }
    //Turning those string of integers to the data type int
    for(int i=0;i<round;i++){
        stringstream ss;
        ss << str[i];
        int number;
        ss >> number;
        list[i]=number;
    }
    //Getting the Max and Min of the Array
    int max=getMax(list,round);
    int min=getMin(list,round);
    //Finding the list of BMM for the numbers in the array
    int BMM=getGCD(max,min);
    //Finding the KMM for the numbers in the array
    int KMM=lcm(max,min);
    //Printing out the values of BMM and KMM
    cout << BMM << " " << KMM;

    return 0;
}
