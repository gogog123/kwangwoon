#include <iostream>
#include <fstream> // file input/output
#include <time.h> //function time
using namespace std;

int main()
{
	ifstream fin("source.txt"); 
	ofstream fout("result.txt");

	time_t start, end;

	char str[100];
	char str_copy[100]; //input str
	float accuracy = 0; 
	float speed = 0;
	
	if (!fin.is_open())
	{
		cout << "No file!" << endl;
		return 0;
	} //Check if file is open

	fout << "KW Typing Verification Program" << endl;
	fout << "정확도 : " << accuracy << "     속도(타자/s) : " << speed << "\n\n";

	while (1)
	{
		cout << "KW Typing Verification Program" << endl;
		cout << "정확도 : " << accuracy << "     속도(타자/s) : " << speed << "\n\n";
		

		if (!fin.eof()) //check end of file
			fin.getline(str, 100); //read line by line
		else
			return 0;

		cout << "문장 : " << str << endl;
		cout << "입력 : ";

		start = time(NULL); // strat time measurement
		cin.getline(str_copy, 100);
		end = time(NULL); // end time measurement

		int count = 0;
		for (int i = 0; i < strlen(str_copy); i++)
		{
			if (str[i] == str_copy[i])
				count++; // Correct characters 
		}

		accuracy = ((float)count / (float)strlen(str_copy)) * 100; 
		// Accuracy = (Correct characters / input length of sentence) * 100
		
		speed = (float)strlen(str)/(float)(end - start); // speed = length / second
		fout << str_copy << endl;
		fout << "정확도 : " << accuracy << "     속도(타자/s) : " << speed << "\n\n";

		system("cls"); // screen reset
	}

	fin.close();
	fout.close(); // close file

	return 0;
}