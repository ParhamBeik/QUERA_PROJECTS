#ifndef PERSON
#define PERSON

#include<iostream>
#include<string>
#include <memory>
#include <vector>
#include<algorithm>
#include <thread>
#include <chrono>

#include "Other.h"

using namespace std;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Person {
    protected:
        string name;
        int level;
        int damage; 
    public:
        Health hp;
        Person(string n) : name(n), level(1), damage(0) {}
        int getLevel();
        string getName();  // Getter for name
        int getDamage();  // Getter for damage
        int getHealthPoints();  // Getter for health points
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Human : public Person {
private:
    Backpack backpack;
    BankAccount bankAccount;
public:
    Experience exp;
    Stamina stamina;
    Human(string n) : Person(n) {}
    Backpack* getBackpack();
    BankAccount* getBankAccount();
    int getExperience();  // Getter for experience
    int getStamina();  // Getter for stamina
    int getMoney();  // Getter for money
    void updateLevel();  // Update level method in Human class
    void updateMaximumStamina();  // Update maximum stamina method in Human class
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Player : public Human {
private:
    int age;
    string gender;
public:
    Player(string n, string g, int a) : Human(n), age(a), gender(g) {}
    int getAge();  // Getter for age
    string getGender();  // Getter for gender
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class SmartZombie : public Human {};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Zombie : public Person {
public:
    Zombie(string n , int dmg);
    void attack();
    int getHealth();
    void takeDamage(int amount);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class BasicZombie : public Zombie {};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class AdvZombiee : public Zombie {};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

#endif