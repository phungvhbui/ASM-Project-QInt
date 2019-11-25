#include "FileHandle.h"

int main() {
	if (Calculator("input.txt", "output.txt") == true)
	{
		cout << "Data is calculated. Please check output.txt" << endl;
	}
	else
	{
		cout << "Error in file/program. Canceling program..." << endl;
	}
	//QInt num1 = { 2,"11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" };
	//QInt num2(10, "2");
	//QInt result = num2 / num1;
	//result.printbit();
	return 0;
}