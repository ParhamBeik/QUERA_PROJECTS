#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "Other.h"
#include "Person.h"
#include "Items.h" 

using namespace std;

// Function And Class Method Decleration

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Person::Person(string n) : name(n), level(1), damage(0) {}

void Person::updateLevel() {
    level++;
}

int Person::getLevel() {
    return level;
}

string Person::getName() {
    return name;
}

int Person::getDamage() {
    return damage;
}

int Person::getHealthPoints() {
    return hp.getCurrentHealth();
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Human::Human(string n) : Person(n) {}

Backpack* Human::getBackpack() {
    return &backpack;
}

int Human::getExperience() {
    return exp.getCurrentExp();
}

int Human::getStamina() {
    return stamina.getCurrentStamina();
}

BankAccount* Human::getBankAccount() {
    return &bankAccount;
}

int Human::getMoney() {
    return bankAccount.getBalance();
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Player::Player(string n, string g, int a) : Human(n), age(a), gender(g) {}

int Player::getAge() {
    return age;
}

string Player::getGender() {
    return gender;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Zombie::Zombie(string n, int dmg) : Person(n) {
    damage = dmg;
}

void Zombie::attack() {
    cout << name <<" bites for " << damage << " damage!" << endl;
}

int Zombie::getHealth() {
    return hp.getCurrentHealth();
}

void Zombie::takeDamage(int amount) {
    hp.decreaseHealth(amount);
    if (hp.getCurrentHealth() <= 0) {
        cout << name << " has been defeated!" << endl;
    } else {
        cout << name << " takes " << amount << " damage. Remaining Zombie HP: " << hp.getCurrentHealth() << endl;
    }
}
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*