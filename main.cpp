#include"complex.h"
#include <iostream>

int main(void)
{
	Complex first;
	Complex second;
	Complex third;

	complexFunction::readComplex(first);
	complexFunction::readComplex(second);

	complexFunction::printComplex(first);
	std::cout << std::endl;

	complexFunction::printComplex(second);
	std::cout << std::endl;

	//third = complexFunction::addComplex(first, second);
	third = first + second;
	//complexFunction::printComplex(third);
	std::cout << third;
	std::cout << std::endl;

	//complexFunction::resetComplex(third);
	//complexFunction::printComplex(third);
	//std::cout << std::endl;

	std::cout << std::endl; std::cout << std::endl;
	std::cout << "ARRAY" << std::endl;


	Array myArray(3);

	myArray[0] = first;
	myArray[1] = second;
	myArray[2] = third;


	std::cout << myArray;
	std::cout << std::endl;

	std::cout <<myArray[2];
	std::cout << std::endl;

	std::cout << "Using U acess:";
	std::cout << myArray['U'];
	std::cout << std::endl;

	std::cout << "Using L acess:";
	std::cout << myArray['L'];
	std::cout << std::endl;


	std::cout << "Using overloaded () operator";
	std::cout << first(5);
	std::cout << std::endl;

	

	std::cout << complexFunction::distance(first, second) << std::endl;

	//std::cout << arrayFunction::polygonDistance(myArray) << std::endl;

	std::getchar();
	std::getchar();
	return 0;
}