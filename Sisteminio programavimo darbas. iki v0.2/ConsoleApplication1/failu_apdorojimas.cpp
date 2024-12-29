#include "failu_apdorojimas.h"
#include "studentas.h"
#include <fstream>
#include <random>
#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <filesystem>

// Funkcija studentų failų generavimui
void generuotiStudentuFaila(const std::string& failoPavadinimas, int irasuKiekis) {
    const std::string direktorija = "C:\\ManoSugeneruotiFailai\\";

    if (!std::filesystem::exists(direktorija)) {
        std::filesystem::create_directories(direktorija);
    }

    std::ofstream outFile(direktorija + failoPavadinimas);
    if (!outFile.is_open()) {
        throw std::ios_base::failure("Nepavyko sukurti failo: " + direktorija + failoPavadinimas);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i <= irasuKiekis; ++i) {
        outFile << "Vardas" << i << " Pavarde" << i;

        // Generuoti atsitiktinius 5–10 namų darbų balus
        int ndKiekis = dist(gen) % 6 + 5;
        for (int j = 0; j < ndKiekis; ++j) {
            outFile << " " << dist(gen);
        }

        // Generuoti egzaminą
        outFile << " " << dist(gen) << "\n";
    }

    outFile.close();
}

// Funkcija generuoti visus didelius failus
void generuotiVisusFailus() {
    const std::string direktorija = "C:\\ManoSugeneruotiFailai\\";

    if (!std::filesystem::exists(direktorija)) {
        std::filesystem::create_directories(direktorija);
    }

    generuotiStudentuFaila("studentai_1000.txt", 1000);
    generuotiStudentuFaila("studentai_10000.txt", 10000);
    generuotiStudentuFaila("studentai_100000.txt", 100000);
    generuotiStudentuFaila("studentai_1000000.txt", 1000000);
    generuotiStudentuFaila("studentai_10000000.txt", 10000000);
}

// Funkcija generuoti atsitiktinius studentus
void generuotiAtsitiktiniusPažymius(std::vector<studentas>& studentai, int kiekis) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i <= kiekis; ++i) {
        std::string vardas = "Vardas" + std::to_string(i);
        std::string pavarde = "Pavarde" + std::to_string(i);

        std::vector<double> ndBalai;
        int ndKiekis = dist(gen) % 6 + 5; // Generuojame nuo 5 iki 10 namų darbų pažymių
        for (int j = 0; j < ndKiekis; ++j) {
            ndBalai.push_back(dist(gen));
        }

        double egzaminas = dist(gen); // Generuojame egzamino pažymį
        studentai.emplace_back(vardas, pavarde, ndBalai, egzaminas);
    }
}

// Funkcija nuskaityti studentus iš failo
void nuskaitytiIsFailo(const std::string& failoPavadinimas, std::vector<studentas>& studentai) {
    const std::string direktorija = "C:\\ManoSugeneruotiFailai\\";
    std::ifstream inFile(direktorija + failoPavadinimas);
    if (!inFile.is_open()) {
        throw std::ios_base::failure("Nepavyko atidaryti failo: " + direktorija + failoPavadinimas);
    }

    std::string eilute;
    while (std::getline(inFile, eilute)) {
        std::istringstream ss(eilute);
        std::string vardas, pavarde;
        ss >> vardas >> pavarde;

        std::vector<double> ndBalai;
        double balas;

        while (ss >> balas) {
            ndBalai.push_back(balas);
        }

        double egzaminas = ndBalai.back();
        ndBalai.pop_back();

        studentai.emplace_back(vardas, pavarde, ndBalai, egzaminas);
    }

    inFile.close();
}

// Funkcija skirstyti studentus į dvi grupes (vargšiukai ir kietekai)
void skirstytiStudentusIFailus(const std::string& failoPavadinimas) {
    const std::string direktorija = "C:\\ManoSugeneruotiFailai\\";
    std::ifstream inFile(direktorija + failoPavadinimas);

    if (!inFile.is_open()) {
        throw std::ios_base::failure("Nepavyko atidaryti failo: " + direktorija + failoPavadinimas);
    }

    std::ofstream vargsaiFailas(direktorija + "vargsai_" + failoPavadinimas);
    std::ofstream kietekaiFailas(direktorija + "kietekai_" + failoPavadinimas);

    if (!vargsaiFailas.is_open() || !kietekaiFailas.is_open()) {
        throw std::ios_base::failure("Nepavyko sukurti grupių failų.");
    }

    std::cout << "Pradedamas failo " << failoPavadinimas << " skirstymas...\n";

    std::string eilute;
    int vargsaiCount = 0;
    int kietekaiCount = 0;

    while (std::getline(inFile, eilute)) {
        std::istringstream ss(eilute);
        std::string vardas, pavarde;
        ss >> vardas >> pavarde;

        std::vector<double> ndBalai;
        double balas;

        while (ss >> balas) {
            ndBalai.push_back(balas);
        }

        double egzaminas = ndBalai.back();
        ndBalai.pop_back();

        double vidurkis = std::accumulate(ndBalai.begin(), ndBalai.end(), 0.0) / ndBalai.size();
        double galutinisBalas = (vidurkis * 0.4) + (egzaminas * 0.6);

        if (galutinisBalas < 5.0) {
            vargsaiFailas << eilute << "\n";
            vargsaiCount++;
        }
        else {
            kietekaiFailas << eilute << "\n";
            kietekaiCount++;
        }
    }

    std::cout << "Failo " << failoPavadinimas << " skirstymas baigtas.\n";
    std::cout << "Vargsai: " << vargsaiCount << ", Kietekai: " << kietekaiCount << "\n";

    inFile.close();
    vargsaiFailas.close();
    kietekaiFailas.close();
}
