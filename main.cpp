//#include "Needleman_W.h"
#include "Star.h"

int main() {

    


    Star star;
    star.readStrings(mix, "../inputs/inputStar.txt");
    star.buildMatrix();
    star.printMatrix();
    int indiceNodoCentral = star.findRootAlignmentIndex();
    cout << "la fila de la cadena central es: " << indiceNodoCentral << "\n\n";
    star.printAlignmentsToFile(indiceNodoCentral,"../outputs/star_alignments.txt");

    /*Star star1;
    star1.readStrings(all,"../inputs/inputStarPrueba.txt");
    star1.buildMatrix();
    star1.printMatrix();
    int inc = star1.findRootAlignmentIndex();
    cout << "la fila de la cadena central es: " << inc << "\n\n";
    star1.printAlignmentsToFile(inc,"../outputs/star_alignmentsPrueba.txt");
    */

}