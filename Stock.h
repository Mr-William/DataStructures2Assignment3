#ifndef STOCK_H
#define STOCK_H

#include <iostream>

using namespace std;

template <typename T>
class Stock
{
private:
	string name;
	string symbol;
	double price;
public:
	Stock(string, string,double);
	Stock(const Stock&);
	void display() const;
	string getName() const;
	string getSymbol() const;
	double getPrice() const;
	int hash(int);
	bool operator ==(const Stock&) const;
	bool operator !=(const Stock&) const;
	friend ostream& operator <<(ostream&, const Stock&);
	friend istream& operator >>(istream&, Stock&);
};

template <typename T>
Stock<T>::Stock(string n, string s , double p)
{
	name = p;
	symbol = s;
	price = p;
}

template <typename T>
Stock<T>::Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

template <typename T>
void Stock<T>::display()const
{
	Stock s;
	s.name = getName();
	s.symbol = getSymbol();
	s.price = getPrice();

	cout << s;
}

template <typename T>
string Stock<T>::getName()const
{
	return name;
}

template <typename T>
string Stock<T>::getSymbol()const
{
	return symbol;
}

template <typename T>
double Stock<T>::getPrice()const
{
	return price;
}

template <typename T>
bool Stock<T>::operator==(const Stock& rhs) const
{
	return rhs.symbol == symbol;
}

template <typename T>
bool Stock<T>::operator!=(const Stock& rhs) const
{
	return !(rhs.symbol == symbol);
}

template <typename T>
int Stock<T>::hash(int size)
{
	return size % 10;
}

template <typename T>
ostream& operator <<(ostream& os, const Stock<T>& s)
{
	os << s.getName() << endl;
	os << s.getSymbol() << endl;
	os << s.getPrice() << endl;

	return os;
}

template <typename T>
istream& operator >>(istream& is, Stock<T>& s)
{
	is >> s.name;
	is >> s.symbol;
	is >> s.price;
}
#endif