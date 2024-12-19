#pragma once

#include "manobib.h"


class studentas {
private:
    string var, pav;
    vector<double> paz;      
    double vid;              
    double median;           
    double rez;              
    double egz;              

public:
    studentas();
    studentas(string, string, vector<double>, double);
    ~studentas();

    void printas();
    void printasmediana();

    void pav_(string);
    string Get_pav();
    void Rez(double);
    void Vid();
    void calculateMedian();  
};
