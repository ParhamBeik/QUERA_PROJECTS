#include<iostream>
#include<cmath>
using namespace std;

double CalculateVolume(double radius){
	float pi=3.14;
    return (4*pow(radius,3)*pi)/3;
}

double CalculateVolume(double length,double width,double height){
    return length*width*height;
}

double CalculateVolume(double radius,double height){
	float pi=3.14;
    return pi*pow(radius,2)*height;
}


int main(){
    int number;
    double radius,length,width,height;
    do{
        cout<<"Choose a shape to calculate the volume:"<<endl;
        cout<<"1. Sphere"<<endl;
        cout<<"2. Rectangular Prism"<<endl;
        cout<<"3. Cylinder"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice (1/2/3/4): "<<endl;
        cin>>number;
        switch(number){
            case (1):
                cin>>radius;
                break;
            case (2):
                cin>>length>>width>>height;
                break;
            case (3):
                cin>>radius>>height;
                break;        
        }
        switch(number){
            case (1):
                cout<<endl<<"Volume of the sphere:"<<"\t"<<CalculateVolume(radius)<<endl;
                break;
            case (2):
                cout<<endl<<"Volume of the rectangular prism:"<<"\t"<<CalculateVolume(length,width,height)<<endl;
                break;
            case (3):
                cout<<endl<<"Volume of the cylinder:"<<"\t"<<CalculateVolume(radius,height)<<endl;
                break;       
            case (4):
                cout<<endl<<"Exiting the program.";
                exit(0);
            default:
                cout<<endl<<"Invalid choice. Please enter 1, 2, 3, or 4."<<endl; 
        }
    }
    while(number!=4);
    return 0;
}
