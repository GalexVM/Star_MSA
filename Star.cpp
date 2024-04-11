#include "Star.h"

string generarcadenaopuesta(string cadena){
    for(auto c : cadena){
        if(c == 'T' || c == 't') c = 'A';
        else if(c == 'A' || c == 'a') c = 'T';
        else if(c == 'C' || c == 'c') c = 'G';
        else if(c == 'G' || c == 'g') c = 'C';
        else cout << "Error al generar cadena opuesta. Cadena no válida.\n";
    }
    return cadena;
}

void Star::readStrings(ReadMode rm, string file){ //Reads and saves
    std::ifstream input(file);
    vector<string> cadenas;
    if(!input.is_open()) cout << "Error al abrir el archivo de input Star\n";
    else{ 
        switch (rm)
        {
        case forward:
            for(auto i = 0; i < 6; i++){
                string temp = ""; 
                std::getline(input,temp);
                cadenas.push_back(temp);
            }
            break;
        case inverse:{
            for(auto i = 0; i < 6; i++){
                string temp = ""; 
                std::getline(input,temp);
            }
            for(auto i = 0; i < 6; i++){
                string temp = ""; 
                std::getline(input,temp);
                cadenas.push_back(temp);
            }
            break;
        }
        case mix:
            //Agarrar directos
            for(auto i = 0; i < 6; i++){
                string temp = ""; 
                std::getline(input,temp);
                cadenas.push_back(temp);
            }
            //Agarrar y transformar inversas
            for(auto i = 0; i < 6; i++){
                string temp = ""; 
                std::getline(input,temp);
                std::reverse(temp.begin(),temp.end());
                temp = generarcadenaopuesta(temp);
                cadenas.push_back(temp);
            }
            break;
        
        case all:
            while(!input.eof()){
                string temp = "";
                std::getline(input,temp);
                cadenas.push_back(temp);
            }
            break;
        
        default: cout << "tipo de lectura incorrecta\n";
            break;
        }
        input.close();
        c = f = (int)cadenas.size();
        matrix = vector<Node>(c * f);
        sums = vector<int>(c,0);
        seq = std::move(cadenas);
    }
}
void Star::buildMatrix(){
    Needleman_W nw(1,-2,-1);
    for(auto i = 0; i < f; i++){
        for(auto j = 0; j < c; j++){
            Node* currentNode = &(matrix[c*i+j]);
            if(j == i){
                currentNode->alg = alignment();
                currentNode->value = 0;
            }
            else if(j > i){
                currentNode->alg = nw.calculate(seq[i],seq[j]);
                currentNode->value = nw.lastScore;
            }
            else{
                currentNode->alg = matrix[c*j+i].alg;
                currentNode->value =  matrix[c*j+i].value;
            }

        }
    }
}
void Star::printMatrix(){
    for(auto i = 0; i < f; i++){
        for(auto j = 0; j < c; j++){
            cout << matrix[c*i+j].value << "\t";
        }cout << "\n";
    }cout << "\n";
}
unsigned int Star::findRootAlignmentIndex(){
    for(auto i = 0; i < f; i++){
        for(auto j = 0; j < c; j++){
            sums[i] += matrix[c*i+j].value;
        }
    }
    int maxIndex = 0;
    for(auto s = 1; s < sums.size(); s++){
        if(sums[s] > sums[maxIndex]) maxIndex = s;
    }
    return maxIndex;
}
void Star::printAlignmentsToFile(unsigned int index, string path){
    /*The index is the best row*/
    vector<alignment> algs = vector<alignment>(seq.size());
    for(auto i = 0; i < seq.size(); i++)
        algs[i] = matrix[c*index+i].alg;
    Needleman_W temp(1,-2,-1);
    temp.printAlignmentsToFile(algs, path);
    //Convert all alignments to the same size
    std::ifstream input(path);
    vector<string> strs;
    if(!input.is_open()) cout << "Error al abrir el archivo star_alignments para leer\n";
    else{
        while (!input.eof())
        {
            string temp;
            std::getline(input,temp);
            if(temp != "") strs.push_back(temp);
        }
    }
    input.close();
    int largestStringIndex = 0;
    for(int i = 0; i < strs.size(); i++){
        if(strs[i].size() > strs[largestStringIndex].size())
            largestStringIndex = i;
    }
    for(auto& a : strs){
        while (a.size() < strs[largestStringIndex].size())
            a.push_back('-');
    }
    //Volver a escribir
    std::ofstream output(path);
    if(!output.is_open()) cout << "Error al abrir el archivo de star_alignments para escribir\n";
    else{
        for(auto& a : strs)
            output << a << "\n";
    }
    output.close();
}
