#include "studentas.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>

studentas::studentas() : vardas(""), pavarde(""), egzaminas(0), galutinisVidurkis(0), galutinisMediana(0) {}

studentas::studentas(std::string v, std::string p, std::vector<double> nd, double egzam)
    : vardas(v), pavarde(p), ndBalai(nd), egzaminas(egzam) {
    skaiciuotiVidurki();
    skaiciuotiMediana();
}

void studentas::skaiciuotiVidurki() {
    if (ndBalai.empty()) {
        galutinisVidurkis = 0.0; // Jei nėra namų darbų, nustatomas 0
        return;
    }
    double suma = std::accumulate(ndBalai.begin(), ndBalai.end(), 0.0);
    double vidurkis = suma / ndBalai.size();
    galutinisVidurkis = (vidurkis * 0.4) + (egzaminas * 0.6);
}

void studentas::skaiciuotiMediana() {
    if (ndBalai.empty()) {
        galutinisMediana = 0.0; // Jei nėra namų darbų, nustatomas 0
        return;
    }
    std::sort(ndBalai.begin(), ndBalai.end());
    double mediana;
    if (ndBalai.size() % 2 == 0) {
        mediana = (ndBalai[ndBalai.size() / 2 - 1] + ndBalai[ndBalai.size() / 2]) / 2.0;
    }
    else {
        mediana = ndBalai[ndBalai.size() / 2];
    }
    galutinisMediana = (mediana * 0.4) + (egzaminas * 0.6);
}

void studentas::spausdinti() const {
    std::cout << std::setw(15) << std::left << pavarde
        << std::setw(15) << std::left << vardas
        << std::setw(20) << std::fixed << std::setprecision(2) << galutinisVidurkis
        << std::setw(20) << galutinisMediana << std::endl;
}
