#include "FileHandle.h"

bool Calculator(string input, string output)
{
	ifstream fin;
	fin.open(input);
	if (!fin.is_open())
		return false;
	
	vector<string> Operands;
	string temp;
	while (fin.peek() != EOF) {
		Operands.clear();

		//Get elements from a line in file
		while (fin.peek() != '\n') {
			fin >> temp;
			Operands.push_back(temp);
		}

		//Determined and solve
		uint16_t mode = stoi(Operands[0]);
		if (mode != 2 && mode != 10 && mode != 16) {
			WriteFile(output, "");
			fin.ignore();
			continue;
		}
		
		if (Operands.size() == 3) {
			QInt val = QInt(mode, Operands[2]);
			if (Operands[1] == "2" || Operands[1] == "10" || Operands[1] == "16") {
				uint16_t convert_mode = stoi(Operands[1]);
				WriteFile(output, val.printAsMode(convert_mode));
				fin.ignore();
				continue;
			}
			else if (Operands[1] == "~") {
				val = ~val;
			}
			else if (Operands[1] == "rol") {
				//val = val.rol(); Unfinish function
			}
			else if (Operands[1] == "ror") {
				//val = val.ror(); Unfinish function
			}
			else
			{
				WriteFile(output, "");
				fin.ignore();
				continue;
			}
			WriteFile(output, val.printAsMode(mode));
		}

		else if (Operands.size() == 4) {
			if (Operands[2] != "<<" && Operands[2] != ">>") {
				QInt result;
				QInt val1 = QInt(mode, Operands[1]);
				QInt val2 = QInt(mode, Operands[3]);

				if (Operands[2] == "+")
					result = val1 + val2;
				else if (Operands[2] == "-")
					result = val1 - val2;
				else if (Operands[2] == "*")
					result = val1 * val2;
				else if (Operands[2] == "/")
					result = val1 / val2;
				else
				{
					WriteFile(output, "");
					fin.ignore();
					continue;
				}
				WriteFile(output, result.printAsMode(mode));
			}
			else {
				QInt val = QInt(mode, Operands[1]);
				int step = stoi(Operands[3]);
				if (Operands[2] == "<<")
					val = val << step;
				else if (Operands[2] == ">>")
					val = val >> step;
				else
				{
					WriteFile(output, "");
					continue;
				}
				WriteFile(output, val.printAsMode(mode));
			}
		}
		fin.ignore();
	}
	return true;
}

void WriteFile(string output, string result)
{
	ofstream fout;
	fout.open(output, ios::app);
	if (!fout.is_open())
		return;
	fout << result << endl;
	fout.close();
}
