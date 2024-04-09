#include "Needleman_W.h"


int main() {
    string cadena1, cadena2;
    Needleman_W NW_alg(1,-2,-1);
    NW_alg.leerInputs(cadena1, cadena2, "input.txt");
    auto fsize = cadena2.size() + 2;
    auto csize = cadena1.size() + 2;
    tablero tab1((csize) * (fsize + 2));
    NW_alg.iniciarlizarTablero(tab1, fsize, csize, cadena1, cadena2);
    NW_alg.NeddlemanWunsch(tab1, fsize, csize);
    auto best = NW_alg.findBestAlignment(tab1, fsize, csize);
    NW_alg.printPathsToFile(best);
    NW_alg.printAlignmentsToFile(best, fsize, csize);
}

