#include<iostream>
#include<string>
#include<vector>

using namespace std;
#include <iostream>
#include <string>
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

int main(){
    string costumerName;
    int costumerAge;

    string salesPersonName;
    int salesPersonAge;
    string salesPersonJob;

    cin >> salesPersonName >> salesPersonAge >> salesPersonJob >> costumerName >> costumerAge;

    Person costumer(costumerName , costumerAge);
    SalesPerson salesPerson(salesPersonName , salesPersonAge , salesPersonJob);

    salesPerson.serveCustomer(costumer);
    return 0;
}