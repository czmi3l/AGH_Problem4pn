#include "Valve.h"


int main() {

	Valve v1;
	Valve v2(Valve::Opened);
	Valve v3(Valve::Opened);

	cout << "Po stworzeniu: Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3) << endl;

	v2.open();
	cout << "Po otwarciu v2: Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3) << endl;

	v3.open();
	cout << "Po otwarciu v3:  Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3) << endl;

	v1.open();
	cout << "Po otwarciu v1: Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3) << endl;

	Valve v4(Valve::Opened);
	cout << "Po dodaniu otwartego v4:  Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3)
		<< " zawor v4 " << status2symbol(v4) << endl;

	v1.open();
	cout << "Po otwarciu v1: Zawor v1 " << status2symbol(v1)
		<< " zawor v2 " << status2symbol(v2)
		<< " zawor v3 " << status2symbol(v3)
		<< " zawor v4 " << status2symbol(v4) << endl;
	cin.get();
	Valve::clean();

	return 0;
}


