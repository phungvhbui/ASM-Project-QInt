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
	return 0;
}