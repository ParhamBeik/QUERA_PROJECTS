#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <thread>
#include <chrono>
#include <map>
#include <conio.h>

#include "file.h"

using namespace std;


Person::Person(string n):name(n),level(1){}

void Person::updateLevel() {
    level++;
}

int Person::getLevel() {
    return level;
}

string Person::getName() {
    return name;
}

int Person::getHealthPoints() {
    return hp.getCurrentHealth();
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Human::Human(string n):Person(n),exp(this){}
Human::Human(string n,int s):Person(n),stamina(s){}

Backpack* Human::getBackpack() {
    Backpack *p=&backpack;
    return p;
}

int Human::getExperience() {
    return exp.getCurrentExp();
    Backpack *p=&backpack;
    return p;
}

int Human::getStamina() {
    return stamina.getCurrentStamina();
}

BankAccount* Player :: getBankAccount(){
    BankAccount* p = &bankAccount;
    return p;
}

int Human::getMoney() {
    return bankAccount.getBalance();
BankAccount* Player :: getBankAccount(){
    BankAccount* p = &bankAccount;
    return p;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Player::Player(string n, string g,string un, int a,int m,int s) : Human(n,s), age(a), gender(g), bankAccount(m) , username(un), exp(this){}
Player::Player(Human & human,string g,string un,int a,int m) : Human(human.getName(), human.getStamina()), age(a), gender(g), bankAccount(m), username(un),exp(this) {}
int Player::getAge() {
    return age;
}

string Player::getGender() {
    return gender;
}

int Player::getMoney() {
    return bankAccount.getBalance();
}

int Player::getExperience() {
    return exp.getCurrentExp();
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*


SmartZombie::SmartZombie(Human& human): Human(human.getName(), human.getStamina()){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

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

Stamina :: Stamina(int cs):maximum(100),currentStamina(cs){}

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
Experience :: Experience(Player *h):humanObj(h),maximum(100),currentExp(0){}

void Experience :: updateMaximum(){
    maximum+=100;
    maximum+=100;
}

void Experience :: setCurrentExp(int selfDamage,int enemyDamage,int usedStamina){
    currentExp+=(0.5*selfDamage)+(0.2*enemyDamage)+(0.3*usedStamina);
    if(currentExp>=maximum){
        currentExp=0;
void Experience :: setCurrentExp(int selfDamage,int enemyDamage,int usedStamina){
    currentExp+=(0.5*selfDamage)+(0.2*enemyDamage)+(0.3*usedStamina);
    if(currentExp>=maximum){
        currentExp=0;
        updateMaximum();
        humanObj->updateLevel();
        humanObj->stamina.updateMaximumStamina();
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

int Experience::getCurrentExp(){
    return currentExp;
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

void Backpack :: addFoodItem(const Food foodItem, int quantity){
    if(FoodItems.find(foodItem)!=FoodItems.end()){
        FoodItems[foodItem]+=quantity;
    }
    else
        FoodItems.insert({foodItem,quantity});
void Backpack :: addFoodItem(const Food foodItem, int quantity){
    if(FoodItems.find(foodItem)!=FoodItems.end()){
        FoodItems[foodItem]+=quantity;
    }
    else
        FoodItems.insert({foodItem,quantity});
}

void Backpack :: addMedicineItem(const Medicine medicineItem, int quantity){
    if(MedicineItems.find(medicineItem)!=MedicineItems.end()){
        MedicineItems[medicineItem]+=quantity;
    }
    else
        MedicineItems.insert({medicineItem,quantity});
void Backpack :: addMedicineItem(const Medicine medicineItem, int quantity){
    if(MedicineItems.find(medicineItem)!=MedicineItems.end()){
        MedicineItems[medicineItem]+=quantity;
    }
    else
        MedicineItems.insert({medicineItem,quantity});
}

void Backpack :: addThrowableItem(const Throwable throwableItem, int quantity){
    if(ThrowableItems.find(throwableItem)!=ThrowableItems.end()){
        ThrowableItems[throwableItem]+=quantity;
    }
    else
        ThrowableItems.insert({throwableItem,quantity});
void Backpack :: addThrowableItem(const Throwable throwableItem, int quantity){
    if(ThrowableItems.find(throwableItem)!=ThrowableItems.end()){
        ThrowableItems[throwableItem]+=quantity;
    }
    else
        ThrowableItems.insert({throwableItem,quantity});
}

void Backpack :: addWarmWeaponItem(const WarmWeapon warmWeaponItem){
    WarmWeaponItems.push_back(warmWeaponItem);
void Backpack :: addWarmWeaponItem(const WarmWeapon warmWeaponItem){
    WarmWeaponItems.push_back(warmWeaponItem);
}

void Backpack :: addColdWeaponItem(const ColdWeapon coldWeaponItem){
    ColdWeaponItems.push_back(coldWeaponItem);
void Backpack :: addColdWeaponItem(const ColdWeapon coldWeaponItem){
    ColdWeaponItems.push_back(coldWeaponItem);
}

bool Backpack::warmWeaponExistence(const WarmWeapon warmWeaponItem){
    for (const auto &item : WarmWeaponItems) {
        if (item== warmWeaponItem) {
            return true;
        }
    }
    return false;
}

bool Backpack::coldWeaponExistence(const ColdWeapon coldWeaponItem){
    for (const auto &item : ColdWeaponItems) {
        if (item== coldWeaponItem) {
            return true;
        }
    }
    return false;
}

void Backpack :: removeFoodItem(const Food foodItem) {
    FoodItems.erase(foodItem);
bool Backpack::warmWeaponExistence(const WarmWeapon warmWeaponItem){
    for (const auto &item : WarmWeaponItems) {
        if (item== warmWeaponItem) {
            return true;
        }
    }
    return false;
}

bool Backpack::coldWeaponExistence(const ColdWeapon coldWeaponItem){
    for (const auto &item : ColdWeaponItems) {
        if (item== coldWeaponItem) {
            return true;
        }
    }
    return false;
}

void Backpack :: removeFoodItem(const Food foodItem) {
    FoodItems.erase(foodItem);
}

void Backpack :: removeMedicineItem(const Medicine medicineItem) {
    MedicineItems.erase(medicineItem);
void Backpack :: removeMedicineItem(const Medicine medicineItem) {
    MedicineItems.erase(medicineItem);
}

void Backpack :: removeThrowableItem(const Throwable throwableItem) {
    ThrowableItems.erase(throwableItem);
void Backpack :: removeThrowableItem(const Throwable throwableItem) {
    ThrowableItems.erase(throwableItem);
}

void Backpack :: useFoodItemCount(const Food foodItem) {
    FoodItems[foodItem]-=1;
    if(FoodItems[foodItem]==0)
        removeFoodItem(foodItem);
}

void Backpack :: useMedicineItemCount(const Medicine medicineItem) {
    MedicineItems[medicineItem]-=1;
    if(MedicineItems[medicineItem]==0)
        removeMedicineItem(medicineItem);
void Backpack :: useFoodItemCount(const Food foodItem) {
    FoodItems[foodItem]-=1;
    if(FoodItems[foodItem]==0)
        removeFoodItem(foodItem);
}

void Backpack :: useMedicineItemCount(const Medicine medicineItem) {
    MedicineItems[medicineItem]-=1;
    if(MedicineItems[medicineItem]==0)
        removeMedicineItem(medicineItem);
}

void Backpack :: useThrowableItemCount(const Throwable throwableItem) {
    ThrowableItems[throwableItem]-=1;
    if(ThrowableItems[throwableItem]==0)
        removeThrowableItem(throwableItem);
void Backpack :: useThrowableItemCount(const Throwable throwableItem) {
    ThrowableItems[throwableItem]-=1;
    if(ThrowableItems[throwableItem]==0)
        removeThrowableItem(throwableItem);
}

void Backpack::showItems(){
    if(!ColdWeaponItems.empty()){
        for(auto i:ColdWeaponItems){
            cout<<"type : "<<i.getName()<<"\tname : "<<i.getName()<<'\n';
void Backpack::showItems(){
    if(!ColdWeaponItems.empty()){
        for(auto i:ColdWeaponItems){
            cout<<"type : "<<i.getName()<<"\tname : "<<i.getName()<<'\n';
        }
    }

    if(!WarmWeaponItems.empty()){
        for(auto i:WarmWeaponItems){
            cout<<"type : "<<i.getName()<<"\tname : "<<i.getName()<<'\n';

    if(!WarmWeaponItems.empty()){
        for(auto i:WarmWeaponItems){
            cout<<"type : "<<i.getName()<<"\tname : "<<i.getName()<<'\n';
        }
    }

    if(!ThrowableItems.empty()){
        for(auto i:ThrowableItems){
            Throwable item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';

    if(!ThrowableItems.empty()){
        for(auto i:ThrowableItems){
            Throwable item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';
        }
    }

    if(!MedicineItems.empty()){
        for(auto i:MedicineItems){
            Medicine item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';

    if(!MedicineItems.empty()){
        for(auto i:MedicineItems){
            Medicine item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';
        }
    }

    if(!FoodItems.empty()){
        for(auto i:FoodItems){
            Food item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';

    if(!FoodItems.empty()){
        for(auto i:FoodItems){
            Food item=i.first;
            cout<<"type : "<<item.getName()<<"\tname : "<<item.getName()<<"\tstock : "<<i.second<<'\n';
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

bool Items::operator<(const Items& other) const {
        return name < other.name;
}

string Items::getName(){
    return name;
}

string Items::getType(){
    return type;
}

bool Items::operator<(const Items& other) const {
        return name < other.name;
}

string Items::getName(){
    return name;
}

string Items::getType(){
    return type;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Permanent::Permanent(string n,int p,string t,int e,int h):Items(n,p,t),exp(e),harm(h){}
Permanent::Permanent(string n,int p,string t,int e,int h):Items(n,p,t),exp(e),harm(h){}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

WarmWeapon::WarmWeapon(string n,int p,int x,int e,int h):Permanent(n,p,"Warm Weapon",e,h),wwa(x){
WarmWeapon::WarmWeapon(string n,int p,int x,int e,int h):Permanent(n,p,"Warm Weapon",e,h),wwa(x){
    WarmWeapon::addToVectors();
}

void WarmWeapon::showItems(){
    for(WarmWeapon *i : shop_items_permanent_warmweapon){
        cout << *i << endl;
    }
}

void WarmWeapon::buy(Player& player){
    BankAccount *creditcard=player.getBankAccount();
    Backpack *backpack=player.getBackpack();

    if(backpack->warmWeaponExistence(*this)){
        cout<<"This item already exist in you backpack!\n";
    }

    else if(creditcard->withdraw(price)){
    Backpack *backpack=player.getBackpack();

    if(backpack->warmWeaponExistence(*this)){
        cout<<"This item already exist in you backpack!\n";
    }

    else if(creditcard->withdraw(price)){
        cout << "Item bought successfully!\n";
        backpack->addWarmWeaponItem(*this);
        backpack->addWarmWeaponItem(*this);
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

    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (wwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (wwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
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

ostream& operator<<(ostream &os,WarmWeapon &obj){
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\tlvl "<<obj.wwa.getCurrentSkill()<<"\t(+"<<obj.exp<<"EXP)\tprice : "<<obj.price<<"$";
    return os;
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

ColdWeapon::ColdWeapon(string n,int p,int x,int e,int h):Permanent(n,p,"Cold Weapon",e,h),cwa(x){
ColdWeapon::ColdWeapon(string n,int p,int x,int e,int h):Permanent(n,p,"Cold Weapon",e,h),cwa(x){
    ColdWeapon::addToVectors();
}

void ColdWeapon::showItems(){
    for (auto& i : shop_items_permanent_coldweapon){
        cout << i << endl;
    }
}

void ColdWeapon::buy(Player& player){
    BankAccount *creditcard=player.getBankAccount();
    Backpack *backpack=player.getBackpack();

    if(backpack->coldWeaponExistence(*this)){
        cout<<"This item already exist in you backpack!\n";
    }

    else if(creditcard->withdraw(price)){
    Backpack *backpack=player.getBackpack();

    if(backpack->coldWeaponExistence(*this)){
        cout<<"This item already exist in you backpack!\n";
    }

    else if(creditcard->withdraw(price)){
        cout << "Item bought successfully!\n";
        backpack->addColdWeaponItem(*this);
        backpack->addColdWeaponItem(*this);
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

    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (cwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (cwa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
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

Throwable::Throwable(string n,int p,int x,int e,int h):Items(n,p,"Throwable Weapon"),twa(x),exp(e),harm(h){
Throwable::Throwable(string n,int p,int x,int e,int h):Items(n,p,"Throwable Weapon"),twa(x),exp(e),harm(h){
    Throwable::addToVectors();
}

void Throwable::showItems(){
    for (auto& i : shop_items_throwable){
        cout << i << endl;
    }
}

void Throwable::buy(Player& player,int quantity){
    BankAccount *creditcard=player.getBankAccount();
    Backpack *backpack=player.getBackpack();
    Backpack *backpack=player.getBackpack();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        backpack->addThrowableItem(*this,quantity);
        backpack->addThrowableItem(*this,quantity);
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
    double staminaFactor = 0.3;
    double weaponLevelFactor = 1.0;
    double playerLevelFactor = 0.8;

    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (twa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    attacker.stamina.decreaseStamina(10*twa.getCurrentSkill());
    attacked.hp.decreaseHealth(damage);

    if(static_cast<Player*>(&attacker)){
        Player *p=static_cast<Player*>(&attacker);
        p->exp.setCurrentExp(0,damage,10*twa.getCurrentSkill());
        Backpack *b=p->getBackpack();
        b->useThrowableItemCount(*this);
    }
    else{
        Player *p=static_cast<Player*>(&attacked);
        p->exp.setCurrentExp(damage,0,0);
        Backpack *b=attacker.getBackpack();
        b->useThrowableItemCount(*this);
    }
    double staminaFactor = 0.3;
    double weaponLevelFactor = 1.0;
    double playerLevelFactor = 0.8;

    int damage = harm + (attacker.stamina.getCurrentStamina() * staminaFactor) + (twa.getCurrentSkill() * weaponLevelFactor) + (attacker.getLevel() * playerLevelFactor);
    attacker.stamina.decreaseStamina(10*twa.getCurrentSkill());
    attacked.hp.decreaseHealth(damage);

    if(static_cast<Player*>(&attacker)){
        Player *p=static_cast<Player*>(&attacker);
        p->exp.setCurrentExp(0,damage,10*twa.getCurrentSkill());
        Backpack *b=p->getBackpack();
        b->useThrowableItemCount(*this);
    }
    else{
        Player *p=static_cast<Player*>(&attacked);
        p->exp.setCurrentExp(damage,0,0);
        Backpack *b=attacker.getBackpack();
        b->useThrowableItemCount(*this);
    }
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
    Backpack *backpack=player.getBackpack();
    Backpack *backpack=player.getBackpack();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        backpack->addMedicineItem(*this,quantity);
        backpack->addMedicineItem(*this,quantity);
        cout<<"Item added to your backpack!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void Medicine::addToVectors(){
    shop_items_medicine.push_back(this);
    shop_items.push_back(this);
}

void Medicine::use(Human& human){
    human.hp.increaseHealth(heal);
    Backpack *b=human.getBackpack();
    b->useMedicineItemCount(*this);
void Medicine::use(Human& human){
    human.hp.increaseHealth(heal);
    Backpack *b=human.getBackpack();
    b->useMedicineItemCount(*this);
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
    Backpack *backpack=player.getBackpack();
    Backpack *backpack=player.getBackpack();

    if(creditcard->withdraw(price*quantity)){
        cout << "Item bought successfully!\n";
        backpack->addFoodItem(*this,quantity);
        backpack->addFoodItem(*this,quantity);
        cout<<"Item added to your backpack!\n";
    }
    else
        cout<<"Not enough money!\n";
}

void Food::addToVectors(){
    shop_items_food.push_back(this);
    shop_items.push_back(this);
}

void Food::use(Human& human){
    human.stamina.increaseStamina(strength);
    Backpack *b=human.getBackpack();
    b->useFoodItemCount(*this);
void Food::use(Human& human){
    human.stamina.increaseStamina(strength);
    Backpack *b=human.getBackpack();
    b->useFoodItemCount(*this);
}

ostream& operator<<(ostream& os,Food& obj) {
    os<<"name : "<<obj.name<<"\ttype : "<<obj.type<<"\theal : +"<<obj.strength<<"STM"<<"\tprice : "<<obj.price<<"$ (each)";
    return os;
}



// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void printWithDelay(string text){
    int delay_ms = 20;
    for (char c : text) {
        cout << c;
        cout.flush();  // Ensure the character is immediately printed
        this_thread :: sleep_for(chrono::milliseconds(delay_ms));
    }
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void ShopMenu(){
    while(true){
        system("cls");
        int number;
        cout << "You enter the shop." << endl << "What do you want to buy?" << endl 
        << "[1].Permanent Items" << endl << "[2].Throwable Items" << endl << "[3].Consumable Items" << endl << "[4].Exit" << endl;
        cin >> number;
        switch(number){
            case 1: Show_Permanent_Items();
                break;
        
            case 2: Show_Throwable_Items();
                break;
        
            case 3: Show_Consumable_Items();
                break;
        
            case 4: 
            cout << "You left the shop." << endl;
                return;

            default: 
            cout << "Wrong number!" << endl << "Press enter to continue";
            getch();
                break;
        }
    }
}

void Show_Permanent_Items(){
    system("cls");
    int number;
    cout << "Permanent Items:" << endl << "[1].WarmWeapons" << endl << "[2].ColdWeapons" << endl << "[3].back" << endl;
    switch(number){
        case 1: 
        cout << "You go to take a look at the WarmWeapons:" << endl;
        WarmWeapon::showItems();
            break;
        
        case 2:
        cout << "You go to take a look at the ColdWeapons:" << endl; 
        ColdWeapon::showItems();
            break;
        
        case 3: 
            return;
    }
}

void Show_Throwable_Items(){
    system("cls");
    cout << "You go to take a look at the Throwable Items:" << endl;
    Throwable::showItems();
}

void Show_Consumable_Items(){
    system("cls");
    int number;
    cout << "Consumable Items:" << endl << "[1].Medicines" << endl << "[2].Foods" << endl << "[3].back" << endl;
    switch(number){
        case 1: 
        cout << "You go to take a look at the Medicines:" << endl;
        Medicine::showItems();
            break;
            
        case 2:
        cout << "You go to take a look at the Foods:" << endl;
        Food::showItems();
            break;
        
        case 3: 
            return;
    }
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void createWarmWeapons() {
    WarmWeapon longclaw("Longclaw", 2800, 3, 20, 15);
    WarmWeapon wildfire("Wildfire Flask", 2500, 1, 25, 18);
    WarmWeapon dragonfire("Dragonfire Bow", 2200, 2, 15, 22);
    WarmWeapon valyrian("Valyrian Steel Dagger", 1900, 3, 30, 14);
    WarmWeapon dragonglass("Dragonglass Blade", 1600, 1, 12, 20);
    WarmWeapon ice("Ice Sword", 3000, 2, 18, 12);
    WarmWeapon crimson("Crimson Sword", 2700, 2, 22, 16);
    WarmWeapon shadow("Shadow Dagger", 2400, 3, 28, 19);
    WarmWeapon blackfyre("Blackfyre Sword", 2100, 1, 16, 23);
    WarmWeapon storm("Storm Bow", 1800, 2, 14, 17);
}

void createColdWeapons() {
    ColdWeapon icicle("Icicle Dagger", 2800, 3, 30, 13);
    ColdWeapon frostbite("Frostbite Axe", 2500, 2, 20, 18);
    ColdWeapon blizzard("Blizzard Mace", 2200, 1, 25, 21);
    ColdWeapon snowfall("Snowfall Sword", 1900, 2, 18, 16);
    ColdWeapon freeze("Freeze Bow", 1600, 1, 12, 11);
    ColdWeapon frost("Frost Dagger", 2700, 3, 16, 22);
    ColdWeapon coldsteel("Coldsteel Axe", 2400, 1, 22, 14);
    ColdWeapon winter("Winter Mace", 2100, 2, 28, 19);
    ColdWeapon icy("Icy Sword", 1800, 1, 14, 17);
    ColdWeapon chill("Chill Bow", 1500, 3, 20, 12);
}

void createThrowableItems() {
    Throwable bomb("Firebomb", 2500, 2, 16, 15);
    Throwable grenade("Ice Grenade", 2200, 3, 12, 17);
    Throwable dart("Poison Dart", 1600, 1, 18, 20);
    Throwable rock("Rock", 1300, 3, 14, 23);
    Throwable knife("Throwing Knife", 1000, 2, 30, 10);
}

void createMedicines() {
    Medicine milkOfThePoppy("Milk of the Poppy", 1200, 20);
    Medicine essenceOfNightshade("Essence of Nightshade", 1100, 18);
    Medicine dreamwine("Dreamwine", 1000, 15);
    Medicine sourRed("Sour Red", 1300, 22);
    Medicine sweetsleep("Sweetsleep", 1500, 25);
    Medicine moonTea("Moon Tea", 1050, 15);
    Medicine weirwoodPaste("Weirwood Paste", 1250, 18);
    Medicine firemilk("Firemilk", 1400, 22);
    Medicine greyscaleCure("Greyscale Cure", 1800, 30);
    Medicine heartsbane("Heartsbane", 1700, 28);
}

void createFoods() {
    Food roastPork("Roast Pork", 1200, 25);
    Food lemonCakes("Lemon Cakes", 1100, 23);
    Food honeyedChicken("Honeyed Chicken", 1000, 20);
    Food beefAndBarleyStew("Beef and Barley Stew", 1300, 26);
    Food blackBread("Black Bread", 1500, 28);
    Food fishPie("Fish Pie", 1050, 18);
    Food lemonWater("Lemon Water", 1250, 20);
    Food mulledWine("Mulled Wine", 1400, 23);
    Food venisonStew("Venison Stew", 1800, 30);
    Food honeycakes("Honeycakes", 1700, 28);
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void ShopMenu(){
    while(true){
        //system("cls");
        int number;
        cout << "You enter the shop." << endl << "What do you want to buy?" << endl 
        << "[1].Permanent Items" << endl << "[2].Throwable Items" << endl << "[3].Consumable Items" << endl << "[4].Exit" << endl;
        cin >> number;
        switch(number){
            case 1: Show_Permanent_Items();
                break;
        
            case 2: Show_Throwable_Items();
                break;
        
            case 3: Show_Consumable_Items();
                break;
        
            case 4: 
            cout << "You left the shop." << endl;
                return;

            default: 
            cout << "Wrong number!" << endl << "Press enter to continue";
            getch();
                break;
        }
    }
}

void Show_Permanent_Items(){
    //system("cls");
    int number;
    cout << "Permanent Items:" << endl << "[1].WarmWeapons" << endl << "[2].ColdWeapons" << endl << "[3].back" << endl;
    cin>>number;
    switch(number){
        case 1: 
        cout << "You go to take a look at the WarmWeapons:" << endl;
        WarmWeapon::showItems();
            break;
        
        case 2:
        cout << "You go to take a look at the ColdWeapons:" << endl; 
        ColdWeapon::showItems();
            break;
        
        case 3: 
            return;
    }
}

void Show_Throwable_Items(){
    // system("cls");
    cout << "You go to take a look at the Throwable Items:" << endl;
    Throwable::showItems();
}

void Show_Consumable_Items(){
    //system("cls");
    int number;
    cout << "Consumable Items:" << endl << "[1].Medicines" << endl << "[2].Foods" << endl << "[3].back" << endl;
    cin>>number;
    switch(number){
        case 1: 
        cout << "You go to take a look at the Medicines:" << endl;
        Medicine::showItems();
            break;
            
        case 2:
        cout << "You go to take a look at the Foods:" << endl;
        Food::showItems();
            break;
        
        case 3: 
            return;
    }
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void createWarmWeapons() {
    WarmWeapon longclaw("Longclaw", 2800, 3, 20, 15);
    WarmWeapon wildfire("Wildfire Flask", 2500, 1, 25, 18);
    WarmWeapon dragonfire("Dragonfire Bow", 2200, 2, 15, 22);
    WarmWeapon valyrian("Valyrian Steel Dagger", 1900, 3, 30, 14);
    WarmWeapon dragonglass("Dragonglass Blade", 1600, 1, 12, 20);
    WarmWeapon ice("Ice Sword", 3000, 2, 18, 12);
    WarmWeapon crimson("Crimson Sword", 2700, 2, 22, 16);
    WarmWeapon shadow("Shadow Dagger", 2400, 3, 28, 19);
    WarmWeapon blackfyre("Blackfyre Sword", 2100, 1, 16, 23);
    WarmWeapon storm("Storm Bow", 1800, 2, 14, 17);
}

void createColdWeapons() {
    ColdWeapon icicle("Icicle Dagger", 2800, 3, 30, 13);
    ColdWeapon frostbite("Frostbite Axe", 2500, 2, 20, 18);
    ColdWeapon blizzard("Blizzard Mace", 2200, 1, 25, 21);
    ColdWeapon snowfall("Snowfall Sword", 1900, 2, 18, 16);
    ColdWeapon freeze("Freeze Bow", 1600, 1, 12, 11);
    ColdWeapon frost("Frost Dagger", 2700, 3, 16, 22);
    ColdWeapon coldsteel("Coldsteel Axe", 2400, 1, 22, 14);
    ColdWeapon winter("Winter Mace", 2100, 2, 28, 19);
    ColdWeapon icy("Icy Sword", 1800, 1, 14, 17);
    ColdWeapon chill("Chill Bow", 1500, 3, 20, 12);
}

void createThrowableItems() {
    Throwable bomb("Firebomb", 2500, 2, 16, 15);
    Throwable grenade("Ice Grenade", 2200, 3, 12, 17);
    Throwable dart("Poison Dart", 1600, 1, 18, 20);
    Throwable rock("Rock", 1300, 3, 14, 23);
    Throwable knife("Throwing Knife", 1000, 2, 30, 10);
}

void createMedicines() {
    Medicine milkOfThePoppy("Milk of the Poppy", 1200, 20);
    Medicine essenceOfNightshade("Essence of Nightshade", 1100, 18);
    Medicine dreamwine("Dreamwine", 1000, 15);
    Medicine sourRed("Sour Red", 1300, 22);
    Medicine sweetsleep("Sweetsleep", 1500, 25);
    Medicine moonTea("Moon Tea", 1050, 15);
    Medicine weirwoodPaste("Weirwood Paste", 1250, 18);
    Medicine firemilk("Firemilk", 1400, 22);
    Medicine greyscaleCure("Greyscale Cure", 1800, 30);
    Medicine heartsbane("Heartsbane", 1700, 28);
}

void createFoods() {
    Food roastPork("Roast Pork", 1200, 25);
    Food lemonCakes("Lemon Cakes", 1100, 23);
    Food honeyedChicken("Honeyed Chicken", 1000, 20);
    Food beefAndBarleyStew("Beef and Barley Stew", 1300, 26);
    Food blackBread("Black Bread", 1500, 28);
    Food fishPie("Fish Pie", 1050, 18);
    Food lemonWater("Lemon Water", 1250, 20);
    Food mulledWine("Mulled Wine", 1400, 23);
    Food venisonStew("Venison Stew", 1800, 30);
    Food honeycakes("Honeycakes", 1700, 28);
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

Human* Factory::createCharacter(const string& type) {
    if (type == "JonSnow") {
        return createJonSnow(type);
    }
    else if (type == "JaimeLannister") {
        return createJaimeLannister(type);
    }
    else if (type == "Daenerys") {
        return createDaenerys(type);
    }
    else if (type == "Stannis") {
        return createStannis(type);
    }
    else if (type == "Joffrey") {
        return createJoffrey(type);
    }
    else if (type == "TheonGreyjoy") {
        return createTheonGreyjoy(type);
    }
    else {
        return nullptr;
    }
}

Human* Factory::createJonSnow(const string& type) {
    return new Human(type, /*stamina*/ 100);
}

Human* Factory::createJaimeLannister(const string& type) {
    return new Human(type, /*stamina*/ 70);
}

Human* Factory::createDaenerys(const string& type) {
    return new Human(type, /*stamina*/ 110);
}

Human* Factory::createStannis(const string& type) {
    return new Human(type, /*stamina*/ 90);
}

Human* Factory::createJoffrey(const string& type) {
    return new Human(type, /*stamina*/ 75);
}

Human* Factory::createTheonGreyjoy(const string& type) {
    return new Human(type, /*stamina*/ 85);
}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
void Menu() {
    int age;
    string gender,username;
    // just getting user info :)))

    vector<string> characterTypes = {"JonSnow", "JaimeLannister", "Daenerys", "Stannis", "Joffrey", "TheonGreyjoy"};
    int chosenIndex;
    int money[6]={1000,1800,1200,1300,2000,1100};
    Player* player = nullptr;
    vector<SmartZombie*> zombies;

    // Show all the different options a user has for the characters
    cout << "Choose a character: " << endl;
    for (int i = 0; i < characterTypes.size(); i++) {
        Human* character = Factory::createCharacter(characterTypes[i]);
        cout << i+1 << ". " << characterTypes[i] << endl;
        cout << "   Name: " << character->getName() << endl;
        cout << "   Stamina: " << character->getStamina() << endl;
        cout << "   Money: " << money[i] << endl;
        delete character;  // Delete the temporary character
    }

    // Get the user's choice
    cin >> chosenIndex;
    chosenIndex--;  // Adjust for 0-based indexing

    // Create the characters
    for (int i = 0; i < characterTypes.size(); i++) {
        Human* character = Factory::createCharacter(characterTypes[i]);
        if (i == chosenIndex) {
            // Turn the chosen character into a Player object
            player = new Player(*character,gender,username,age,money[i]);
        } else {
            // Turn the other characters into SmartZombie objects
            zombies.push_back(new SmartZombie(*character));
        }
        delete character;  // Delete the temporary character
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

    // Don't forget to delete the player and zombies when you're done with them
    delete player;
    for (auto& zombie : zombies) {
        delete zombie;
    }
}
