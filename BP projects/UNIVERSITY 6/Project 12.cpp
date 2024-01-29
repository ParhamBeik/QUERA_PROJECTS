#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int round;
    cin>>round;
    vector<char> list;
    int min=1;
    int count[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int rank[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<round;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++){
        	char strChar=str[j];
        	list.push_back(strChar);
        	switch(strChar){
        		case 'a':
        			if(i==0){
        				rank[0]=min;
        				min++;
					}
        			count[0]++;
        			break;
        		case 'b':
        			if(i==0){
        				rank[1]=min;
        				min++;
					}
        			count[1]++;
        			break;
				case 'c':
					if(i==0){
        				rank[2]=min;
        				min++;
					}
        			count[2]++;
        			break;
				case 'd':
					if(i==0){
        				rank[3]=min;
        				min++;
					}
        			count[3]++;
        			break;
				case 'e':
					if(i==0){
        				rank[4]=min;
        				min++;
					}
        			count[4]++;
        			break;
				case 'f':
					if(i==0){
        				rank[5]=min;
        				min++;
					}
        			count[5]++;
        			break;
				case 'g':
					if(i==0){
        				rank[6]=min;
        				min++;
					}
        			count[6]++;
        			break;
				case 'h':
					if(i==0){
        				rank[7]=min;
        				min++;
					}
        			count[7]++;
        			break;
				case 'j':
					if(i==0){
        				rank[8]=min;
        				min++;
					}
        			count[8]++;
        			break;
				case 'i':
					if(i==0){
        				rank[9]=min;
        				min++;
					}
        			count[9]++;
        			break;
				case 'k':
					if(i==0){
        				rank[10]=min;
        				min++;
					}
        			count[10]++;
        			break;
				case 'l':
					if(i==0){
        				rank[1]=min;
        				min++;
					}
        			count[11]++;
        			break;
				case 'm':
					if(i==0){
        				rank[12]=min;
        				min++;
					}
        			count[12]++;
        			break;	
				case 'n':
					if(i==0){
        				rank[13]=min;
        				min++;
					}
        			count[13]++;
        			break;		
				case 'o':
                    if(i==0){
                        rank[14]=min;
                        min++;
                    }
        			count[14]++;
        			break;	
				case 'p':
                    if(i==0){
                        rank[15]=min;
                        min++;
                    }
        			count[15]++;
        			break;	
				case 'q':
                    if(i==0){
                        rank[16]=min;
                        min++;
                    }
        			count[16]++;
        			break;	
				case 'r':
                    if(i==0){
                        rank[17]=min;
                        min++;
                    }
        			count[17]++;
        			break;	
				case 's':
                    if(i==0){
                        rank[18]=min;
                        min++;
                    }
        			count[18]++;
        			break;	
				case 't':
                    if(i==0){
                        rank[19]=min;
                        min++;
                    }
        			count[19]++;
        			break;
        		case 'u':
                    if(i==0){
                        rank[20]=min;
                        min++;
                        }
        			count[20]++;
        			break;
        		case 'v':
                    if(i==0){
                        rank[21]=min;
                        min++;
                    }
        			count[21]++;
        			break;
        		case 'w':
                    if(i==0){
                        rank[22]=min;
                        min++;
                    }
        			count[22]++;
        			break;
        		case 'x':
                    if(i==0){
                        rank[23]=min;
                        min++;
                    }
        			count[23]++;
        			break;
        		case 'y':
                    if(i==0){
                        rank[24]=min;
                        min++;
                    }
        			count[24]++;
        			break;
        		case 'z':
                    if(i==0){
                        rank[25]=min;
                        min++;
                    }
        			count[25]++;
        			break;
			}
		}
    }

    string test="";
    for(int i=0;i<26;i++){
    	if(i==0){
    		if(count[0]==round){
    			test+=97;
			}
		}
		else if(i>0 && count[i]==round && count[i-1]==round){
			test+=i+97;
		}
	}
	for(int i=0;i<26;i++){
		cout<<rank[i]<<" ";
	}

//	string res="";
//    int minimum=1;
//    for(int i=0;i<test.size();i++){
//        int index=0;
//        while(rank[index]!=minimum){
//            index++;
//        }
//        res[i]=index+97;
//        minimum++;
//    }
//    
//	if(res.size()>0){
//		cout<<res;
//	}
//	else{
//		cout<<"-1";
//	}
    return 0;
}
