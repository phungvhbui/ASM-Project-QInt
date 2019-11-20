#include "QInt.h"

QInt::QInt()
{
	this->bit = QInt(2, "0").bit;
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
QInt& QInt::operator=(QInt const& Qint)
{
	this->bit = Qint.bit;
	return (*this);
}

QInt QInt::operator+(const QInt& Qint2)
{
	QInt result;
	int carry = 0;
	/*while (Qint2.bit != 0) {
		for (int i = 0; i < this->bit.size(); i++) {
			carry.bit[i] = this->bit[i] & Qint2.bit[i];
		}
		this->bit = this->bit ^ Qint2.bit;

	}*/

	for (int i = 0; i < this->bit.size(); i++) {
		if (this->bit[i] == 0 && Qint2.bit[i] == 0) {
			result.bit[i] = 0 ^ carry;
			carry = 0;
		}
		else if ((this->bit[i] & Qint2.bit[i]) == 0) {
			if (carry == 1) {
				result.bit[i] = 0;
				carry = 0;
				carry++;
			}
			else if (carry == 0) {
				result.bit[i] = 1;
			}
		}
		else
		{
			result.bit[i] = (this->bit[i] ^ Qint2.bit[i]) ^ carry;
			carry = 0;
			carry++;
		}
		//if((carry == 1 && (this->bit[i] == 1 || Qint2.bit[i] == 1)) || (carry == 1 && (this->bit[i] == 1 && Qint2.bit[i] == 1)) || (carry == 0 && (this->bit[i] == 1 && Qint2.bit[i] == 1)))
	}


	return result;
}

QInt QInt::operator-(const QInt& Qint2)
{
	QInt result, temp = Qint2;
	temp = ~temp;
	temp = temp + ONE;
	result = *this + temp;
	return result;
}

QInt QInt::operator*(const QInt& Qint2)
{
	QInt result,temp;
	for (int i = 0; i < Qint2.bit.size(); i++) {
		if (Qint2.bit[i] == 1) {
			result = result + *this;
		}
		this->bit = this->bit << 1;
	}
	return result;
}

QInt QInt::operator/(const QInt& Qint2)
{
	return QInt();
}


//Bitwise
QInt QInt::operator&(const QInt& Qint2)
{
	string result = QInt().bit.to_string();
	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == '1' && value2[i] == '1')
			result[i] = '1';
		else
			result[i] = '0';
	}

	return QInt(2, result);
}

QInt QInt::operator|(const QInt& Qint2)
{
	string result = QInt().bit.to_string();
	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == '0' && value2[i] == '0')
			result[i] = '0';
		else
			result[i] = '1';
	}

	return QInt(2, result);
}

QInt QInt::operator^(const QInt& Qint2)
{
	string result = QInt().bit.to_string();
	string value1 = this->bit.to_string();
	string value2 = Qint2.bit.to_string();

	for (int i = 0; i < value1.size(); i++) {
		if (value1[i] == value2[i])
			result[i] = '0';
		else
			result[i] = '1';
	}

	return QInt(2,result);
}

QInt& QInt::operator~()
{

	for (int i = 0; i < this->bit.size(); i++) {
		if (this->bit[i] == 0)
			this->bit[i] = 1;
		else if (this->bit[i] == 1)
			this->bit[i] = 0;
	}
	return *this;
}

QInt QInt::operator>>(int step)
{
	
	return *this;
}

QInt QInt::operator<<(int step)
{
	return QInt();
}

void print(QInt x)
{
	//string output = x.bit.to_string();

 	for (int i = x.bit.size() - 1; i >=0 ; i--) {
		cout << x.bit[i];
	}
}

