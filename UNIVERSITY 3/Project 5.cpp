#include<iostream>
using namespace std;

double CalculateVolume(double radius){
    return (4*radius*radius*radius*3.14)/3;
}

double CalculateVolume(double length,double width,double height){
    return length*width*height;
}

double CalculateVolume(double radius,double height){
    return 3.14*radius*radius*height;
}


int main(){
    int number;
    double radius,length,width,height;
    do{
        cin>>number;
        switch(number){
            case (1):
                cin>>radius;
                break;
            case (2):
                cin>>radius>>length>>width>>height;
                break;
            case (3):
                cin>>radius,height;
                break;        
        }
        cout<<"Choose a shape to calculate the volume:"<<endl;
        cout<<"1. Sphere"<<endl;
        cout<<"2. Rectangular Prism"<<endl;
        cout<<"3. Cylinder"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice (1/2/3/4): "<<endl;
        cout<<number<<endl;
        switch(number){
            case (1):
                cout<<"Volume of the sphere:"<<" "<<CalculateVolume(radius)<<endl;
                break;
            case (2):
                cout<<"Volume of the rectangular prism:"<<" "<<CalculateVolume(length,width,height)<<endl;
                break;
            case (3):
                cout<<"Volume of the cylinder:"<<" "<<CalculateVolume(radius,height)<<endl;
                break;       
            case (4):
                cout<<"Exiting the program.";
                exit(0);
            default:
                cout<<"Invalid choice. Please enter 1, 2, 3, or 4."<<endl; 
        }
    }
    while(number!=4);
    return 0;
}