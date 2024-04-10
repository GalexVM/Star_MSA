#include "Star.h"

vector<string> Star::readStrings(ReadMode rm, string file){ //Reads and saves
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
        sums = vector<Node>(c);
    }
    return cadenas;
}