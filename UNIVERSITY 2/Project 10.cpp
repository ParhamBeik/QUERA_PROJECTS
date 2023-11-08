#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	double a,b,c,delta,squareRootOfDelta,answer1,answer2,answer,minusB;
	cin>>a>>b>>c;
	delta=b*b-4*a*c;
	squareRootOfDelta=sqrt(delta);
	vector<double> listOfAnswersForTheEquation;
	minusB=b-2*b;
	
	if(delta>0){
		answer1=double(minusB+squareRootOfDelta)/double(2*a);
		answer2=double(minusB-squareRootOfDelta)/double(2*a);
		listOfAnswersForTheEquation.push_back(answer1);
		listOfAnswersForTheEquation.push_back(answer2);
		cout<<"there are 2 roots"<<endl;
	}
	else if(delta<0){
		cout<<"there is no root"<<endl;
	}
	else{
		answer=(minusB/2*a);
		listOfAnswersForTheEquation.push_back(answer);
		cout<<"there is 1 root"<<endl;
	}
	
	for(int i=0;i<listOfAnswersForTheEquation.size();i++){
		cout<<listOfAnswersForTheEquation[i]<<endl;
	}
	
	if(delta<=0 ){
		cout<<"It passes through 2 coordinate regions";
	}
	else if(delta>0 && (c/a)>0){
		cout<<"It passes through 3 coordinate regions";
	}
	else if(delta>0 && (c/a)<0){
		cout<<"It passes through 4 coordinate regions";
	}
	
	return 0;
}

