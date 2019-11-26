#include "FileHandle.h"

//int main() {
//
//	/*if (Calculator("data\input.txt", "output_sv\output.txt") == true)
//	{
//		cout << "Data is calculated. Please check output.txt" << endl;
//	}
//	else
//	{
//		cout << "Error in file/program. Canceling program..." << endl;
//	}*/
//	QInt num1(10,"788323282258381939236275890776");
//	QInt num2(10, "-27388934683056007097503944712");
//	QInt result = num1 / num2;
//	result.printbit();
//
//	return 0;
//}

int main(int argc, char* argv[])
{
	if (Calculator(argv[1], argv[2]) == true)
	{
		cout << "Data is calculated. Please check output.txt" << endl;
	}
	else
	{
		cout << "Error in file/program. Canceling program..." << endl;
	}

	return 0;
}