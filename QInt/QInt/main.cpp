#include "QInt.h"

int main() {
	QInt num(2, "110100011");
	string result = num.BinToHex();
	cout << result << endl;

	QInt num2(16, "1A3");
	num2.printbit();
}