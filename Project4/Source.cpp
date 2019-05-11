#include <iostream>
#include <string>
#include <vector>
//polimorfizam vje�ba - RADI SAMO NA HEAPU SAMO RADI; ALI NE NA STACKU!!!
//virtual function table vje�ba - napravi tablicu i gleda koja je zapravo definicija funckije koja se naslijedila

class Human
{
public:

	int hands;
	int feet;
	int eyes;

	virtual void PrintType()
	{
		std::cout << "I am a human being!" << std::endl;
	}

private:

};

class Male : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a male human being!" << std::endl;
	}

private:

};

class Female : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a female human being!" << std::endl;
	}
private:

};

int main()
{
	Male* maleObject = new Male(); //sad pozivamo memoriju na heapu (sporije) ina�e je sve na stacku (tamo su sve varijable)
	maleObject->hands = 2;
	maleObject->feet = 2;
	maleObject->eyes = 2;

	maleObject->PrintType();
	
	Female* femaleObject = new Female();
	femaleObject->PrintType();

	Human* humanObject = new Human();

	std::vector<Human*> humans;
	humans.push_back(maleObject);
	humans.push_back(femaleObject);
	humans.push_back(humanObject);

	std::cout << "==========================================" << std::endl;

	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->PrintType();
	}

	std::cin.get();
}