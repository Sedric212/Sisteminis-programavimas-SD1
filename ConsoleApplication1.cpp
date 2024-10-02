#include "manobib.h"
#include "studentas.h"

int main()
{

	//
	//A.printas();
	vector <studentas> eilutMas;
	//cout << eilutMas.size() << "   " << eilutMas.capacity()<<endl;
	for (int i = 0; i < 2; i++)
	{
		string iv1, iv2; cout << "Iveskite varda ir pav.: ";
		cin >> iv1 >> iv2;
		vector <double> ivv;
		int n;
		for (int i = 0; i < 3; i++) {
			cout << "iveskite semestro paz." << i + 1 << ": ";
			cin >> n;
			ivv.push_back(n);
		}
		cout << "Iveskite egzamino paz.: ";
		cin >> n;

		studentas A(iv1, iv2, ivv, n);
		eilutMas.push_back(A);
		//cout << eilutMas.size() << "   " << eilutMas.capacity() << endl;
	}
	cout << endl;
	for (auto a : eilutMas)
		a.printas();

}