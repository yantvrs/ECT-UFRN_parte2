#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica{

    public:
        CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
        ~CutEllipsoid(){}
        void draw(Sculptor &t);
    protected:
            int xcenter, ycenter, zcenter, rx, ry, rz;
    private:
};

#endif // CUTELLIPSOID_H
