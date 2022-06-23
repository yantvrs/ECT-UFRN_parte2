#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "figurageometrica.h"

using namespace std;

class Interpretador{
    public:
        Interpretador();

            vector<FiguraGeometrica*> parse(string filename);
            int getDx();
            int getDy();
            int getDz();

    protected:

            int dx, dy, dz;
            float r, g, b, a;

    private:
};

#endif // INTERPRETADOR_H
