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
    public:
        Health hp;
        Person(string n) : name(n), level(1) {}
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
        Experience(Human*);
        void updateMaximum();
        void setCurrentExp(int,int,int);
        void increaseExp(int);
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
    private:
        map <Food , int> FoodItems;
        map <Medicine , int> MedicineItems;
        map <Throwable , int> ThrowableItems;
        vector <WarmWeapon> WarmWeaponItems;
        vector <ColdWeapon> ColdWeaponItems;
        void removeFoodItem(const Food);
        void removeMedicineItem(const Medicine);
        void removeThrowableItem(const Throwable);
    public:
        Backpack(){}
        void addFoodItem(const Food,int);
        void addMedicineItem(const Medicine,int);
        void addThrowableItem(const Throwable,int);
        void addWarmWeaponItem(const WarmWeapon);
        void addColdWeaponItem(const ColdWeapon);
        bool warmWeaponExistence(const WarmWeapon);
        bool coldWeaponExistence(const ColdWeapon);
        void useFoodItemCount(const Food specificItem);
        void useMedicineItemCount(const Medicine specificItem);
        void useThrowableItemCount(const Throwable specificItem);
        void showItems();
};

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class BankAccount {
    protected:
        int balance;
    public:
        BankAccount(int);
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
        virtual void addToVectors(){}                    //add the bought item to the vector
        bool operator==(const Items&) const;             //check equality of two object based on names
        bool operator<(const Items&) const;
        string getName();
        string getType();
}; 
vector <Items*> Items::shop_items;     

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

class Permanent : public Items {
    protected:
        int harm;
        int exp;
        static vector <Permanent*> shop_items_permanent;
        Permanent(string,int,string,int,int); 
    public:       
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
        WarmWeapon(string,int,int,int,int);
        static void showItems();                     //show the available items to buy
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
        ColdWeapon(string,int,int,int,int);
        static void showItems();                     //show the available items to buy
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
        int harm;
        int exp;
        static vector <Throwable*> shop_items_throwable;
        ThrowableWeaponAbility twa;
    public:
        Throwable(string,int,int,int,int);
        static void showItems();                     //show the available items to buy
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
        static void showItems();                     //show the available items to buy
        void buy(Player&,int);
        void addToVectors() override;
        void use(Human&);
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
        static void showItems();                     //show the available items to buy
        void buy(Player&,int);
        void addToVectors() override;
        void use(Human&);
        friend ostream& operator<<(ostream&,Food&);
};
vector <Food*> Food::shop_items_food;

// *----------------------------------------------------------------*
// *----------------------------------------------------------------*
// *----------------------------------------------------------------*

void Menu();

void printWithDelay() {}

void ShopMenu();
void Show_Permanent_Items();
void Show_Throwable_Items();
void Show_Consumable_Items();
void createWarmWeapons();
void createColdWeapons();
void createThrowableItems();
void createMedicines();
void createFoods();

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