#include <iostream>
#include <string>

int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	std::string* stringptr;
	//void* ptr = &number;
	std::string someWord = "Nesto";
	//ptr = (void*)&someWord;
	stringptr = &someWord;
	int** doubleptr = &ptr;

	number = 9;
	
	std::cout << "Hello world" << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "tracker: " << tracker << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "stringptr: " << stringptr << std::endl;

	std::cout << "derefference strinptr: " << *stringptr << std::endl;
	*stringptr = "nesto drugo";
	std::cout << "derefference strinptr take two: " << *stringptr << std::endl;
	std::cout << "doubleptr ptr address: " << *doubleptr << std::endl;
	std::cout << "value: " << **doubleptr << std::endl;

	std::cin.get();

	return 0;
}