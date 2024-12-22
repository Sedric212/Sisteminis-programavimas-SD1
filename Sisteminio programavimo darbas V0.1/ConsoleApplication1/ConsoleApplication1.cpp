#include "studentas.h"
#include "failu_apdorojimas.h"
#include <iostream>
#include <algorithm>
#include <vector>
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

// Funkcija studentų spausdinimui
void spausdintiStudentus(const std::vector<studentas>& studentai) {
    std::cout << std::setw(15) << "Pavarde"
        << std::setw(15) << "Vardas"
        << std::setw(20) << "Galutinis (Vid.)"
        << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    for (const auto& stud : studentai) {
        stud.spausdinti();
    }
}

// Pagrindinė funkcija
int main() {
    std::vector<studentas> studentai;

    int pasirinkimas;
    std::cout << "Pasirinkite veiksma:\n"
        << "1 - Ivesti studentu duomenis ranka\n"
        << "2 - Nuskaityti duomenis is failo\n"
        << "3 - Generuoti studentu duomenis automatiskai\n";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        ivestiStudentus(studentai);
    }
    else if (pasirinkimas == 2) {
        try {
            nuskaitytiIsFailo("C:\\Users\\arnas\\OneDrive\\Desktop\\Sisteminio programavimo darbas V0.1\\ConsoleApplication1\\x64\\Debug\\kursiokai.txt", studentai);
        }
        catch (const std::exception& e) {
            std::cerr << "Klaida: " << e.what() << std::endl;
            return 1;
        }
    }
    else if (pasirinkimas == 3) {
        int kiekis;
        std::cout << "Kiek studentu sugeneruoti? ";
        std::cin >> kiekis;
        generuotiAtsitiktiniusPažymius(studentai, kiekis);
    }
    else {
        std::cerr << "Neteisingas pasirinkimas!\n";
        return 1;
    }

    std::sort(studentai.begin(), studentai.end(), [](const studentas& a, const studentas& b) {
        return a.getPavarde() < b.getPavarde();
        });

    spausdintiStudentus(studentai);

    return 0;
}
