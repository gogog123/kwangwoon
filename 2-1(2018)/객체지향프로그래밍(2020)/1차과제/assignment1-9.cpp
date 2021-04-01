#include <iostream>
using namespace std;
int extra_text;
int extra_call;
int total;

void type_A(int text, int call) 
{
	extra_text = (text - 100) * 20;
	if (extra_text < 0)
		extra_text = 0;

	extra_call = (call - 60) * 180;
	if (extra_call < 0)
		extra_call = 0;
	total = extra_text + extra_call + 10000;
}//type_A
//fee10,000, free_text:100, free_call:60, extra_text:20, extra_call:180

void type_B(int text, int call)
{
	extra_text = (text - 150) * 15;
	if (extra_text < 0)
		extra_text = 0;

	extra_call = (call - 90) * 150;
	if (extra_call < 0)
		extra_call = 0;
	total = extra_text + extra_call + 15000;
}//type_B
//fee15,000, free_text:150, free_call:90, extra_text:15, extra_call:150

void type_C(int text, int call)
{
	extra_text = (text - 200) * 10;
	if (extra_text < 0)
		extra_text = 0;

	extra_call = (call - 120) * 60;
	if (extra_call < 0)
		extra_call = 0;
	total = extra_text + extra_call + 20000;
}//type_C
//fee20,000, free_text:200, free_call:120, extra_text:10, extra_call:60

void type_D(int text, int call)
{
	extra_text = (text - 250) * 5;
	if (extra_text < 0)
		extra_text = 0;

	extra_call = (call - 150) * 30;
	if (extra_call < 0)
		extra_call = 0;
	total = extra_text + extra_call + 25000;
}//type_D
//fee25,000, free_text:250, free_call:150, extra_text:5, extra_call:30


int main()
{
	char input_type;
	int input_text;
	int input_call;
	while (1)
	{
		cout << "Which type: ";
		cin >> input_type;
		cout << "Text: ";
		cin >> input_text;
		cout << "Call: ";
		cin >> input_call;
		cout << "----------------" << endl;

		if (input_type == 'A') //when A
		{
			type_A(input_text, input_call);
			break;
		}
		else if (input_type == 'B') //when B
		{
			type_B(input_text, input_call);
			break;
		}
		else if (input_type == 'C') //when C
		{
			type_C(input_text, input_call);
			break;
		}
		else if (input_type == 'D') //when D
		{
			type_D(input_text, input_call);
			break;
		}
		else //excepion
		{
			cout << "Please input type A~D\n\n";
		}
	}
	cout << "Result" << endl;
	cout << "Extra text: " << extra_text << endl;
	cout << "Extra call: " << extra_call << endl;
	cout << "Total: : " << total << endl;
	//print fee
	

	return 0;
}