#include "Star.h"

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
            //TODO: inversión de cadenas
            for(auto i = 0; i < 12; i++){
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