#pragma once
#include "Needleman_W.h"

class Star {
    struct Node {
        int value = NULL;
        alignment alg;
    };
    vector<Node> matrix;
    vector<Node> sums;
    vector<string>seq;
    int f = 0, c = 0;
    explicit Star(vector<string>& sequences) :seq(sequences) {
        c = f = (int)sequences.size();
        matrix = vector<Node>(c * f);
        sums = vector<Node>(c);
    }
    void buildMatrix();
    unsigned int findRootAlignmentIndex();



};

