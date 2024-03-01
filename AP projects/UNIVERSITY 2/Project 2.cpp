#include<iostream>
#include<string>
#include<vector>

using namespace std;

//---------------------------------------------------------------------------------------------------
class Fruit {
    protected:
        string name;
        int price = 0;
        double calories = 0.0;
        float weight = 0.0f;
        Fruit() = default;
    public:
        Fruit(string name){
            this->name = name;
        }
        Fruit(string name , int price , double calories , float weight){
            this->name = name;
            this->price = price;
            this->calories = calories;
            this->weight = weight;
        }
        string getName(){
            return name;
        }
        int getPrice(){
            return price;
        }
        double getCalories(){
            return calories;
        }
        float getWeight(){
            return weight;
        }
        bool operator==(Fruit other){
            return this->name == other.name;
        }
};
//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------

int main(){
    string name;
    int price;
    double calories;
    float weight;
    cin >> name >> price >> calories >> weight;
    Fruit fruit(name , price , calories , weight);
    cout << "Your fruit is:" << endl;
    cout << "- Name: " << fruit.getName()<< endl;
    cout << "- Price: " << fruit.getPrice()<< endl;
    cout << "- Calories: " << fruit.getCalories()<< endl;
    cout << "- Weight: " << fruit.getWeight()<< endl;
    return 0;
}