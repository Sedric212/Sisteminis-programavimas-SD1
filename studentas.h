#pragma once

#include "manobib.h";

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