Test2024.cpp

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
		   cout << "iveskite semestro paz." << i + 1<<": ";
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
//-------------------------------------------------------------------------------------
manobib.h

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;

using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::right;

using std::string;

using std::vector;

using std::accumulate; 

//--------------------------------------------------------------------
studentas.h

#pragma once

#include "manobib.h"

class studentas {
private:
	string var, pav;
	vector <double> paz;
	double vid, rez, egz; 
public:
	studentas();
	studentas(string, string, vector <double>, double);
	~studentas();

	void printas();

	void pav_(string); 
	string Get_pav();
	void Rez(double);
	void Vid();
};

//------------------------------------------------------------------------------------
Studentas.cpp

#include "studentas.h"

studentas::studentas()
{
	var = "Test";
	pav="Test";
	paz = {1,2,3};
	egz = 0;
	Vid();
	Rez(vid);
}

studentas::studentas(string Var_, string Pav_, vector <double> Paz_, double Egz_) {
	var = Var_;
	pav = Pav_;
	paz = Paz_;
	egz = Egz_;
	Vid();
	Rez(vid);
}
studentas::~studentas() {
	var.clear();
	pav.clear();
	paz.clear();
	vid = 0;
	egz = 0;
	rez = 0;
}

void studentas::printas() {
	cout <<setw(10)<<left <<var << "  " << setw(10) << left<<pav<< setw(10) << "Paz.:";
	for (auto d : paz) cout << setw(10)<<setprecision(1)<<fixed << d << "  ";
	cout << setw(10) << "Egz.:" << setw(10) << setprecision(1) << fixed << egz << setw(10) 
		<< "Rez.:" << setw(10) << setprecision(1) << fixed << rez<< "Vid. "<<vid<<endl;
}

void studentas::pav_(string Pav_) {
	pav = Pav_;
}
string studentas::Get_pav() {
	return pav;
}
void studentas::Rez(double kint) {
	rez = kint*0.4+egz*0.6;
}
void studentas::Vid() {
	double sum = accumulate(paz.begin(), paz.end(), 0.);
	/*
	double sum = 0.;
	for (auto i : paz) sum += i;
	*/
	vid = sum / paz.size();
}
