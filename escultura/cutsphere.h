#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "sculptor.h"
#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica
{

    public:
        CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
        ~CutSphere(){}

        void draw(Sculptor &t);

    protected:
        int xcenter, ycenter, zcenter, radius;
    private:

};

#endif // CUTSPHERE_H
