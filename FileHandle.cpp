#include "FileHandle.h"

//Hàm đọc file -> Tính toán -> Viết ra file theo từng dòng
bool Calculator(string input, string output)
{
	ifstream fin;
	ofstream fout;

	fin.open(input);
	if (!fin.is_open())
		return false;
	fout.open(output);
	if (!fout.is_open())
		return false;
	
	vector<string> Operands;
	string temp;
	int i = 0;
	while (fin.peek() != EOF) {
		Operands.clear();

		//Lấy các toán hạng của phép toán ở từng dòng từ file
		while (fin.peek() != '\n') {
			fin >> temp;
			Operands.push_back(temp);
		}

		//Xác định đó là phép tính gì và tính toán, đồng thời ghi kết quả ra file
		uint16_t mode = stoi(Operands[0]);
		if (mode != 2 && mode != 10 && mode != 16) {
			fout << "" << endl;
			fin.ignore();
			continue;
		}
		
		if (Operands.size() == 3) {
			QInt val = QInt(mode, Operands[2]);
			if (Operands[1] == "2" || Operands[1] == "10" || Operands[1] == "16") {
				uint16_t convert_mode = stoi(Operands[1]);
				fout << val.printAsMode(convert_mode) << endl;
				fin.ignore();
				continue;
			}
			else if (Operands[1] == "~") {
				val = ~val;
			}
			else if (Operands[1] == "rol") {
				val = val.rol();
			}
			else if (Operands[1] == "ror") {
				val = val.ror();
			}
			else
			{
				fout << "" << endl;
				fin.ignore();
				continue;
			}
			fout << val.printAsMode(mode) <<endl;
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
				{
					if ((val2.printAsMode(2) == "0")) {
						fout << "" <<endl;
						fin.ignore();
						continue;
					}
					result = val1 / val2;
				}
				else if (Operands[2] == "&")
					result = val1 & val2;
				else if (Operands[2] == "|")
					result = val1 | val2;		
				else if (Operands[2] == "^")
					result = val1 ^ val2;		
				else
				{
					fout << "" << endl;
					fin.ignore();
					continue;
				}
				fout << result.printAsMode(mode) << endl;
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
					fout << "" << endl;
					continue;
				}
				fout << val.printAsMode(mode) << endl;
			}
		}
		fin.ignore();
	}
	fin.close();
	fout.close();
	return true;
}