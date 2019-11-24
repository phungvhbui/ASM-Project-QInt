#include "FileHandle.h"

int main() {
	/*if (Calculator("input.txt", "output.txt") == true)
	{
		cout << "Data is calculated. Please check output.txt" << endl;
	}
	else
	{
		cout << "Error in file/program. Canceling program..." << endl;
	}*/
	QInt num1(2, "00011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011");
	QInt result = num1 >> 200;
	result.printbit();
	return 0;
}