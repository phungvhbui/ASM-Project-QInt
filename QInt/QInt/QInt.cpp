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
		if (s[0] == '-')
		{
			isNegative = true;
			s = s.substr(1);
		}

		this->bit = binary(DecToBin(s));

		if (isNegative)
		{
			bit = ~bit;
			*this = *this + QInt(2, "1");
		}
	}

	else if (mode == 16)
		this->bit = binary(HexToBin(s));
}

string QInt::BinToDec()
{
	int negative = false;
	if ((*this).bit[127] == 1)
		negative = true;

	if (negative) {
		*this = *this - QInt(2, "1");
		*this = ~(*this);
	}

	int result = 0;
	for (int i = 0; i < (*this).bit.size(); i++) {
		if ((*this).bit[i] == 1)
			result += pow(2, i);
	}

	if (negative)
		result = (-1) * result;

	return to_string(result);
}

string QInt::BinToHex()
{
	string val = (*this).bit.to_string();
	string result;
	map<string, char> map = map_BinHex();
	int k = 1;
	string temp;

	for (int i = val.size() - 1; i >= 0; --i) {
		if (k <= 4) {
			k++;
			temp = val[i] + temp;
			continue;
		}
		else {
			i++;
			result = map[temp] + result;
			k = 1;
			temp.clear();
		} 
	}
	result = normalize(result);
	return result;
}

string QInt::DecToBin(string dec)
{
	string result;
	uint16_t num = stoi(dec);
	int remainder = 0;

	while (num > 0) {
		remainder = num % 2;
		num = num / 2;
		result = to_string(remainder) + result;
	}
	return result;
}

string QInt::HexToBin(string hex)
{
	string result;
	map<char, string> map = map_HexBin();
	for (int i = 0; i < hex.length(); i++)
	{
		result = result + map[hex[i]];
	}
	return result;
}

map<string,char> QInt::map_BinHex()
{
	map<string, char> juctBinHex;
	juctBinHex["0000"] = '0';
	juctBinHex["0001"] = '1';
	juctBinHex["0010"] = '2';
	juctBinHex["0011"] = '3';
	juctBinHex["0100"] = '4';
	juctBinHex["0101"] = '5';
	juctBinHex["0110"] = '6';
	juctBinHex["0111"] = '7';
	juctBinHex["1000"] = '8';
	juctBinHex["1001"] = '9';
	juctBinHex["1010"] = 'A';
	juctBinHex["1011"] = 'B';
	juctBinHex["1100"] = 'C';
	juctBinHex["1101"] = 'D';
	juctBinHex["1110"] = 'E';
	juctBinHex["1111"] = 'F';
	return juctBinHex;
}

map<char, string> QInt::map_HexBin()
{
	map<char, string> juncHecBin;
	juncHecBin['0'] = "0000";
	juncHecBin['1'] = "0001";
	juncHecBin['2'] = "0010";
	juncHecBin['3'] = "0011";
	juncHecBin['4'] = "0100";
	juncHecBin['5'] = "0101";
	juncHecBin['6'] = "0110";
	juncHecBin['7'] = "0111";
	juncHecBin['8'] = "1000";
	juncHecBin['9'] = "1001";
	juncHecBin['A'] = "1010";
	juncHecBin['B'] = "1011";
	juncHecBin['C'] = "1100";
	juncHecBin['D'] = "1101";
	juncHecBin['E'] = "1110";
	juncHecBin['F'] = "1111";
	return juncHecBin;
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
	}
	return result;
}

QInt QInt::operator-(const QInt& Qint2)
{
	QInt result, temp = Qint2;
	temp = ~temp;
	temp = temp + QInt(2,"1");
	result = *this + temp;
	return result;
}

QInt QInt::operator*(const QInt& Qint2)
{
	QInt result;
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
	QInt result;
	for (int i = 0; i < Qint2.bit.size(); i++) {
		if (this->bit[i] == 1 && Qint2.bit[i] == 1)
			result.bit[i] = 1;
		else
			result.bit[i] = 0;
	}
	return result;
}

QInt QInt::operator|(const QInt& Qint2)
{
	QInt result;
	for (int i = 0; i < Qint2.bit.size(); i++) {
		if (this->bit[i] == 0 && Qint2.bit[i] == 0)
			result.bit[i] = 0;
		else
			result.bit[i] = 1;
	}
	return result;
}

QInt QInt::operator^(const QInt& Qint2)
{
	QInt result;
	for (int i = 0; i < Qint2.bit.size(); i++) {
		if (this->bit[i] == Qint2.bit[i])
			result.bit[i] = 0;
		else
			result.bit[i] = 1;
	}
	return result;
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
	for (int i = step; i < 127; i++) {
		this->bit[i - step] = this->bit[i];
	}
	if (this->bit[127] == 1) {

		for (int i = 126; i >= 126 - step; i--) {
			this->bit[i] = 1;
		}
	}
	else {
		for (int i = 126; i >= 126 - step; i--) {
			this->bit[i] = 0;
		}
	}
	return *this;
}

QInt QInt::operator<<(int step)
{
	for (int i = 127 - step; i >= 0; i--) {
		this->bit[i - step] = this->bit[i];
	}
	if (this->bit[127] == 1) {

		for (int i = 126; i >= 126 - step; i--) {
			this->bit[i] = 1;
		}
	}
	else {
		for (int i = 126; i >= 126 - step; i--) {
			this->bit[i] = 0;
		}
	}
	return *this;
}

QInt QInt::rol()
{
	QInt result;
	int i = 127;
	while ((*this).bit[i] == 0)
		i--;
	bool carry = (*this).bit[i];
	result = (*this) << 1;
	result.bit[0] = carry;
	return result;
}

QInt QInt::ror()
{
	QInt result;
	int i = 127;
	while ((*this).bit[i] == 0)
		i--;
	bool carry = (*this).bit[0];
	result = (*this) >> 1;
	result.bit[i] = carry;
	return result;
}

void QInt::printbit()
{
	for (int i = (*this).bit.size() - 1; i >= 0; i--) {
		cout << (*this).bit[i];
	}
}

string QInt::printAsMode(uint16_t mode)
{
	if (mode == 10)
		return (*this).BinToDec();
	if (mode == 2)
		return (*this).bit.to_string();
	if (mode == 16)
		return (*this).BinToHex();
	return string();
}

string normalize(string s) {
	int i = 1;
	while (s[i] == s[i - 1] && s[i] == '0') 
		i++;
	return s.substr(i);
}