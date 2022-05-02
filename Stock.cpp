#include <iostream>
#include <fstream>

using namespace std;

#include "Stock.h"

void processMenu(const string);

template <typename T>
void insertStock(ifstream&, const Stock<T>&);

template <typename T>
void getStock(Stock<T>&);

void displayAll(istream&);
string displayName(istream&, const string);
char getChoice();
string getSymbol();
double displayPrice(const string);

template <typename T>
int main()
{
    Stock<T> s("","",0);
    string sym = "";
    char choice = 'x';
    ifstream stockFile;

    stockFile.open("Stocks.txt");

    do
    {        
        processMenu(sym);

        choice = toupper(getChoice());
        
        switch (choice)
        {
        case 'A':
            sym = getSymbol();
            displayName(stockFile, sym);
            break;
        case 'B':
            sym = getSymbol();
            displayPrice(sym);
            break;
        case 'C':
            displayAll(stockFile);
            break;
        case 'D':
            getStock(s);
            insertStock(stockFile, *s);
            break;
        default:
            cout << "\nThat was not a valid choice." << endl;
        }
    } while (choice != 'Q');

    cout << "Program Terminated.\n" << endl;

    return 0;
}

void processMenu(string s)
{
    cout << "\n\n" << string(40, '*') << endl;
    cout << "Select a menu option from below..." << endl;
    cout << "A. Find a stock by symbol." << endl;
    cout << "B. Find stock price by symbol." << endl;
    cout << "C. Display all stocks on file." << endl;
    cout << "D. Insert a new stock to file." << endl;
    cout << "Q. Quit." << endl;
    cout << "Please enter your choice: ";
}

char getChoice()
{
    char choice;
    
    cin >> choice;

    return choice;
}

template <typename T>
void insertStock(ifstream& os, Stock<T>& s)
{
    os << s;
}

template <typename T>
string getSymbol()
{
    string *st;
    
    cout << "\nEnter the stock symbol: ";
    cin.get(st);

    char tmp [st.length() + 1];
    strcpy(tmp, toupper(st.c_str()));

    st = tmp;

    delete[] tmp;

    return st;
}

template <typename T>
void displayPrice(istream& is, string s)
{
    Stock<T>* tmp;
    string name;
    double p;

    is >> tmp;

    while (tmp.symbol != s)
    {
        is >> tmp;
    }

    if (tmp.symbol == s)
        p = tmp.getPrice();

    cout << p;
}

template<typename T>
void getStock(Stock<T>& s)
{
    Stock t = new Stock();
    string* symbol;
    string name;
    double price;

    cout << "Insert stock symbol: ";
    cin.get(symbol);
    cin.ignore();
    char tmp[symbol.length() + 1];
    strcpy(tmp, toupper(symbol.c_str()));
    symbol = tmp;
    t.symbol = tmp;
    delete[]tmp;

    cout << "Insert stock name: ";
    cin >> name;
    cin.ignore();
    t.name = name;

    cout << "Enter stock price: ";
    cin >> price;
    t.price = price;

    return t;
}

template <typename T>
void displayAll(istream& i)
{
    Stock<T>* s = new Stock();
    while (!(i.eof()))
    {
        i >> s;

        cout << s << endl;
    }
}