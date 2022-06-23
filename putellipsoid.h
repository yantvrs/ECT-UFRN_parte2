#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "sculptor.h"
#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica
{
    public:
        PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r,float _g,float _b,float _a);
        ~PutEllipsoid(){}

        void draw(Sculptor &t);
    protected:
        int xcenter, ycenter, zcenter, rx, ry, rz;
    private:

};
#endif // PUTELLIPSOID_H
