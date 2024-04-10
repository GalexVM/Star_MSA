//
// Created by USER on 9/04/2024.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

struct casilla {
    casilla* left = nullptr, * top = nullptr, * diagonal = nullptr;
    std::string valor = "__";
    char l, t;
};

using tablero = std::vector<casilla>;
using alignment = std::vector<std::vector<std::string>>;
using std::string;
using std::vector;
using std::cout;
using std::pair;
using std::max;
using std::stoi;

class Needleman_W
{
public:
    int lastScore = 0;
    int match = 1, indel = -2, mismatch = -1;
    Needleman_W(int m, int ind, int misma) :match(m), indel(ind), mismatch(misma) {}
    alignment calculate(string c1, string c2);
    void exportAlignment(string c1, string c2, alignment& alg);
    void iniciarlizarTablero(tablero& tab, unsigned int fsize, unsigned int csize, string c1, string c2);
    void imprimirTablero(tablero& tab, unsigned int fsize, unsigned int csize);
    void NeddlemanWunsch(tablero& tab, unsigned int fsize, unsigned int csize);
    std::vector<alignment> findAllAlingments(tablero& tab, unsigned int fsize, unsigned int csize, casilla* temp = nullptr);
    alignment findBestAlignment(tablero& tab, unsigned  int fsize, unsigned  int csize);
    void printPathsToFile(vector<alignment>& recorridos);
    void printAlignmentsToFile(vector<alignment>& recorridos, unsigned int fsize, unsigned int csize);
    void printPathsToFile(alignment& recorrido);
    void printAlignmentsToFile(alignment& recorrido, unsigned int fsize, unsigned int csize);
    void leerInputs(string& st1, string& st2, string file);
};

