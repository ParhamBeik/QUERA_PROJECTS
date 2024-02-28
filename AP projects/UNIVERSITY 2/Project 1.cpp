#include<iostream>
#include<string>

using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person() =default;
        Person(string name,int age) {}
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
        SalesPerson(string name , int age , string job): Person(name , age){}
        virtual void serveCustomer(Person){}

};
class Grocer: public SalesPerson{
    public:
        Grocer(string name, int age, string job): SalesPerson(name, age, job) {}
        void serveCustomer(Person) final{}
};

int main(){

    return 0;
}