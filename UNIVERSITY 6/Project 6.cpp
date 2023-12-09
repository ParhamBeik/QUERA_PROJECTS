#include<iostream>
using namespace std;
int main(){
    int count[26];
    for(int i=0;i<26;i++){
        count[i]=0;
    }

    string str;
    cin>>str;

    for(int i=0;i<str.size();i++){
        switch(str[i]){
            case 65:
                count[0]++;
                break;
            case 66:
                count[1]++;
                break;
            case 67:
                count[2]++;
                break;
            case 68:
                count[3]++;
                break;
            case 69:
                count[4]++;
                break;
            case 70:
                count[5]++;
                break;
            case 71:
                count[6]++;
                break;
            case 72:
                count[7]++;
                break;
            case 73:
                count[8]++;
                break;
            case 74:
                count[9]++;
                break;
            case 75:
                count[10]++;
                break;
            case 76:
                count[11]++;
                break;
            case 77:
                count[12]++;
                break;
            case 78:
                count[13]++;
                break;
            case 79:
                count[14]++;
                break;
            case 80:
                count[15]++;
                break;
            case 81:
                count[16]++;
                break;
            case 82:
                count[17]++;
                break;
            case 83:
                count[18]++;
                break;
            case 84:
                count[19]++;
                break;
            case 85:
                count[20]++;
                break;
            case 86:
                count[21]++;
                break;
            case 87:
                count[22]++;
                break;
            case 88:
                count[23]++;
                break;
            case 89:
                count[24]++;
                break;
            case 90:
                count[25]++;
                break;
        }
    }

    for(int i=0;i<26;i++){
        cout<<count[i]<<" ";
    }
    return 0;
}