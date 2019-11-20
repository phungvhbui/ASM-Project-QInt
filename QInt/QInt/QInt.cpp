#include "QInt.h"

QInt::QInt()
{
	this->bit = binary(0);
}

QInt::QInt(const QInt& num)
{
	this->bit = num.bit;
}

QInt::QInt(uint16_t mode, string s)
{
	if (mode == 2)
		this->bit = binary(s);

	else if (mode == 10) {
		bool isNegative = false;
		if (s[0]=='-')
		{
			isNegative = true;
			s = s.substr(1);
		}

		this->bit = binary(DecToBin(s));

		if (isNegative)
		{
			bit = ~bit;
			*this = *this + ONE;
		}
	}

	else if (mode == 16)
		this->bit = binary(HexToBin(s));
}

string QInt::BinToDec()
{
	return string();
}

string QInt::BinToHex()
{
	return string();
}

string QInt::DecToBin(string dec)
{
	return string();
}

string QInt::HexToBin(string hex)
{
	return string();
}

//Arithmetic
QInt QInt::operator=(QInt const& Qint)
{
	this->bit = Qint.bit;
	return (*this);
}

QInt QInt::operator+(const QInt& Qint2)
{
	return QInt();
}

QInt QInt::operator-(const QInt& Qint2)
{
	return QInt();
}

QInt QInt::operator*(const QInt& Qint2)
{
	
	return QInt();
}

QInt QInt::operator/(const QInt& Qint2)
{
	return QInt();
}


//Bitwise
QInt QInt::operator&(const QInt& Qint2)
{
	QInt result;
	string result_string = result.bit.to_string();

	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == 1 && value2[i] == 1)
			result_string[i] = 1;
		else
			result_string[i] = 0;
	}

	result.bit = binary(result_string);

	return result;
}

QInt QInt::operator|(const QInt& Qint2)
{
	QInt result;
	string result_string = result.bit.to_string();

	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == 0 && value2[i] == 0)
			result_string[i] = 0;
		else
			result_string[i] = 1;
	}

	result.bit = binary(result_string);

	return result;
}

QInt QInt::operator^(const QInt& Qint2)
{
	QInt result;
	string result_string = result.bit.to_string();

	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == value2[i])
			result_string[i] = 0;
		else
			result_string[i] = 1;
	}

	result.bit = binary(result_string);

	return result;
}

QInt QInt::operator~()
{
	QInt result;
	string value = this->bit.to_string();

	for (int i = 0; i < value.size(); i++) {
		if (value[i] == 0)
			value[i] == 1;
		else if (value[i] == 1)
			value[i] == 0;
	}

	result.bit = binary(value);

	return result;
}

QInt QInt::operator>>(int step)
{
	return QInt();
}

QInt QInt::operator<<(int step)
{
	return QInt();
}

