#include "failu_apdorojimas.h"
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

// Funkcija generuoti atsitiktinius studentus
void generuotiAtsitiktiniusPažymius(std::vector<studentas>& studentai, int kiekis) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (int i = 0; i < kiekis; ++i) {
        std::vector<double> ndBalai;
        int ndKiekis = dist(gen); // Atsitiktinis namų darbų kiekis
        for (int j = 0; j < ndKiekis; ++j) {
            ndBalai.push_back(dist(gen));
        }
        double egzaminas = dist(gen);
        studentai.emplace_back("Vardas" + std::to_string(i + 1), "Pavarde" + std::to_string(i + 1), ndBalai, egzaminas);
    }
}

// Funkcija nuskaityti studentus iš failo
void nuskaitytiIsFailo(const std::string& failoPavadinimas, std::vector<studentas>& studentai) {
    std::ifstream file(failoPavadinimas);
    if (!file.is_open()) {
        throw std::ios_base::failure("Nepavyko atidaryti failo.");
    }

    std::string vardas, pavarde;
    int lineNumber = 0;

    while (file >> pavarde >> vardas) {
        lineNumber++;
        std::vector<double> ndBalai;
        double balas;

        // Skaityti namų darbų balus
        while (file >> balas) {
            if (file.peek() == '\n' || file.eof()) { // Jei liko tik vienas skaičius (egzaminas)
                break;
            }
            ndBalai.push_back(balas);
        }

        double egzaminas = balas; // Paskutinis skaičius yra egzaminas
        if (ndBalai.empty()) {
            std::cerr << "Klaida: studentas " << pavarde << " " << vardas
                << " neturi galiojančių pažymių eilutėje " << lineNumber << std::endl;
            continue;
        }

        // Debug: Patikrinti, kas buvo nuskaityta
        std::cout << "DEBUG: Nuskaitytas studentas: " << pavarde << " " << vardas << "\n";
        std::cout << "DEBUG: Namu darbai: ";
        for (const auto& pazymys : ndBalai) {
            std::cout << pazymys << " ";
        }
        std::cout << "\nDEBUG: Egzaminas: " << egzaminas << std::endl;

        // Pridėti studentą į sąrašą
        studentai.emplace_back(vardas, pavarde, ndBalai, egzaminas);
    }

    file.close();
}
