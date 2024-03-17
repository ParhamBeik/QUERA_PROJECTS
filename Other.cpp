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

Health ::Health() : maxHealth(100){}

int Health ::getCurrentHealth() {
    return currentHealth;
}

int Health ::getMaxHealth() {
    return maxHealth;
}

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

Stamina :: Stamina():maximum(50),currentStamina(100){}

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
    maximum+=50;
}

int Stamina :: getCurrentStamina(){
    return currentStamina;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Experience :: Experience() : maximum(100), currentExp(0) {}

void Experience :: updateMaximum(){
    maximum += 100;
}

int Experience :: getCurrentExp(){
    return currentExp;
}

void Experience :: setCurrentExp(int selfDamage, int enemyDamage, int usedStamina){
    currentExp += (0.5 * selfDamage) + (0.2 * enemyDamage) + (0.3 * usedStamina);
    if(currentExp >= maximum){
        currentExp = 0;
        updateMaximum();
    }
}

void Experience::increaseExp(int amount){
    currentExp += amount;
    if(currentExp >= maximum){
        currentExp = 0;
        updateMaximum();
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

int Skills::getCurrentSkill(){
    return currentSkill;
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

BankAccount :: BankAccount(int n){
    this->balance = n;
}
int BankAccount :: getBalance() {
    return balance;
}
void BankAccount :: deposit(int amount) { 
    this->balance += amount;
}
bool BankAccount::withdraw(int amount) {
    if (balance >= amount){
        balance -= amount;
        return true;
    }    
    else
        return false;
        
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

shared_ptr<Human> Factory::createCharacter(const string& name, const string& type) {
    if (type == "JonSnow") {
        return createJonSnow(name);
    }
    else if (type == "JaimeLannister") {
        return createJaimeLannister(name);
    }
    else if (type == "Daenerys") {
        return createDaenerys(name);
    }
    else if (type == "Stannis") {
        return createStannis(name);
    }
    else if (type == "Joffrey") {
        return createJoffrey(name);
    }
    else if (type == "TheonGreyjoy") {
        return createTheonGreyjoy(name);
    }
    else {
        return nullptr;
    }
}

shared_ptr<Human> Factory::createJonSnow(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 100, /*damage*/ 85, /*money*/ 100);
}

shared_ptr<Human> Factory::createJaimeLannister(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 70, /*damage*/ 80, /*money*/ 180);
}

shared_ptr<Human> Factory::createDaenerys(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 110, /*damage*/ 65, /*money*/ 120);
}

shared_ptr<Human> Factory::createStannis(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 90, /*damage*/ 75, /*money*/ 130);
}

shared_ptr<Human> Factory::createJoffrey(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 75, /*damage*/ 60, /*money*/ 200);
}

shared_ptr<Human> Factory::createTheonGreyjoy(const string& name) {
    return make_shared<Human>(name, /*exp*/ 0, /*hp*/ 100, /*stamina*/ 85, /*damage*/ 70, /*money*/ 110);
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void Menu() {
    vector<string> characterTypes = {"JonSnow", "JaimeLannister", "Daenerys", "Stannis", "Joffrey", "TheonGreyjoy"};
    int chosenIndex;
    shared_ptr<Player> player;
    vector<shared_ptr<SmartZombie>> zombies;

    // Show all the different options a user has for the characters
    cout << "Choose a character: " << endl;
    for (int i = 0; i < characterTypes.size(); i++) {
        shared_ptr<Human> character = Factory::createCharacter(characterTypes[i], characterTypes[i]);
        cout << i+1 << ". " << characterTypes[i] << endl;
        cout << "   Name: " << character->getName() << endl;
        cout << "   Experience: " << character->getExperience() << endl;
        cout << "   Health Points: " << character->getHealthPoints() << endl;
        cout << "   Stamina: " << character->getStamina() << endl;
        cout << "   Damage: " << character->getDamage() << endl;
        cout << "   Money: " << character->getMoney() << endl;
    }

    // Get the user's choice
    cin >> chosenIndex;
    chosenIndex--;  // Adjust for 0-based indexing

    // Create the characters
    for (int i = 0; i < characterTypes.size(); i++) {
        shared_ptr<Human> character = Factory::createCharacter(characterTypes[i], characterTypes[i]);
        if (i == chosenIndex) {
            // Turn the chosen character into a Player object
            player = dynamic_pointer_cast<Player>(character);
        } else {
            // Turn the other characters into SmartZombie objects
            zombies.push_back(dynamic_pointer_cast<SmartZombie>(character));
        }
    }

    // Show the details of the Player
    cout << "Player details: " << endl;
    cout << "Name: " << player->getName() << endl;
    cout << "Level: " << player->getLevel() << endl;
    // Add more details as needed...

    // Show the details of the SmartZombies
    for (const auto& zombie : zombies) {
        cout << "Zombie details: " << endl;
        cout << "Name: " << zombie->getName() << endl;
        cout << "Level: " << zombie->getLevel() << endl;
        // Add more details as needed...
    }
}
