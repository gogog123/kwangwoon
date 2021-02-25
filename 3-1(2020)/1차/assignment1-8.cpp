#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

void loadTxt(ifstream& inFile, string& strFile)
{
	if (!inFile.is_open()) return;

	int fileSize = 0;

	inFile.seekg(0, ios::end); //move the file pointer to the end of the file
	fileSize = inFile.tellg(); //get file size
	inFile.seekg(0, ios::beg); //move the file pointer to the beginning of the file

	strFile.resize(fileSize);
	inFile.read(&strFile[0], fileSize);
} //read txt fileand save to variable

void caesarEncryption(ifstream& inFile)
{
	int i = 0;
	int arr[1000];
	int value;

	if (!inFile.is_open())
	{
		cout << "file is not opened" << endl;
	}//When a file cannot be read

	string strFile;

	loadTxt(inFile, strFile);

	stringstream ss(strFile);

	string token;

	cout << "ciphertext : ";
	while (ss >> token)
	{
		cout << token.c_str() << " ";
		value = _strtoi64(token.c_str(), NULL, 16); //get hexadecimal number as decimal number
	//	cout << value << endl;
		arr[i] = value;
		i++;
	}

	cout << endl;

	for (int caesar = 0; caesar< 128; caesar++)
	{
		cout << "key(" << caesar << "): ";
		for (int j = 0; j < i; j++)
		{
			if (arr[j] + caesar >= 128)
			{
				arr[j] = arr[j] - 128;
			}
			cout << (char)(arr[j] + caesar);
		}
		cout << "\n\n";
	 } //0 to 127 shift execution

}

int main()
{
	string strFileName = "ciphertext";
	string strFileFormat = ".txt";

	ifstream inFile(strFileName + strFileFormat);

	caesarEncryption(inFile);

	inFile.close();

	return 0;
}