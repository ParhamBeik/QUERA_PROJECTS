#ifndef OTHER
#define OTHER

#include<iostream>
#include<string>
#include <memory>
#include <vector>
#include<algorithm>
#include <thread>
#include <chrono>

#include "Items.h"

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
    public:
        Experience() : maximum(0), currentExp(0) {}
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