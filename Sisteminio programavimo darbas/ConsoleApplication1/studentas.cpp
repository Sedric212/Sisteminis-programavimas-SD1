#include "studentas.h"



studentas::studentas()
{
	var = "Test";
	pav = "Test";
	paz = { 1,2,3 };
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
	cout << setw(10) << left << var << "  " << setw(10) << left << pav << setw(10) << "Paz.:";
	for (auto d : paz) cout << setw(10) << setprecision(1) << fixed << d << "  ";
	cout << setw(10) << "Egz.:" << setw(10) << setprecision(1) << fixed << egz << setw(10)
		<< "Rez.:" << setw(10) << setprecision(1) << fixed << rez << "Vid. " << vid << endl;
}
void studentas::printasmediana() {
	cout << setw(10) << left << var << "  " << setw(10) << left << pav << setw(10) << "Paz.:";
	for (auto d : paz) cout << setw(10) << setprecision(1) << fixed << d << "  ";
	cout << setw(10) << "Egz.:" << setw(10) << setprecision(1) << fixed << egz << setw(10)
		<< "Rez.:" << setw(10) << setprecision(1) << fixed << rez << "Vid. Pagal mediana " << median << endl;
}

void studentas::pav_(string Pav_) {
	pav = Pav_;
}
string studentas::Get_pav() {
	return pav;
}
void studentas::Rez(double kint) {
	rez = kint * 0.4 + egz * 0.6;
}
void studentas::Vid() {
	double sum = accumulate(paz.begin(), paz.end(), 0.);
	/*
	double sum = 0.;
	for (auto i : paz) sum += i;
	*/
	vid = sum / paz.size();
}

void studentas::calculateMedian() {
	if (paz.empty()) {
		median = 0.0; 
		return;
	}

	std::sort(paz.begin(), paz.end()); 

	size_t size = paz.size();
	if (size % 2 == 0) {
		// Even number of elements: average the two middle elements
		median = (paz[size / 2 - 1] + paz[size / 2]) / 2.0;
	}
	else {
		// Odd number of elements: middle element is the median
		median = paz[size / 2];
	}
}
