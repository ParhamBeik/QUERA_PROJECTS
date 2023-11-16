#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int HexaToDecimal(string number){
    int sum=0,lengthOfString=number.size();
    for(int i=0;i<number.size();i++){
        switch(number[i]){
            case 48:
                sum+=0*pow(16,lengthOfString-1);
                break;
            case 49:
                sum+=1*pow(16,lengthOfString-1);
                break;
            case 50:
                sum+=2*pow(16,lengthOfString-1);
                break;
            case 51:
                sum+=3*pow(16,lengthOfString-1);
                break;
            case 52:
                sum+=4*pow(16,lengthOfString-1);
                break;
            case 53:
                sum+=5*pow(16,lengthOfString-1);
                break;
            case 54:
                sum+=6*pow(16,lengthOfString-1);
                break;
            case 55:
                sum+=7*pow(16,lengthOfString-1);
                break;
            case 56:
                sum+=8*pow(16,lengthOfString-1);
                break;
            case 57:
                sum+=9*pow(16,lengthOfString-1);
                break;
            case 65:
                sum+=10*pow(16,lengthOfString-1);
                break;
            case 66:
                sum+=11*pow(16,lengthOfString-1);
                break;
            case 67:
                sum+=12*pow(16,lengthOfString-1);
                break;
            case 68:
                sum+=13*pow(16,lengthOfString-1);
                break;
            case 69:
                sum+=14*pow(16,lengthOfString-1);
                break;
            case 70:
                sum+=15*pow(16,lengthOfString-1);
                break;
        }
        lengthOfString--;
    }
    return sum;
}

string DecimalToHexa(int number){
    int copyOfNum=number;
    string num="";
    while(copyOfNum!=0){
        switch(copyOfNum%16){
            case 0:
                num+=48;
                break; 
            case 1:
                num+=49;
                break;
            case 2:
                num+=50;
                break;
            case 3:
                num+=51;
                break;    
            case 4:
                num+=52;
                break;    
            case 5:
                num+=53;
                break;    
            case 6:
                num+=54;
                break;    
            case 7:
                num+=55;
                break;    
            case 8:
                num+=56;
                break;    
            case 9:
                num+=57;
                break;
            case 10:
                num+=65;
                break;
            case 11:
                num+=66;
                break;
            case 12:
                num+=67;
                break;
            case 13:
                num+=68;
                break;
            case 14:
                num+=69;
                break;
            case 15:
                num+=70;
                break;
        }
        copyOfNum/=16;
    }
    int length=num.length();
    for(int i=0;i<length/2;i++){
        swap(num[i],num[length-i-1]);
    }
    return num;
}

int F(int number){
    return ceil(cbrt(pow(number,2))-log2(abs(number))+sin(cosh(cbrt(number)))+exp(atan(number)));
}

int G(int number){
    return floor(pow(pow(F(number*number),3),1.0/4)+(1/number+10));
}

int main(){
    string number,Fnumber,Gnumber;
    cin>>number;
    int number2=HexaToDecimal(number);
    Fnumber=DecimalToHexa(F(number2));
    Gnumber=DecimalToHexa(G(number2));
    cout<<Fnumber<<endl<<Gnumber;
    return 0;
}