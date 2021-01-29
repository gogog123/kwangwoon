#include <systemc.h>

int sc_main(int argc, char* argv[]) {

	sc_set_time_resolution(1, SC_PS);

	sc_time t1(10, SC_NS);
	sc_time t2(5, SC_PS);
	sc_time t3, t4(1, SC_US), t5(1, SC_PS);
	//declare the sc_time variables

	cout << "Value of t1 " << t1.to_string() << endl;
	cout << "Value of t2 " << t2.to_string() << endl;
	cout << "Value of t3 " << t3.to_string() << endl;
	cout << "Value of t4 " << t4.to_string() << endl;
	cout << "Value of t5 " << t5.to_string() << endl;
	//print valiables t1, t2, t3, t4, t5

	cout << "simulation start! " << sc_time_stamp() << endl;

	sc_start(10, SC_PS); // 10ps
	t3 = sc_time_stamp();
	cout << "Value of t3 " << t3.to_string() << endl; //10ps print

	sc_start(1, SC_NS); // 1ns = 1000ps
	t3 = sc_time_stamp();
	cout << "Value of t3 " << t3.to_string() << endl; //10ps + 1ns = 1010ps print

	sc_start(20, SC_MS); // 20ms = 20000000000ps
	t4 = sc_time_stamp(); // get time stamp
	cout << "Value of t4 " << t4.to_string() << endl; //1010ps + 20ms print

	t5 = t4 - t3; // 20000001010ps - 1010ps
	//sc_time arithmetic examples
	cout << "Value of t5 " << t5.to_string() << endl;

	if (t5 > t2) {
		cout << " t5 is greated than t2 " << endl;
	}
	else {
		cout << " t2 is greated than t5 " << endl;
	}

	return 1;
}