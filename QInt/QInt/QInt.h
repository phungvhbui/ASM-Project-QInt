#pragma once
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

typedef bitset<128> binary;
#define ONE QInt(2, "1");

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

	//friend string HexToDec(string hex);
	//friend string DecToHex(string dec);

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

	friend void print(QInt x);
};