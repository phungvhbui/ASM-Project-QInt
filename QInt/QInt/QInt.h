#pragma once
#include <iostream>
#include <bitset>
#include <string>
#include <map>
using namespace std;

typedef bitset<128> binary;

class QInt
{
private:
	binary bit;
public:
	QInt();
	QInt(const QInt& num);
	QInt(uint16_t mode, string s);

	//Converter
	string BinToDec();
	string BinToHex();
	static string DecToBin(string dec);
	static string HexToBin(string hex);
	static string CheckEven(string number);
	static string DivideBy2(string dec);

	//Operator
		//Arithmetic
	QInt& operator=(QInt const& Qint);
	QInt operator+(const QInt& Qint2);
	QInt operator-(const QInt& Qint2);
	QInt operator*(const QInt& Qint2);
	QInt operator/(const QInt& Qint2);
		//Bitwise
	QInt operator&(const QInt& Qint2);
	QInt operator|(const QInt& Qint2);
	QInt operator^(const QInt& Qint2);
	QInt& operator~();
	QInt operator>>(int step);
	QInt operator<<(int step);
	
	//Roll
	QInt rol();
	QInt ror();

	void printbit();
	string printAsMode(uint16_t mode);
	int* Addition(int* ResultArray, int* SaveNumber, int n, int i);
};

string normalize(string s);