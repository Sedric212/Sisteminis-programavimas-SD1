#include "failu_apdorojimas.h"
#include "studentas.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <iomanip>

// Funkcija rankiniam studentų duomenų įvedimui
void ivestiStudentus(std::vector<studentas>& studentai) {
    int studentuSk;
    std::cout << "Kiek studentu norite ivesti? ";
    std::cin >> studentuSk;

    for (int i = 0; i < studentuSk; ++i) {
        std::string vardas, pavarde;
        std::cout << "\nIveskite " << i + 1 << "-ojo studento duomenis:\n";
        std::cout << "Vardas: ";
        std::cin >> vardas;
        std::cout << "Pavarde: ";
        std::cin >> pavarde;

        std::vector<double> namuDarbai;
        double balas;

        std::cout << "Dabar iveskite namu darbu pazymius. "
            << "Kai baigsite, iveskite '-1', kad pereitumete prie egzamino balo.\n";
        std::cout << "Atminkite: pazymiai turi buti tarp 0 ir 10.\n";

        while (true) {
            std::cout << "Namu darbu pazymys (-1 jei baigiate): ";
            std::cin >> balas;

            if (balas == -1) {
                break;
            }

            if (balas < 0 || balas > 10) {
                std::cout << "Klaida: pazymys turi buti tarp 0 ir 10. Bandykite dar karta.\n";
                continue;
            }

            namuDarbai.push_back(balas);
        }

        double egzaminas;
        while (true) {
            std::cout << "Egzamino balas: ";
            std::cin >> egzaminas;

            if (egzaminas < 0 || egzaminas > 10) {
                std::cout << "Klaida: egzamino balas turi buti tarp 0 ir 10. Bandykite dar karta.\n";
                continue;
            }

            break;
        }

        studentai.emplace_back(vardas, pavarde, namuDarbai, egzaminas);
    }
}

// Funkcija studentų lentelės spausdinimui
void spausdintiStudentus(const std::vector<studentas>& studentai) {
    std::cout << std::setw(15) << std::left << "Pavarde"
        << std::setw(15) << std::left << "Vardas"
        << std::setw(20) << std::right << "Galutinis (Vid.)"
        << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;

    for (const auto& stud : studentai) {
        stud.spausdinti(); // Kviečiame spausdinimo metodą iš studentas klasės
    }
}

// Funkcija laikui matuoti
void matuotiLaika(const std::string& zingsnis, const std::function<void()>& veiksmas) {
    auto pradzia = std::chrono::high_resolution_clock::now();
    veiksmas();
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> trukme = pabaiga - pradzia;
    std::cout << zingsnis << " truko: " << trukme.count() << " s\n";
}

int main() {
    std::vector<studentas> studentai;

    while (true) {
        int pasirinkimas;
        std::cout << "\nPasirinkite veiksma:\n"
            << "1 - Ivesti studentu duomenis ranka\n"
            << "2 - Nuskaityti duomenis is failo\n"
            << "3 - Generuoti studentu duomenis automatiskai\n"
            << "4 - Generuoti ir rusiuoti studentu sarasus (V0.2)\n"
            << "5 - Baigti programa\n";
        std::cout << "Jusu pasirinkimas: ";
        std::cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            ivestiStudentus(studentai);
        }
        else if (pasirinkimas == 2) {
            try {
                std::string failoPavadinimas;
                std::cout << "Iveskite failo pavadinima: ";
                std::cin >> failoPavadinimas;
                nuskaitytiIsFailo(failoPavadinimas, studentai);
                spausdintiStudentus(studentai);
            }
            catch (const std::exception& e) {
                std::cerr << "Klaida: " << e.what() << std::endl;
            }
        }
        else if (pasirinkimas == 3) {
            int kiekis;
            std::cout << "Kiek studentu sugeneruoti? ";
            std::cin >> kiekis;
            generuotiAtsitiktiniusPažymius(studentai, kiekis);
            spausdintiStudentus(studentai);
        }
        else if (pasirinkimas == 4) {
            try {
                matuotiLaika("Failų generavimas", []() {
                    generuotiVisusFailus();
                    });

                std::vector<std::string> failai = {
                    "studentai_1000.txt",
                    "studentai_10000.txt",
                    "studentai_100000.txt",
                    "studentai_1000000.txt",
                    "studentai_10000000.txt"
                };

                for (const auto& failas : failai) {
                    matuotiLaika("Apdorojamas failas: " + failas, [&]() {
                        skirstytiStudentusIFailus(failas);
                        });
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Klaida: " << e.what() << std::endl;
            }
        }
        else if (pasirinkimas == 5) {
            std::cout << "Programa baigiama.\n";
            break;
        }
        else {
            std::cerr << "Neteisingas pasirinkimas! Bandykite dar karta.\n";
        }
    }

    return 0;
}
