#pragma once
#include <string>
#include <vector>
#include "studentas.h"

// Funkcija generuoti didelius failus
void generuotiVisusFailus();

// Funkcija generuoti vieną studentų failą
void generuotiStudentuFaila(const std::string& failoPavadinimas, int irasuKiekis);

// Funkcija generuoti atsitiktinius studentus
void generuotiAtsitiktiniusPažymius(std::vector<studentas>& studentai, int kiekis);

// Funkcija nuskaityti studentus iš failo
void nuskaitytiIsFailo(const std::string& failoPavadinimas, std::vector<studentas>& studentai);

// Funkcija skirstyti studentus į dvi grupes (vargšiukai ir kietekai)
void skirstytiStudentusIFailus(const std::string& failoPavadinimas);
