#include <iostream>
#include <string>
#include <vector>
#define PI 3.14159

//Zadatak:
//Napraviti interface Shape koji ima metode Area i Perimeter
//Napraviti klase Triangle(a+b+c), Circle(2*PI*r), Square(4*a) koji implementiraju interface Shape:
//Napraviti objekte svake podklase i ispisati Area i Perimeter (opseg i površina)

class Shape
{
public:
	virtual std::string ime() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;

};

class Triangle : public Shape
{
public:
	
	float a, b, c;

	std::string ime()
	{
		return "Trokut";
	}

	double area()
	{
		double s = ((a + b + c) / 2);
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	double perimeter()
	{
		return a + b + c;
	}

private:

};

class Circle : public Shape
{
public:

	float r;

	std::string ime()
	{
		return "Krug";
	}
	
	double area()
	{
		return (r * r * PI);
	}

	double perimeter()
	{
		return (2 * r * PI);
	}

private:

};

class Rectangle : public Shape
{
public:

	float a, b;
	
	std::string ime()
	{
		return "Pravokutnik";
	}

	double area()
	{
		return  (a * b);
	}

	double perimeter()
	{
		return (2 * a + 2 * b);
	}

private:

};

void printShapeInfo(Shape* shape)
{
	std::cout << "Ime oblika: " << shape->ime() << std::endl;
	std::cout << "Povrsina je: " << shape->area() << std::endl;
	std::cout << "Opseg je: " << shape->perimeter() << std::endl;
	std::cout << "==========================================" << std::endl;
}


int main()
{
	std::cout << "This program calulates perimeter and area of different shapes!" << std::endl;
	std::cout << "Which shape do you want to choose?" << std::endl;
	std::cout << "Press 1 for triangle" << std::endl;
	std::cout << "Press 2 for circle" << std::endl;
	std::cout << "Press 3 for rectangle" << std::endl;
	int ordinalNumber;
	std::cin >> ordinalNumber;
	
	switch (ordinalNumber)
	{
	case 1: 
		Triangle* trokut = new Triangle();
		std::cout << "Enter the sides of a triangle: " << std::endl;
		std::cin >> trokut->a;
		std::cin >> trokut->b;
		std::cin >> trokut->c;

	case 2:
		Circle* krug = new Circle();
		std::cout << "Enter the radius of a circle: " << std::endl;
		std::cin >> krug->r;

	case 3:
		Rectangle* pravokutnik = new Rectangle();
		std::cout << "Enter the sides of a rectangle: " << std::endl;
		std::cin >> pravokutnik->a;
		std::cin >> pravokutnik->b;
	
	default:
		break;
	}

	




	std::vector<Shape*> oblici;
	oblici.push_back(trokut);
	oblici.push_back(krug);
	oblici.push_back(pravokutnik);

	for (Shape* it : oblici)
	{
		printShapeInfo(it);
	}

	//dodaj apstrakciju za printanje funkcije pogledaj na githubu... DONE!

	//zadatak za doma...sve da može korisnik sam unjeti

	std::cin.get();
}