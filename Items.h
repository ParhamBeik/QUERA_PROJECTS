#ifndef ITEMS
#define ITEMS

#include<iostream>
#include<string>
#include <memory>
#include <vector>
#include<algorithm>
#include <thread>
#include <chrono>

#include "Other.h"
#include "Person.h"

using namespace std;

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

#endif