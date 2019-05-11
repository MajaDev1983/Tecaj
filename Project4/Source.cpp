#include <iostream>
#include <string>
#include <vector>
//polimorfizam vježba - RADI SAMO NA HEAPU, ALI NE NA STACKU!!! svaki auto je vozilo, ali svako vozilo nije auto. Radi se sa pointerima transformacije...
//virtual function table vježba - napravi tablicu i gleda koja je zapravo definicija funckije koja se naslijedila.

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

	virtual int getNumberOfHands() = 0; //pure virutal function (nema implentaciju u baznoj klasi), mora postojati implementacija unutar klasa koje naslijeðuju tu klasu - služi kao interface

private:

};

class Male : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a male human being!" << std::endl;
	}

	int getNumberOfHands()
	{
		return hands;
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

	int getNumberOfHands()
	{
		return hands;
	}
private:

};

int main()
{
	Male* maleObject = new Male(); //sad pozivamo memoriju na heapu (sporije) inaèe je sve na stacku (tamo su sve varijable)
	maleObject->hands = 2;
	maleObject->feet = 2;
	maleObject->eyes = 2;

	maleObject->PrintType();
	
	Female* femaleObject = new Female();
	femaleObject->PrintType();

	//Human* humanObject = new Human(); //zakomentirano da bi se pokazala kako radi true virtual

	std::vector<Human*> humans;
	humans.push_back(maleObject);
	humans.push_back(femaleObject);
	//humans.push_back(humanObject);

	std::cout << "==========================================" << std::endl;

	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->PrintType();
		std::cout << humans[i]->getNumberOfHands() << std::endl;
	}

	std::cin.get();

	delete femaleObject;
	delete maleObject;
}