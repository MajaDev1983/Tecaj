#include <iostream>
#include <string>
#include <vector>

class Person
{
public:
	
	Person(std::string givenName, std::string givenLastName, std::string givenAddress)
	{
		_name = givenName;
		_lastName = givenLastName;
		_address = givenAddress;
	}

	~Person();
	
	bool trysetSSN(std::string ssn)
	{
		if (_socialSecuritiNumber != "")
		{
			std::cout << "Social Security Number is already set!" << std::endl;
			std::cout << "Persons SSN cannot be changed!" << std::endl;
			return true;
		}

		if (ssn.size() != 11)
		{
			std::cout << "Social Security Number is invalid! Wrong numer of characters!" << std::endl;
			return false;
		}

		for (size_t i = 0; i < ssn.size(); i++)
		{
			char current = ssn[i];
			if (current < 0 || current > 9)
			{
				std::cout << "Social Security Number is invalid!" << std::endl;
				std::cout << "Character at index " << i << " is invalid!" << std::endl;
				return false;
			}
		}
		_socialSecuritiNumber = ssn;
		return true;
	}

	void print()
	{
		std::cout << "Name: " << _name << " " << _lastName << std::endl;
		std::cout << "Address: " << _address << " " << std::endl;
		std::cout << "Social Security Number: " << _socialSecuritiNumber << std::endl;
	}

private:
	std::string _name, _lastName, _address, _socialSecuritiNumber;
};

void dispalyPersons(std::vector<Person> persons)
{
	for (size_t i = 0; i < persons.size(); i++)
	{
		persons[i].print;
	}
}

void inputNewData(std::string message, std::string& data)
{
	std::cout << "Enter new persons name: " << std::endl;
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

void createPerson(std::vector<Person>& person)
{
	std::string name, lastName, address;
	
	std::cout << "Enter new persons name: " << std::endl;
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::cout << "Enter new persons laste name: " << std::endl;
	std::cin >> lastName;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::cout << "Enter new persons address: " << std::endl;
	std::cin >> address;
	std::cin.clear();
	std::cin.ignore(10000, '\n');


	Person person = Person(name, lastName, address);
	std::string ssn;

	while (true)
	{
		std::cout << "Enter new social security number: " << std::endl;
		std::cin >> ssn;
		if (person.trysetSSN(ssn))
		{

		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
};



int main()
{
	//Zadatak:
	//Napraviti klasu osobe, sadržava ime, prezime, adresu, oib
	//Konstruktor treba inicijalizirate sve memebere osim oiba
	//Posebna metoda za setanje oiba, probjeriti jel valjan oib ili postojeci, te na temelju toga namjestiti oib
	//Napraviti probram koji omogucuje izradu novih osoba i iima mogucnost printanja svih unesenih osoba

	std::vector<Person> persons;

	while (true)
	{
		std::cout << "What do you want to do: " << std::endl;
		std::cout << "1 - Add new person" << std::endl;
		std::cout << "2 - Exit" << std::endl;
		
		int choice;
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		switch (choice)
		{
		case 1:
			createPerson(persons);
			break;
		case 2:
			return;
		default:
			break;
		}


	}

	std::cin.get();


}