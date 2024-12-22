#pragma once
#include "studentas.h"
#include <vector>
#include <string>

void generuotiAtsitiktiniusPažymius(std::vector<studentas>& studentai, int kiekis);
void nuskaitytiIsFailo(const std::string& failoPavadinimas, std::vector<studentas>& studentai);
