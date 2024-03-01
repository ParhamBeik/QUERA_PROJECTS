#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person() = default;
        Person(string name,int age) {
            this->age = age;
            this->name = name;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        void setName(string newName){
            this->name = newName;
        }
        void setAge(int newAge){
            this->age = newAge;
        }
};

class SalesPerson : public Person {
    protected:
        string job;
    public:
        SalesPerson(string name , int age , string job): Person(name , age){
            this->job = job;
        }
        virtual void serveCustomer(Person customer){
            cout << "Hello, " << customer.getName() << "! What can I do for you?" << endl;
        }
};

class Grocer: public SalesPerson{
    public:
        Grocer(string name, int age, string job): SalesPerson(name, age, job) {}
        void serveCustomer(Person customer) final{
            cout << "Hello, " << customer.getName() << "! What fruit do you want to buy?" << endl;
        }
};

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

class SliceableFruit : public Fruit{
    protected:
        SliceableFruit() = default;
    public:
        bool isSliced = false;

        SliceableFruit(string name , int price , double calories , float weight) : Fruit(name,price,calories,weight){}

        virtual SliceableFruit* slice(int slices) = 0;
};

class Apple : public SliceableFruit {
    private:
        string color;
        Apple() = default;

    public:
        Apple(string color){
            this->color = color;
        }
        Apple(string name , int price , double calories , float weight , string color) : SliceableFruit(name,price,calories,weight){
            this->color = color;
        }
        string getColor(){
            return color;
        }
        SliceableFruit* slice(int slices) override {
            Apple* newApples = new Apple[slices];
            for(int i = 0; i < slices; i++){
                Apple newApple(this->name, this->price/slices, this->calories/slices, this->weight/slices, this->color);
                newApples[i] = newApple;
            }
            return newApples;
        }
};


class PeelableFruit : public Fruit{
    protected:
        PeelableFruit() = default;
    public:
        bool isPeeled = false;
        PeelableFruit(string name , int price , double calories , float weight): Fruit(name,price,calories,weight){}
        virtual void peel() = 0;
};

class Banana : public PeelableFruit {
    private:
        string originCountry;
    public:
        Banana(string originCountry){
            this->originCountry = originCountry;
        }
        Banana(string name , int price , double calories , float weight , string originCountry): PeelableFruit(name,price,calories,weight){
            this->originCountry = originCountry;
        }
        string getOriginCounrty(){
            return originCountry;
        }
        void peel() override{
            this->isPeeled = true;
        }
};

//---------------------------------------------------------------------------------------------------
class Building {
    private:
        string address;
        int postalCode;
    public:
        string getAddress(){
            return address;
        }
        int getPostalCode(){
            return postalCode;
        }
        void setAddress(string newAddress){
            this->address = newAddress;
        }
        void setPostalCode(int newPostalCode){
            this->postalCode = newPostalCode;
        }
};
class Store : public Building {
    private:
        SalesPerson* Owner;
        double rentalFee;
    public:
        SalesPerson* getOwner(){
            return Owner;
        }
        double getRentalFee(){
            return rentalFee;
        }
        void setOwner(SalesPerson* newOwner){
            this->Owner = newOwner;
        }
        void setRentalFee(double newRentalFee){
            this->rentalFee = newRentalFee;
        }
};
class Grocery : public Store {
    private:
        vector<Fruit*> fruits;
    public:
        vector<Fruit*> getFruits(){
            return fruits;
        }
        void addFruit(Fruit* fruit){
            fruits.push_back(fruit);
        }
        Fruit* buyFruit(Fruit fruit){
            for(auto &f : fruits){
                if(*f == fruit){
                    return f;
                }
            }
            return nullptr;
        }
        void operator+=(Fruit* fruit){
            addFruit(fruit);
        }
};
//---------------------------------------------------------------------------------------------------

int main(){
    Grocery grocery;
    SalesPerson* owner = new SalesPerson("Herbod", 20, "Businessman");
    grocery.setOwner(owner);

    int count;
    cin >> count;
    for(int i=0;i < count;i++){
        string name;
        cin >> name;
        if(name == "Banana"){
            cin >> name;
            int price;
            double calories;
            float weight;
            string originCountry;
            cin >> originCountry >> price >> calories >> weight;
            Banana banana(name , price , calories , weight , originCountry);
            grocery.addFruit(&banana);
        }
        else{
            cin >> name;
            int price;
            double calories;
            float weight;
            string color;
            cin >> color >> price >> calories >> weight;
            Apple apple(name , price , calories , weight , color);
            grocery.addFruit(&apple);
        }
    }
    
    return 0;
}