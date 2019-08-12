#include "Header.h"
//#include <string>


drink::drink() :name("none"), price(0)
{
}

drink::drink(string name, int price) : name(name)
{
	setPrice(price);
}

string drink::getName() const
{
	return name;
}

int drink::getPrice() const
{
	return price;
}

void drink::setPrice(int price)
{
	if (price <= 0)
	{
		throw ("the price can not be lower 1");
	}
	else if (price >= INT_MAX)
	{
		throw ("the value is too large");
	}
	else
		this->price = price;
}

void drink::Print() const
{
	std::cout << name << std::endl;
	std::cout << "Price :" << price << std::endl;
	std::cout << "************************\n";
}

tea::tea() :drink("Tea", 1)
{
}

tea::tea(int price) : drink("Tea", price)
{
}

coffee::coffee() : drink("Coffee", 1)
{
}

coffee::coffee(int price) : drink("Coffee", price)
{
}

cappuccino::cappuccino() : drink("Cappuccino", 1)
{
}

cappuccino::cappuccino(int price) : drink("Cappuccino", price)
{
}

HotDrinksMachine::HotDrinksMachine()
{
	this->drinks.push_back(tea());
	this->drinks.push_back(coffee());
	this->drinks.push_back(cappuccino());
	//this->drinks.push_back({ tea(),coffee(),cappuccino() });
	this->setAmountOfSugar(amountOfSugar);
	this->setAmountOfTea(amountOfTea);
	this->setAmountOfWater(amountOfWater);
	this->setAmountOfCoffee(amountOfCoffee);
	this->setAmountOfMilk(amountOfMilk);

}

HotDrinksMachine::HotDrinksMachine(int amountOfWater, int quantityOfCoffee, int amountOfTea, int amountOfSugar)
{
	this->drinks.push_back(tea());
	this->drinks.push_back(coffee());
	this->drinks.push_back(cappuccino());
	this->setAmountOfSugar(amountOfSugar);
	this->setAmountOfTea(amountOfTea);
	this->setAmountOfWater(amountOfWater);
	this->setAmountOfCoffee(quantityOfCoffee);
}

void HotDrinksMachine::setAmountOfWater(int amountOfWater)
{
	if (amountOfWater <= 0)
	{
		throw ("the amount Of Water can not be lower 1");
		amountOfWater = 1;
	}
	else if (amountOfWater >= INT_MAX)
	{
		throw ("the value is too large");
	}
	this->amountOfWater = amountOfWater;
}

void HotDrinksMachine::setAmountOfCoffee(int quantityOfCoffee)
{
	if (quantityOfCoffee <= 0)
	{
		throw ("the quantityOfCoffee can not be lower 1");
		quantityOfCoffee = 1;
	}
	else if (amountOfWater >= INT_MAX)
	{
		throw ("the value is too large");
	}
	this->amountOfCoffee = quantityOfCoffee;
}

void HotDrinksMachine::setAmountOfTea(int amountOfTea)
{
	if (amountOfTea <= 0)
	{
		throw ("the amountOfTea can not be lower 1");
		amountOfTea = 1;
	}
	else if (amountOfWater >= INT_MAX)
	{
		throw ("the value is too large");
	}
	this->amountOfTea = amountOfTea;
}

void HotDrinksMachine::setAmountOfSugar(int amountOfSugar)
{
	if (amountOfSugar <= 0)
	{
		throw ("the amountOfSugar can not be lower 1");
		amountOfSugar = 1;
	}
	else if (amountOfWater >= INT_MAX)
	{
		throw ("the value is too large");
	}
	this->amountOfSugar = amountOfSugar;
}

void HotDrinksMachine::setAmountOfMilk(int amountOfMilk)
{
	if (amountOfMilk <= 0)
	{
		throw ("the amountOfMilk can not be lower 1");
		amountOfMilk = 1;
	}
	else if (amountOfWater >= INT_MAX)
	{
		throw ("the value is too large");
	}
	this->amountOfMilk = amountOfMilk;
}

void HotDrinksMachine::setCache(int cache)
{
	if (cache >= INT_MAX||cache<0)
	{
		throw ("cache overloaded");
	}
	else
		this->cache = cache;
}

