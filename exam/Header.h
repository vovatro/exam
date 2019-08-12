#pragma once
#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
class drink
{
	string name;
	int price;
public:
	drink();
	drink(string name,int price);
	string getName()const;
	int getPrice()const;
	void setPrice(int price);
	virtual void Print()const;
};

class tea:public drink
{
public:
	tea();
	tea(int price);
};

class coffee :public drink
{
public:
	coffee();
	coffee(int price);
};

class cappuccino:public drink
{
public:
	cappuccino();
	cappuccino(int price);
};

class HotDrinksMachine
{
	vector<drink>drinks;
	int cache;
	int amountOfWater;
	int amountOfCoffee;
	int amountOfTea;
	int amountOfSugar;
	int amountOfMilk;
public:
	HotDrinksMachine();
	HotDrinksMachine(int amountOfWater, int quantityOfCoffee, int amountOfTea, int amountOfSugar);
	void setAmountOfWater(int amountOfWater);
	void setAmountOfCoffee(int quantityOfCoffee);
	void setAmountOfTea(int amountOfTea);
	void setAmountOfSugar(int amountOfSugar);
	void setAmountOfMilk(int amountOfMilk);
	void setCache(int cache);

	int getAmountOfWater()const;
	int getAmountOfCoffee()const;
	int getAmountOfTea()const;
	int getAmountOfSugar()const;
	int getAmountOfMilk()const;
	int getCache()const;

	void makeCoffee(int howMuchSugar);
	void makeTea(int howMuchSugar);
	void makeCappuccino(int howMuchSugar);

	void PrintDrinks();

	void cleanCache();

	void AdminMenu();
	void UserMenu();
	void MainMenu();
};