#include <iostream>
#include <utility>
#include <algorithm>

class Complex
{
	double realPart;
	double imagPart;
public:
	inline Complex(const double real = 0.0, const double imag = 0.0) :realPart(real), imagPart(imag) {}
	~Complex() = default;
	constexpr double getReal(void) const { return realPart; }
	constexpr double getImag(void) const { return imagPart; }
	inline void setReal(const double real) { realPart = real; }
	inline void setImag(const double imag) { imagPart = imag; }
	inline void reset(void) { realPart = 0.0; imagPart = 0.0; }
	inline Complex &operator++() { ++realPart; return *this; }//prefix
	inline Complex operator++(int k) { Complex tmp = *this; realPart++; imagPart += k; return tmp; }//postfix
	inline Complex &operator--() { --realPart; return *this; }//prefix
	inline Complex operator--(int k) { Complex tmp = *this; realPart--; imagPart -= k; return tmp; }//postfix
	explicit operator double() { return sqrt(pow(realPart, 2) + pow(imagPart, 2)); };
	Complex operator+(Complex);
	Complex operator()(double);
	inline void *operator new(size_t size) { void *p = new Complex(); return p; }
	inline void operator delete(void *p) { delete p; }
	friend std::ostream &operator<<(std::ostream &, const Complex &);
	friend std::istream &operator>>(std::istream &, const Complex &);
};
namespace complexFunction
{
	//First three functions should be replaced by overloaded operators
	void readComplex(Complex &);
	void printComplex(const Complex);
	Complex addComplex(const Complex, const Complex);
	void resetComplex(Complex &);
	double distance(const Complex, const Complex);
	double distance(const Complex);
	//Other functions to consider:
	//double abs(const Complex);
	//double arg(Complex);
	//double conj(const Complex);
	//Complex polar(const double, const double);
	//Complex exComplex(const Complex, double);
	//Complex logComplex(const Complex);
	//Complex sqrtComplex(const Complex);
}

class Array
{
	Complex *complexArray;
	int numberOfElements;
	friend std::ostream &operator<<(std::ostream &, Array &);
public:
	Array(const int number=0);
	Array(const Array &);
	Array(Array &&);
	inline ~Array() { emptyArray(); }
	constexpr int getNumberOfElements(void) { return numberOfElements; }
	inline Complex *getArray(void) const { return complexArray; }//????
	Array &operator=(const Array &);
	Array &operator=(Array &&);
	Array &operator+=(const Array &);
	Complex &operator[](int);
	const Complex &operator[](int) const;
	Complex &operator[](char);
	private:
		void copy(const Array &);
		void move(Array &&);
		void emptyArray(void);
};

namespace arrayFunction
{
	double polygonDistance(const Array);
}