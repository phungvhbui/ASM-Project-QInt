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

QInt QInt::operator=(QInt const& Qint)
{
	this->bit = Qint.bit;
	return (*this);
}