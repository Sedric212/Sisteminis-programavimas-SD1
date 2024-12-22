#include "studentas.h"
#include "failu_apdorojimas.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

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

int main() {
    std::vector<studentas> studentai;

    int pasirinkimas;
    std::cout << "Pasirinkite veiksma:\n"
        << "1 - Ivesti studentu duomenis ranka\n"
        << "2 - Nuskaityti duomenis is failo\n"
        << "3 - Generuoti studentu duomenis automatiskai\n";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        int studentuSk;
        std::cout << "Kiek studentu norite ivesti? ";
        std::cin >> studentuSk;

        for (int i = 0; i < studentuSk; ++i) {
            std::string vardas, pavarde;
            std::cout << "Iveskite varda ir pavarde: ";
            std::cin >> vardas >> pavarde;

            std::vector<double> namuDarbai;
            double balas;
            std::cout << "Iveskite namu darbu pazymius (-1 jei baigiate): ";
            while (true) {
                std::cin >> balas;
                if (balas == -1) break;
                namuDarbai.push_back(balas);
            }

            double egzaminas;
            std::cout << "Iveskite egzamino bala: ";
            std::cin >> egzaminas;

            studentai.emplace_back(vardas, pavarde, namuDarbai, egzaminas);
        }
    }
    else if (pasirinkimas == 2) {
        try {
            // Naudojamas absoliutus kelias
            nuskaitytiIsFailo("C:\\Users\\arnas\\OneDrive\\Desktop\\Sisteminio programavimo darbas\\ConsoleApplication1\\x64\\Debug\\kursiokai.txt", studentai);
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
