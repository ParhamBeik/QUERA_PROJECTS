#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <thread>
#include <chrono>

#include "header.h"

using namespace std;

// Function And Class Method Decleration

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Person::Person(string n) : name(n), level(1){}

void Person :: updateLevel(){
    level++;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Backpack* Human::getBackpack(){
    Backpack *p = &backpack;
    return p;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

BankAccount* Player :: getBankAccount(){
    BankAccount* p = &bankAccount;
    return p;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Health :: Health() : maxHealth(100),currentHealth(100){}

void Health :: decreaseHealth(int damage){
    currentHealth -= damage;
    if(currentHealth <= 0)
        currentHealth = 0;
}
void Health :: increaseHealth (int amount){
    currentHealth += amount;
    if(currentHealth >= maxHealth)
        currentHealth = maxHealth;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Stamina :: Stamina():maximum(100),currentStamina(100){}

void Stamina :: decreaseStamina(int amount) {
    currentStamina -= amount;
    if (currentStamina < 0)
        currentStamina = 0;
}
void Stamina :: increaseStamina(int amount) {
    currentStamina += amount;
    if ( currentStamina > maximum)
        currentStamina = maximum;
}
void Stamina :: updateMaximumStamina(){
    maximum+=100;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Experience :: Experience(Human *h):humanObj(h),maximum(100),currentExp(0){}

void Experience :: updateMaximum(){
    maximum+=50;
}
void Experience :: setCurrentExp(int selfDamage,int enemyDamage,int usedStamina){
    currentExp+=(0.5*selfDamage)+(0.2*enemyDamage)+(0.3*usedStamina);
    if(currentExp>=maximum){
        currentExp=0;
        updateMaximum();
        humanObj->updateLevel();
        humanObj->stamina.updateMaximumStamina();
    }
}
void Experience :: increaseExp(int amount){
    currentExp+=amount;
    if(currentExp>=maximum){
        currentExp=0;
        humanObj->exp.updateMaximum();
        humanObj->updateLevel();
        humanObj->stamina.updateMaximumStamina();
    }
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Skills::Skills(int n,int m):maximum(5),currentSkill(n),upgradePrice(m){}

void Skills::upgradeSkill(BankAccount *creditcard){
    try{
        if(creditcard->getBalance()>=upgradePrice){
            creditcard->withdraw(upgradePrice);
            currentSkill++;
            setUpgradePrice();
        }
        else{
            throw 0;
        }
    }
    catch(int temp){
        cout<<"not enough money!\n";
    } 
}

void Skills::setUpgradePrice(){
    upgradePrice+=10;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

WarmWeaponAbility::WarmWeaponAbility(int n):Skills(n,n*10){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

ColdWeaponAbility::ColdWeaponAbility(int n):Skills(n,n*15){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

ThrowableWeaponAbility::ThrowableWeaponAbility(int n):Skills(n,n*20){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void Backpack :: addFoodItem(const Food& foodItem, int quantity){
    for (auto &item : FoodItems) {
        if (item.first == foodItem) {
            item.second += quantity;
            return;
        }
    }
    FoodItems.push_back(make_pair(foodItem, quantity));
}

void Backpack :: addMedicineItem(const Medicine& medicineItem, int quantity){
    for (auto &item : MedicineItems) {
        if (item.first == medicineItem) {
            item.second += quantity;
            return;
        }
    }
    MedicineItems.push_back(make_pair(medicineItem, quantity));
}

void Backpack :: addThrowableItem(const Throwable& throwableItem, int quantity){
    for (auto &item : ThrowableItems) {
        if (item.first == throwableItem) {
            item.second += quantity;
            return;
        }
    }
    ThrowableItems.push_back(make_pair(throwableItem, quantity));
}

void Backpack :: addWarmWeaponItem(const WarmWeapon& WarmWeaponItem){
    for (const auto &item : WarmWeaponItems) {
        if (item.first == WarmWeaponItem) {
            return;
        }
    }
    WarmWeaponItems.push_back(make_pair(WarmWeaponItem, 1));
}

void Backpack :: addColdWeaponItem(const ColdWeapon& ColdWeaponItem){
    for (const auto &item : ColdWeaponItems) {
        if (item.first == ColdWeaponItem) {
            return;
        }
    }
    ColdWeaponItems.push_back(make_pair(ColdWeaponItem, 1));
}

// *----------------------------------------------------------------*

void Backpack :: removeFoodItem(const Food& foodItem) {
    for (auto it = FoodItems.begin(); it != FoodItems.end(); ) {
        if (it->first == foodItem) {
            it = FoodItems.erase(it);
        } else {
            ++it;
        }
    }
}

void Backpack :: removeMedicineItem(const Medicine& medicineItem) {
    for (auto it = MedicineItems.begin(); it != MedicineItems.end(); ) {
        if (it->first == medicineItem) {
            it = MedicineItems.erase(it);
        } else {
            ++it;
        }
    }
}

void Backpack :: removeThrowableItem(const Throwable& throwableItem) {
    for (auto it = ThrowableItems.begin(); it != ThrowableItems.end(); ) {
        if (it->first == throwableItem) {
            it = ThrowableItems.erase(it);
        } else {
            ++it;
        }
    }
}

void Backpack :: removeWarmWeaponItem(const WarmWeapon& WarmWeaponItem) {
    for (auto it = WarmWeaponItems.begin(); it != WarmWeaponItems.end(); ) {
        if (it->first == WarmWeaponItem) {
            it = WarmWeaponItems.erase(it);
        } else {
            ++it;
        }
    }
}

void Backpack :: removeColdWeaponItem(const ColdWeapon& ColdWeaponItem) {
    for (auto it = ColdWeaponItems.begin(); it != ColdWeaponItems.end(); ) {
        if (it->first == ColdWeaponItem) {
            it = ColdWeaponItems.erase(it);
        } else {
            ++it;
        }
    }
}

// *----------------------------------------------------------------*

int Backpack :: getFoodItemsCount() {
    int total = 0;
    for (const auto& item : FoodItems) {
        total += item.second;
    }
    return total;
}

int Backpack :: getMedicineItemsCount() {
    int total = 0;
    for (const auto& item : MedicineItems) {
        total += item.second;
    }
    return total;
}

int Backpack :: getThrowableItemsCount() {
    int total = 0;
    for (const auto& item : ThrowableItems) {
        total += item.second;
    }
    return total;
}

int Backpack :: getWarmWeaponItemsCount() {
    int total = 0;
    for (const auto& item : WarmWeaponItems) {
        total += item.second;
    }
    return total;
}

int Backpack :: getColdWeaponItemsCount() {
    int total = 0;
    for (const auto& item : ColdWeaponItems) {
        total += item.second;
    }
    return total;
}

// *----------------------------------------------------------------*

int Backpack :: getSpecificFoodItemCount(const Food& specificItem) const {
    int count = 0;                                           
    for (const auto& item : FoodItems) {
        if (item.first == specificItem) {
            count += item.second;
        }
    }
    return count;
}

int Backpack :: getSpecificMedicineItemCount(const Medicine& specificItem) const {
    int count = 0;
    for (const auto& item : MedicineItems) {
        if (item.first == specificItem) {
            count += item.second;
        }
    }
    return count;
}

int Backpack :: getSpecificThrowableItemCount(const Throwable& specificItem) const {
    int count = 0;
    for (const auto& item : ThrowableItems) {
        if (item.first == specificItem) {
            count += item.second;
        }
    }
    return count;
}

int Backpack :: getSpecificWarmWeaponItemCount(const WarmWeapon& specificItem) const {
    int count = 0;
    for (const auto& item : WarmWeaponItems) {
        if (item.first == specificItem) {
            count += item.second;
        }
    }
    return count;
}

int Backpack :: getSpecificColdWeaponItemCount(const ColdWeapon& specificItem) const {
    int count = 0;
    for (const auto& item : ColdWeaponItems) {
        if (item.first == specificItem) {
            count += item.second;
        }
    }
    return count;
}

// *----------------------------------------------------------------*

void Backpack :: clearFoodItems() {
    FoodItems.clear();
}

void Backpack :: clearMedicineItems() {
    MedicineItems.clear();
}

void Backpack :: clearThrowableItems() {
    ThrowableItems.clear();
}

void Backpack :: clearWarmWeaponItems() {
    WarmWeaponItems.clear();
}

void Backpack :: clearColdWeaponItems() {
    ColdWeaponItems.clear();
}

// *----------------------------------------------------------------*

void Backpack :: useFoodItemCount(const Food& specificItem, int quantity) {
    for (auto& item : FoodItems) {
        if (item.first == specificItem) {
            item.second -= quantity;
            if (item.second < 0) item.second = 0;
            break;
        }
    }
}

void Backpack :: useMedicineItemCount(const Medicine& specificItem, int quantity) {
    for (auto& item : MedicineItems) {
        if (item.first == specificItem) {
            item.second -= quantity;
            if (item.second < 0) item.second = 0;
            break;
        }
    }
}

void Backpack :: useThrowableItemCount(const Throwable& specificItem, int quantity) {
    for (auto& item : ThrowableItems) {
        if (item.first == specificItem) {
            item.second -= quantity;
            if (item.second < 0) item.second = 0;
            break;
        }
    }
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

BankAccount :: BankAccount(){
    this->balance = 500;
}
int BankAccount :: getBalance() {
    return balance;
}
void BankAccount :: deposit(int amount) { 
    this->balance += amount;
}
void BankAccount::withdraw(int amount) {
    if (balance >= amount)
        balance -= amount;
    else
        cout << "Insufficient funds" << endl;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Items::Items(string n,int p):name(n),price(p){}

bool Items::operator==(const Items& other) const {
    return name == other.name;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void printWithDelay() {
    int delay_ms = 20;
    string text = "In the land of Westeros, war and tensions among powerful families have always existed. But now, the wrath and uninvited power have cast a harsh shadow over this land. You, a hero, are faced with an important mission. You must navigate through the dangers and immense obstacles ahead and confront the looming threats that menace the land of Westeros.In this journey, you must choose your character. Will Jon Snow, the strong and just commander, seize the fate of the land? Or will you, instead of him, travel with Jaime Lannister, the intelligent knight and seasoned strategist, and overcome all obstacles? Or perhaps with Daenerys Targaryen, the dangerous and powerful queen, you seek to rule over Westeros?Your decision can change the fate of the land. Are you ready?";
    for (char c : text) {
        cout << c;
        cout.flush();  // Ensure the character is immediately printed
        this_thread :: sleep_for(chrono::milliseconds(delay_ms));
    }
}


class Factory {
    public:
        static shared_ptr<Human> createCharacter(const string& name, const string& type);

    private:
        static shared_ptr<Human> createJonSnow(const string& name);
        static shared_ptr<Human> createJaimeLannister(const string& name);
        static shared_ptr<Human> createDaenerys(const string& name);
        static shared_ptr<Human> createStannis(const string& name);
        static shared_ptr<Human> createJoffrey(const string& name);
        static shared_ptr<Human> createTheonGreyjoy(const string& name);

        shared_ptr<Human> Factory::createCharacter(const string& name, const string& type) {
            if (type == "JonSnow") {
                return createJonSnow(name);
            } else if (type == "JaimeLannister") {
                return createJaimeLannister(name);
            } else if (type == "Daenerys") {
                return createDaenerys(name);
            } else if (type == "Stannis") {
                return createStannis(name);
            } else if (type == "Joffrey") {
                return createJoffrey(name);
            } else if (type == "TheonGreyjoy") {
                return createTheonGreyjoy(name);
            } else {
                return nullptr; // یا یک اشاره‌گر به شخصیت پیشفرض
            }
        }

    shared_ptr<Human> Factory::createJonSnow(const string& name) {
        return make_shared<Human>(name, /*age*/ 30, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 100, /*damage*/ 70, /*money*/ 100);
    }

    shared_ptr<Human> Factory::createJaimeLannister(const string& name) {
        return make_shared<Human>(name, /*age*/ 40, /*exp*/ 0, /*hp*/ 120, /*stamina*/ 80, /*damage*/ 80, /*money*/ 150);
    }

    shared_ptr<Human> Factory::createDaenerys(const string& name) {
        return make_shared<Human>(name, /*age*/ 25, /*exp*/ 0, /*hp*/ 90, /*stamina*/ 110, /*damage*/ 60, /*money*/ 120);
    }

    shared_ptr<Human> Factory::createStannis(const string& name) {
        return make_shared<Human>(name, /*age*/ 45, /*exp*/ 0, /*hp*/ 110, /*stamina*/ 90, /*damage*/ 75, /*money*/ 140);
    }

    shared_ptr<Human> Factory::createJoffrey(const string& name) {
        return make_shared<Human>(name, /*age*/ 20, /*exp*/ 0, /*hp*/ 80, /*stamina*/ 70, /*damage*/ 90, /*money*/ 200);
    }

    shared_ptr<Human> Factory::createTheonGreyjoy(const string& name) {
        return make_shared<Human>(name, /*age*/ 35, /*exp*/ 0, /*hp*/ 85, /*stamina*/ 85, /*damage*/ 65, /*money*/ 110);
    }
}
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*