int HotDrinksMachine::getAmountOfWater() const
{
	return this->amountOfWater;
}

int HotDrinksMachine::getAmountOfCoffee() const
{
	return this->amountOfCoffee;
}

int HotDrinksMachine::getAmountOfTea() const
{
	return this->amountOfTea;
}

int HotDrinksMachine::getAmountOfSugar() const
{
	return this->amountOfSugar;
}

int HotDrinksMachine::getAmountOfMilk() const
{
	return this->amountOfMilk;
}

int HotDrinksMachine::getCache() const
{
	return cache;
}

void HotDrinksMachine::makeCoffee(int howMuchSugar)
{
	if (howMuchSugar > amountOfSugar)
		throw ("not enough sugar");
	if (amountOfWater <= 0)
		throw ("not enough WATER");
	if (amountOfCoffee <= 0)
		throw ("not enough coffee");
	amountOfCoffee--;
	amountOfWater--;
	amountOfSugar -= howMuchSugar;
	setCache(cache + drinks[1].getPrice());
}

void HotDrinksMachine::makeTea(int howMuchSugar)
{
	if (howMuchSugar > amountOfSugar)
		throw ("not enough sugar");
	if (amountOfWater <= 0)
		throw ("not enough WATER");
	if (amountOfTea <= 0)
		throw ("not enough tea");
	amountOfTea--;
	amountOfWater--;
	amountOfSugar -= howMuchSugar;
	setCache(cache + drinks[0].getPrice());
}

void HotDrinksMachine::makeCappuccino(int howMuchSugar)
{
	if (howMuchSugar > amountOfSugar)
		throw ("not enough sugar");
	if (amountOfWater <= 0)
		throw ("not enough WATER");
	if (amountOfCoffee <= 0)
		throw ("not enough coffee");
	if (amountOfMilk <= 0)
		throw ("not enough milk");
	amountOfMilk--;
	amountOfCoffee--;
	amountOfWater--;
	amountOfSugar -= howMuchSugar;
		setCache(cache + drinks[2].getPrice());
}

void HotDrinksMachine::PrintDrinks()
{
	int i = 1;
	for (auto el : drinks)
	{
		std::cout << i << ")";
		el.Print();
		i++;
	}
}

void HotDrinksMachine::cleanCache()
{
	setCache(0);
}
using std::cout;
using std::cin;
using std::endl;
void HotDrinksMachine::AdminMenu()
{
	system("cls");
	int switcher = 0;
	cout << "Admin Menu\n";
	cout << "Cashe:" << cache << endl;
	cout << "Select:\n";
	cout << "1)Loading the machine\n";
	cout << "2)Output of statistics for the presence of constituents for the preparation of beverages\n";
	cout << "3)Changing prices for drinks\n";
	cout << "4)Removing a cache\n";
	cout << "5)Return to the main menu\n";
	cin >> switcher;
	cin.clear();
	system("cls");
	switch (switcher)
	{
	case 1:
	{
		int value = 0;
		cout << "Select:\n";
		cout << "1)Download water\n";
		cout << "2)Download tea\n";
		cout << "3)Download coffee\n";
		cout << "4)Download sugar\n";
		cout << "5)Download milk\n";
		cin >> switcher;
		cin.clear();
		switch (switcher)
		{
		case 1:
		{
			cout << "enter how water download:";
			cin >> value;
			cin.clear();
			if (value < 0)
				throw "it is impossible to download less than 0 ";
			this->setAmountOfWater(value + getAmountOfWater());
			break;
		}
		case 2:
		{
			cout << "enter how tea download:";
			cin >> value;
			cin.clear();
			if (value < 0)
				throw "it is impossible to download less than 0 ";
			this->setAmountOfTea(value + getAmountOfTea());
			break;
		}
		case 3:
		{
			cout << "enter how coffee download:";
			cin >> value;
			cin.clear();
			if (value < 0)
				throw "it is impossible to download less than 0 ";
			this->setAmountOfCoffee(value + getAmountOfCoffee());
			break;
		}
		case 4:
		{
			cout << "enter how sugar download:";
			cin >> value;
			cin.clear();
			if (value < 0)
				throw "it is impossible to download less than 0 ";
			this->setAmountOfSugar(value + getAmountOfSugar());
			break;
		}
		case 5:
		{
			cout << "enter how milk download:";
			cin >> value;
			cin.clear();
			if (value < 0)
				throw "it is impossible to download less than 0 ";
			this->setAmountOfMilk(value + getAmountOfMilk());
			break;
		}
		default:
		{
			cout << "error number\n";
			break;
		}
		}
		system("cls");
		break;
	}
	case 2:
	{
		cout << "Amount of coffee :" << getAmountOfCoffee() << endl;
		cout << "Amount of tea :" << getAmountOfTea() << endl;
		cout << "Amount of sugar:" << getAmountOfSugar() << endl;
		cout << "Amount of wather:" << getAmountOfWater() << endl;
		cout << "Amount of milk :" << getAmountOfMilk() << endl;
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		PrintDrinks();
		auto it = drinks.begin();
		cout << "Choose which drink to change the price:\n";
		cin >> switcher;
		cin.clear();
		cout << "Enter new price:\n";
		switch (switcher)
		{
		case 1:
		{
			cin >> switcher;
			cin.clear();
			drinks[0].setPrice(switcher);
			break;
		}
		case 2:
		{
			cin >> switcher;
			cin.clear();
			drinks[1].setPrice(switcher);
			break;
		}
		case 3:
		{
			cin >> switcher;
			cin.clear();
			drinks[2].setPrice(switcher);
			break;
		}
		default:
		{
			cout << "Error number!!\n";
		}
		}
		system("cls");
		break;
	}
	case 4:
	{
		this->cleanCache();
		break;
	}
	case 5:
	{
		while (true)
			MainMenu();
	}
	default:
	{		cout << "error number\n";
	break;
	}
	}

}

