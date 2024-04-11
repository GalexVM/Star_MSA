//#include "Needleman_W.h"
#include "Star.h"

int main() {


    Star star;
    star.readStrings(forward, "../inputs/inputStar.txt");
    star.buildMatrix();
    star.printMatrix();
    int indiceNodoCentral = star.findRootAlignmentIndex();
    cout << "la fila de la cadena central es: " << indiceNodoCentral << "\n";
    star.printAlignmentsToFile(indiceNodoCentral,"../outputs/star_alignments.txt");


}