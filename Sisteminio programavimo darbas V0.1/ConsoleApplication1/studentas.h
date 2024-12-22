#pragma once
#include <string>
#include <vector>

class studentas {
private:
    std::string vardas, pavarde;
    std::vector<double> ndBalai; // Namų darbų balai
    double egzaminas;
    double galutinisVidurkis;
    double galutinisMediana;

public:
    studentas();
    studentas(std::string v, std::string p, std::vector<double> nd, double egzam);

    void skaiciuotiVidurki();
    void skaiciuotiMediana();
    void spausdinti() const;

    double getGalutinisVidurkis() const { return galutinisVidurkis; }
    double getGalutinisMediana() const { return galutinisMediana; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
};
