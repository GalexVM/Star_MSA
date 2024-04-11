//#include "Needleman_W.h"
#include "Star.h"

int main() {


    Star star;
    star.readStrings(forward, "../inputStar.txt");
    star.buildMatrix();
    int indiceNodoCentral = star.findRootAlignmentIndex();
    star.printAlignmentsToFile(indiceNodoCentral,"../star_alignments.txt");


}