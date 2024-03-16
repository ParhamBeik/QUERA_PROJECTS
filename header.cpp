#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "header.h"

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

Experience :: Experience(Human *h):humanObj(h),maximum(100),currentExp(0){}

void Experience :: updateMaximum(){
    maximum+=100;
}

int Experience :: getCurrentExp(){
    return currentExp;
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

void printWithDelay(string &text){
    int delay_ms = 20;
    for (char c : text) {
        cout << c;
        cout.flush();  // Ensure the character is immediately printed
        this_thread :: sleep_for(chrono::milliseconds(delay_ms));
    }
}

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