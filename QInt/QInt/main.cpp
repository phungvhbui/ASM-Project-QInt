#include "QInt.h"

int main() {
	QInt num(2, "1111");
	QInt num2(2, "0001");
	QInt result	= num ^ num2;
	print(result);
}