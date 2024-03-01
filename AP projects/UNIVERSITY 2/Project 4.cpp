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
//---------------------------------------------------------------------------------------------------

int main(){
    string address;
    int postalCode;
    double rentalFee;
    string ownerName;
    string ownerJob;
    int ownerAge;

    Store store;
    SalesPerson* owner = new SalesPerson(ownerName, ownerAge, ownerJob);

    getline(cin,address);
    cin >> postalCode >> rentalFee >> ownerName >> ownerAge >> ownerJob;

    owner->setName(ownerName);
    owner->setAge(ownerAge);

    store.setAddress(address);
    store.setPostalCode(postalCode);
    store.setRentalFee(rentalFee);
    store.setOwner(owner);

    cout << "Your grocery is:" << endl;
    cout << "- Address: " << store.getAddress() << endl;
    cout << "- Postal Code: " << store.getPostalCode() << endl;
    cout << "- Rental Fee: " << store.getRentalFee() << endl;
    cout << "- Owner: " << store.getOwner()->getName() << ", "<< store.getOwner()->getAge() << endl; 

    delete owner;

    return 0;
}
