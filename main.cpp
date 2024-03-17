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

int main(){
	createWarmWeapons();
	createColdWeapons();
	createThrowableItems();
	createMedicines();
	createFoods();
	ShopMenu();
}