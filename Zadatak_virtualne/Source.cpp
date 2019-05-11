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

	double a, b, c, r;

	virtual std::string ime() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;

private:

};

class Triangle : public Shape
{
public:
	
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

class Square : public Shape
{
public:

	std::string ime()
	{
		return "Kvadrat";
	}

	double area()
	{
		return  (a * a);
	}

	double perimeter()
	{
		return (4 * a);
	}

private:

};



int main()
{
	Triangle* trokut = new Triangle();
	trokut->a = 3.8;
	trokut->b = 4.2;
	trokut->c = 2.2;
	
	Circle* krug = new Circle();
	krug->r = 2.6;

	Square* kvadrat = new Square();
	kvadrat->a = 5.0;

	std::vector<Shape*> oblici;
	oblici.push_back(trokut);
	oblici.push_back(krug);
	oblici.push_back(kvadrat);

	for (Shape* it : oblici)
	{
		std::cout << "Ime oblika: " << it->ime() << std::endl;
		std::cout << "Povrsina je: " << it->area() << std::endl;
		std::cout << "Opseg je: " << it->perimeter() << std::endl;
		std::cout << "==========================================" << std::endl;
	}

	//dodaj apstrakciju za printanje funkcije pogledaj na githubu...
	//zadatak za doma...sve da može korisnik unjeti

	std::cin.get();
}