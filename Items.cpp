#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "Items.h" 
#include "Other.h"
#include "Person.h"

using namespace std;

// Function And Class Method Decleration

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Items::Items(string n,int p,string t):name(n),price(p),type(t){}

bool Items::operator==(const Items& other) const {
    return (name == other.name);
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Permanent::Permanent(string n,int p,string t,int e):Items(n,p,t),exp(e){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

WarmWeapon::WarmWeapon(string n,int p,int x,int e):Permanent(n,p,"Warm Weapon",e),wwa(x){
    WarmWeapon::addToVectors();
}

void WarmWeapon::showItems(){
    for(auto& i : shop_items_permanent_warmweapon){
        cout << i << endl;
    }
}

void WarmWeapon::buy(Player& player){
    BankAccount *creditcard=player.getBankAccount();

    if(creditcard->withdraw(price)){
        cout << "Item bought successfully!\n";
        player.getBackpack()->addWarmWeaponItem(*this);
        cout<<"Item added to your backpack!\n";
        player.exp.increaseExp(exp);
        cout<<"EXP increased!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void WarmWeapon::addToVectors(){
    shop_items_permanent_warmweapon.push_back(this);
    shop_items_permanent.push_back(this);
    shop_items.push_back(this);
}

void WarmWeapon::Attack(Human attacker, Human attacked){
    double staminaFactor = 0.3;
    double weaponLevelFactor = 1.0;
    double playerLevelFactor = 0.8;

    srand(time(nullptr));
    int baseDamage = rand() % 10 + 1;
    int damage = baseDamage + (attacker.stamina.getCurrentStamina() * staminaFactor) + (wwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    attacker.stamina.decreaseStamina(10*wwa.getCurrentSkill());
    attacked.hp.decreaseHealth(damage);

    if(static_cast<Player*>(&attacker)){
        Player *p=static_cast<Player*>(&attacker);
        p->exp.setCurrentExp(0,damage,10*wwa.getCurrentSkill());
    }
    else{
        Player *p=static_cast<Player*>(&attacked);
        p->exp.setCurrentExp(damage,0,0);
    }
}

ostream& operator<<(ostream& os,WarmWeapon& obj){
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\tlvl "<<obj.wwa.getCurrentSkill()<<"\t(+"<<obj.exp<<"EXP)\tprice : "<<obj.price<<"$";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

ColdWeapon::ColdWeapon(string n,int p,int x,int e):Permanent(n,p,"Cold Weapon",e),cwa(x){
    ColdWeapon::addToVectors();
}

void ColdWeapon::showItems(){
    for (auto& i : shop_items_permanent_coldweapon){
        cout << i << endl;
    }
}

void ColdWeapon::buy(Player& player){
    BankAccount *creditcard=player.getBankAccount();

    if(creditcard->withdraw(price)){
        cout << "Item bought successfully!\n";
        player.getBackpack()->addColdWeaponItem(*this);
        cout<<"Item added to your backpack!\n";
        player.exp.increaseExp(exp);
        cout<<"EXP increased!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void ColdWeapon::addToVectors(){
    shop_items_permanent_coldweapon.push_back(this);
    shop_items_permanent.push_back(this);
    shop_items.push_back(this);
}

void ColdWeapon::Attack(Human attacker, Human attacked){
    double staminaFactor = 0.3;
    double weaponLevelFactor = 1.0;
    double playerLevelFactor = 0.8;

    srand(time(nullptr));
    int baseDamage = rand() % 10 + 1;
    int damage = baseDamage + (attacker.stamina.getCurrentStamina() * staminaFactor) + (cwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    attacker.stamina.decreaseStamina(10*cwa.getCurrentSkill());
    attacked.hp.decreaseHealth(damage);

    if(static_cast<Player*>(&attacker)){
        Player *p=static_cast<Player*>(&attacker);
        p->exp.setCurrentExp(0,damage,10*cwa.getCurrentSkill());
    }
    else{
        Player *p=static_cast<Player*>(&attacked);
        p->exp.setCurrentExp(damage,0,0);
    }
}

ostream& operator<<(ostream& os,ColdWeapon& obj){
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\tlvl "<<obj.cwa.getCurrentSkill()<<"(+"<<obj.exp<<"EXP)\tprice : "<<obj.price<<"$";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Throwable::Throwable(string n,int p,int x,int e):Items(n,p,"Throwable Weapon"),twa(x),exp(e){
    Throwable::addToVectors();
}

void Throwable::showItems(){
    for (auto& i : shop_items_throwable){
        cout << i << endl;
    }
}

void Throwable::buy(Player& player,int quantity){
    BankAccount *creditcard=player.getBankAccount();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        player.getBackpack()->addThrowableItem(*this, quantity);
        cout<<"Item added to your backpack!\n";
        player.exp.increaseExp(exp*quantity);
        cout<<"EXP increased!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void Throwable::addToVectors(){
    shop_items_throwable.push_back(this);
    shop_items.push_back(this);
}

void Throwable::Throw(Human attacker, Human attacked){
    
}

ostream& operator<<(ostream& os,Throwable& obj) {
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\tlvl "<<obj.twa.getCurrentSkill()<<"(+"<<obj.exp<<"EXP)\tprice : "<<obj.price<<"$ (each)";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Medicine::Medicine(string n,int p,int h):Items(n,p,"Medicine"),heal(h){
    Medicine::addToVectors();
}

void Medicine::showItems(){
    for (auto& i : shop_items_medicine){
        cout << i << endl;
    }
}

void Medicine::buy(Player& player,int quantity){
    BankAccount *creditcard=player.getBankAccount();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        player.getBackpack()->addMedicineItem(*this, quantity);
        cout<<"Item added to your backpack!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void Medicine::addToVectors(){
    shop_items_medicine.push_back(this);
    shop_items.push_back(this);
}

void Medicine::use(Player& player){
    player.hp.increaseHealth(heal);
    player.getBackpack()->useMedicineItemCount(*this, 1);
}

ostream& operator<<(ostream& os,Medicine& obj) {
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\theal : +"<<obj.heal<<"HP"<<"\tprice : "<<obj.price<<"$ (each)";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Food::Food(string n,int p,int s):Items(n,p,"Food"),strength(s){
    Food::addToVectors();
}

void Food::showItems(){
    for (auto& i : shop_items_food){
        cout << i << endl;
    }
}

void Food::buy(Player& player,int quantity){
    BankAccount *creditcard=player.getBankAccount();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        player.getBackpack()->addFoodItem(*this, quantity);
        cout<<"Item added to your backpack!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void Food::addToVectors(){
    shop_items_food.push_back(this);
    shop_items.push_back(this);
}

void Food::use(Player& player){
    player.stamina.increaseStamina(strength);
    player.getBackpack()->useFoodItemCount(*this, 1);
}

ostream& operator<<(ostream& os,Food& obj) {
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\theal : +"<<obj.strength<<"STM"<<"\tprice : "<<obj.price<<"$ (each)";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*