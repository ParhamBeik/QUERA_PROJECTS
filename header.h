#ifndef HEADER
#define HEADER

#include<iostream>
#include<string>
#include <memory>
#include <vector>
#include<algorithm>
#include <thread>
#include <chrono>

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
        void updateLevel();
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

class Health {
private :
    int currentHealth;
    int maxHealth;
public :
    Health();
    int getCurrentHealth();
    int getMaxHealth();
    void decreaseHealth(int damage);
    void increaseHealth (int amount);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Stamina {
private :
    int currentStamina;
    int maximum;
public :
    Stamina();
    void decreaseStamina(int amount);
    void increaseStamina(int amount);
    void updateMaximumStamina();
    int getCurrentStamina();
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Experience {
    private:
        int maximum;
        int currentExp;
        Human *humanObj;
    public:
        Experience(Human* h = nullptr) : humanObj(h), maximum(0), currentExp(0) {}
        void updateMaximum();
        void setCurrentExp(int,int,int);
        void increaseExp(int);
        int getCurrentExp();
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Skills {
    protected:
        int maximum;
        int currentSkill;
        int upgradePrice;
    public:
        Skills(int,int);
        void upgradeSkill(BankAccount*);
        void setUpgradePrice();
        int getCurrentSkill();

};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class WarmWeaponAbility : public Skills {
    public:
        WarmWeaponAbility(int);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class ColdWeaponAbility : public Skills {
    public:
        ColdWeaponAbility(int);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class ThrowableWeaponAbility : public Skills {
    public:
        ThrowableWeaponAbility(int);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Backpack {
    protected:
        vector<pair<Food , int>> FoodItems;
        vector<pair<Medicine , int>> MedicineItems;
        vector<pair<Throwable , int>> ThrowableItems;
        vector<pair<WarmWeapon , int>> WarmWeaponItems;
        vector<pair<ColdWeapon , int>> ColdWeaponItems;
    public:
        void addFoodItem(const Food& foodItem, int quantity);
        void addMedicineItem(const Medicine& medicineItem, int quantity);
        void addThrowableItem(const Throwable& throwableItem, int quantity);
        void addWarmWeaponItem(const WarmWeapon& WarmWeaponItem);
        void addColdWeaponItem(const ColdWeapon& ColdWeaponItem);

        void removeFoodItem(const Food& foodItem);
        void removeMedicineItem(const Medicine& medicineItem);
        void removeThrowableItem(const Throwable& throwableItem);
        void removeWarmWeaponItem(const WarmWeapon& WarmWeaponItem);
        void removeColdWeaponItem(const ColdWeapon& ColdWeaponItem);

        int getFoodItemsCount();
        int getMedicineItemsCount();
        int getThrowableItemsCount();
        int getWarmWeaponItemsCount();
        int getColdWeaponItemsCount();

        int getSpecificFoodItemCount(const Food& specificItem) const;
        int getSpecificMedicineItemCount(const Medicine& specificItem) const;
        int getSpecificThrowableItemCount(const Throwable& specificItem) const;
        int getSpecificWarmWeaponItemCount(const WarmWeapon& WarmWeaponItem) const;
        int getSpecificColdWeaponItemCount(const ColdWeapon& ColdWeaponItem) const;
        
        void clearFoodItems();
        void clearMedicineItems();
        void clearThrowableItems();
        void clearWarmWeaponItems();
        void clearColdWeaponItems();

        void useFoodItemCount(const Food& specificItem, int quantity);
        void useMedicineItemCount(const Medicine& specificItem, int quantity);
        void useThrowableItemCount(const Throwable& specificItem, int quantity);

};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class BankAccount {
    protected:
        int balance;
    public:
        BankAccount(int b = 0) : balance(b) {}
        int getBalance();
        void deposit(int amount);
        bool withdraw(int amount);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Items {
    protected:
        string type;
        string name;
        int price;
        static vector <Items*> shop_items;
    public:
        Items(string,int,string);
        virtual void showItems(){}                       //show the available items in the shop based on their types
        virtual void addToVectors(){}                    //add the bought item to the vector
        virtual void use(Player&){}                      //use consumable items and increase health or stamina 
        bool operator==(const Items& other) const;       //check equality of two object names
}; 
vector <Items*> Items::shop_items;     

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Permanent : public Items {
    protected:
        int exp;
        static vector <Permanent*> shop_items_permanent;
    public:
        Permanent(string,int,string,int);       
        virtual void buy(Player&){}                      //buy item and add it into player's backpack
        virtual void Attack(Human,Human){}               //calculate the damage of attacker and reduce it from attacked health
};
vector <Permanent*> Permanent::shop_items_permanent;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class WarmWeapon : public Permanent {
    private:
        static vector <WarmWeapon*> shop_items_permanent_warmweapon;
        WarmWeaponAbility wwa;
    public:
        WarmWeapon(string,int,int,int);
        void showItems() override;
        void buy(Player&) override;
        void addToVectors() override;
        void Attack(Human,Human) override;
        friend ostream& operator<<(ostream&,WarmWeapon&);
};
vector <WarmWeapon*> WarmWeapon::shop_items_permanent_warmweapon;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class ColdWeapon : public Permanent {
    private:
        static vector <ColdWeapon*> shop_items_permanent_coldweapon;
        ColdWeaponAbility cwa;
    public:
        ColdWeapon(string,int,int,int);
        void showItems() override;
        void buy(Player&) override;
        void addToVectors() override;
        void Attack(Human,Human) override;
        friend ostream& operator<<(ostream&,ColdWeapon&);
};
vector <ColdWeapon*> ColdWeapon::shop_items_permanent_coldweapon;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Throwable : public Items {
    private:
        int exp;
        static vector <Throwable*> shop_items_throwable;
        ThrowableWeaponAbility twa;
    public:
        Throwable(string,int,int,int);
        void showItems() override;
        void buy(Player&,int);
        void addToVectors() override;
        void Throw(Human,Human);
        friend ostream& operator<<(ostream&,Throwable&);
};
vector <Throwable*> Throwable::shop_items_throwable;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Medicine : public Items {
    private:
        int heal;
        static vector <Medicine*> shop_items_medicine;
    public:
        Medicine(string,int,int);
        void showItems() override;
        void buy(Player&,int);
        void addToVectors() override;
        void use(Player&) override;
        friend ostream& operator<<(ostream&,Medicine&);
};
vector <Medicine*> Medicine::shop_items_medicine;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Food : public Items {
    private:
        int strength;
        static vector <Food*> shop_items_food;
    public:
        Food(string,int,int);
        void showItems() override;
        void buy(Player&,int);
        void addToVectors() override;
        void use(Player&) override;
        friend ostream& operator<<(ostream&,Food&);
};
vector <Food*> Food::shop_items_food;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void Menu();

void printWithDelay() {}

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Factory {
public:
    static shared_ptr<Human> createCharacter(const string &name, const string &type);

private:
    static shared_ptr<Human> createJonSnow(const string &name);

    static shared_ptr<Human> createJaimeLannister(const string &name);

    static shared_ptr<Human> createDaenerys(const string &name);

    static shared_ptr<Human> createStannis(const string &name);

    static shared_ptr<Human> createJoffrey(const string &name);

    static shared_ptr<Human> createTheonGreyjoy(const string &name);
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

#endif