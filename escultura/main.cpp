#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "sculptor.h"
#include "interpretador.h"


using namespace std;

int main()
{



    Sculptor *nave;
    Interpretador parser;
    vector<FiguraGeometrica*> figuras;

    figuras = parser.parse("teste.txt");

    nave = new Sculptor(parser.getDx(), parser.getDy(), parser.getDz());

    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*nave);
    }

    nave -> writeOFF((char*)"teste.off");

    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete nave;
    return 0;

}
