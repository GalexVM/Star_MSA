#pragma once
#include "Needleman_W.h"


enum ReadMode{
    forward,
    inverse,
    mix,
    all
};

class Star {
    public:
    struct Node {
        int value = 0;
        alignment alg;
    };
    vector<Node> matrix;
    vector<int> sums;
    vector<string>seq;
    int f = 0, c = 0;

    void readStrings(ReadMode rm, string file);
    void buildMatrix();
    void printMatrix();
    unsigned int findRootAlignmentIndex();
    void printAlignmentsToFile(unsigned int index, string path);

};

