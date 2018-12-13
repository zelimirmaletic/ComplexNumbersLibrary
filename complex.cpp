#include "complex.h"
#include <cmath>

//CLASS COMPLEX
std::ostream & operator<<(std::ostream &output, const Complex &myNumber)
{
	output << "(" << myNumber.realPart << "," << myNumber.imagPart << ")";
	output << std::endl;
	return output;
}
std::istream & operator>>(std::istream &input, const Complex &myNumber)
{
	input >> myNumber.realPart >> myNumber.imagPart;
	return input;
}
Complex Complex::operator+(Complex number)
{
	number.realPart += realPart;
	number.imagPart += imagPart;
	return number;
	//Here we do not have side effects, since the number is a copy of real argument
	//copy constructor was called
}
Complex Complex::operator()(double CONST)
{
	Complex tmp;
	tmp.setReal(this->getReal()*CONST);
	tmp.setImag(this->getImag()*CONST);
	return tmp;
}

Complex complexFunction::addComplex(const Complex first, const Complex second)
{
	Complex tmp;
	tmp.setImag(first.getImag() + second.getImag());
	tmp.setReal(first.getReal() + second.getReal());
	return tmp;
}
double complexFunction::distance(const Complex first, const Complex second)
{
	return sqrt(pow(first.getReal() - second.getReal(), 2) + pow(second.getImag() - first.getImag(), 2));
}
double complexFunction::distance(const Complex number)
{
	return sqrt(pow(number.getReal(), 2) + pow(number.getImag(), 2));
}
void complexFunction::printComplex(const Complex myNumber)
{
	std::cout << "(" << myNumber.getReal() << "," << myNumber.getImag() << ")";
}
void complexFunction::readComplex(Complex &myNumber)
{
	double tmp;
	std::printf("\tReal part:");
	std::cin >> tmp;
	myNumber.setReal(tmp);
	std::printf("\n\tImaginary part:");
	std::cin >> tmp;
	myNumber.setImag(tmp);
	std::cout << std::endl;
}
void complexFunction::resetComplex(Complex &myNumber)
{
	myNumber.reset();
}

//CLASS ARRAY


Array::Array(const int number):numberOfElements(number)
{
	if (number == 0)
		complexArray = nullptr;
	else
		complexArray = new Complex[number];
}
Array::Array(const Array &myArray)
{
	copy(myArray);
}
Array::Array(Array &&myArray)
{
	move(std::move(myArray));
}



Array & Array::operator=(const Array &myArray)
{
	if (this != &myArray)
	{
		delete[] this->complexArray;
		copy(myArray);
	}
	return *this;
}

Array & Array::operator=(Array &&myArray)
{
	if (this != &myArray)
	{
		delete[] this->complexArray;
		move(std::move(myArray));
	}
	return *this;
}

Array & Array::operator+=(const Array &myArray)
{
	if (this != &myArray && this->getNumberOfElements() == myArray.numberOfElements)
	{
		if (myArray.complexArray != nullptr)
		{
			for (int i = 0; i < myArray.numberOfElements; ++i)
			{
				complexArray[i].setReal(complexArray[i].getReal() + myArray.complexArray[i].getReal());
				complexArray[i].setImag(complexArray[i].getImag() + myArray.complexArray[i].getImag());
			}
		}
	}
	return *this;
}

Complex &Array::operator[](int i)
{
	if (i<0 and i>numberOfElements - 1)
		exit(1);
	return complexArray[i];
}

const Complex &Array::operator[](int i) const
{
	if (i<0 and i>numberOfElements - 1)
		exit(1);
	return complexArray[i];
}

Complex &Array::operator[](char criteria)
{
	if (!complexArray)
		exit(1);
	else if (criteria == 'U')//returns maximal(upper) element in array
	{
		int element=0;
		double max = 0;
		for (int i = 0; i < numberOfElements; ++i)
		{
			if (complexFunction::distance(complexArray[i]) >= max)
				element = i;
		}
		return complexArray[element];
	}
	else if (criteria == 'L')//returns minimal(lower) element in array
	{
		int element=0;
		double min = 0;
		for (int i = 0; i < numberOfElements; ++i)
		{
			if (complexFunction::distance(complexArray[i]) < min)
				element = i;
		}
		return complexArray[element];
	}
}

void Array::copy(const Array &myArray)
{
	if (myArray.complexArray != nullptr)
	{
		complexArray = new Complex[myArray.numberOfElements];
		for (int i = 0; i < myArray.numberOfElements; i++)
			complexArray[i] = myArray.complexArray[i];
	}
	else
	{
		complexArray = nullptr;
		numberOfElements = 0;
	}
}

void Array::move(Array &&other)
{
	numberOfElements = std::move(other.numberOfElements);
	complexArray = std::move(other.complexArray);
	other.complexArray = nullptr;
}

void Array::emptyArray(void)
{
	numberOfElements = 0;
	delete[] complexArray;
	complexArray = nullptr;
}

std::ostream & operator<<(std::ostream &output, Array &myArray)
{
	for (int i = 0; i < myArray.numberOfElements; i++)
		output << "(" << myArray.complexArray[i].getReal() << "," << myArray.complexArray[i].getImag() << ") ";
	return output;
}



/*
double arrayFunction::polygonDistance(const Array myArray)
{
	double distanceSum = 0.0;
	for (int i = 0; i < myArray.getNumberOfElements()-1; i++)
	{
		distanceSum += complexFunction::distance(myArray.getElement(i) , myArray.getElement(i + 1));
	}
	distanceSum += complexFunction::distance(myArray.getElement(0), myArray.getElement(myArray.getNumberOfElements() - 1));
	return distanceSum;
}
*/