void HotDrinksMachine::UserMenu()
{
	system("cls");
	int switcher;
	cout << "Select a drink\n";
	cout << "1)" << drinks[0].getName() << "\t\t\t" << drinks[0].getPrice() << "\n";
	cout << "2)" << drinks[1].getName() << "\t\t" << drinks[1].getPrice() << "\n";
	cout << "3)" << drinks[2].getName() << "\t\t" << drinks[2].getPrice() << "\n";
	cout << "4)Return to the main menu\n";
	cin >> switcher;
	cin.clear();
	system("cls");
	cout << "How much sugar:\n";
	switch (switcher)
	{
	case 1:
	{
		cin >> switcher;
		cin.clear();
		try
		{
			makeTea(switcher);
		}
		catch (char *obj)
		{
			cout << obj << endl;
		}
		break;
	}
	case 2:
	{
		cin >> switcher;
		cin.clear();
		try
		{
			makeCoffee(switcher);
		}
		catch (char *obj)
		{
			cout << obj << endl;
		}
		break;
	}
	case 3:
	{
		cin >> switcher;
		cin.clear();
		try
		{
			makeCappuccino(switcher);
		}
		catch (char *obj)
		{
			cout << obj << endl;
		}
		break;
	}
	case 4:
	{
		while (true)
			MainMenu();
	}
	default:
		break;
	}
}

void HotDrinksMachine::MainMenu()
{
	system("cls");
	using std::string;
	int switcher;
	cout << "1)Login user\n";
	cout << "2)Login admin\n";
	cin >> switcher;
	switch (switcher)
	{
	case 1:
	{
		while (true)
		{
			try
			{
				UserMenu();
			}
			catch (const char* obj)
			{
				std::cout << obj << std::endl;
				system("pause");
				system("cls");
			}

		}
		break;
	}
	case 2:
	{
		const string pass("admin");
		string enter = " ";
		system("cls");
		cout << "Enter password:";
		cin >> enter;
		cin.clear();
		if (enter == pass)
		{
			while (true)
			{
				try
				{
					AdminMenu();
				}
				catch (const char* obj)
				{
					std::cout << obj << std::endl;
					system("pause");
					system("cls");
				}
			}
		}
		else
		{
			cout << "Invalid password\n";
			system("pause");
		}
		break;
	}
	default:
		break;
	}
}


