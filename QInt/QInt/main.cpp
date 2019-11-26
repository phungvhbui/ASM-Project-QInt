#include "FileHandle.h"

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