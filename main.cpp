//#include "Needleman_W.h"
#include "Star.h"

int main() {
    string cadena1, cadena2;
    Needleman_W NW_alg(1, -2, -1);
    NW_alg.leerInputs(cadena1, cadena2, "../inputNW.txt");
    auto rec = NW_alg.calculate(cadena1, cadena2);
    cout << "score: " << NW_alg.lastScore << std::endl;

    Star star;
    vector<string> cadenas = star.readStrings(forward, "../inputStar.txt");
    for(auto a : cadenas){
        cout<< a<<"\n";
    }
}