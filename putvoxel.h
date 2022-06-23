#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica{
    public:
        PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
        ~PutVoxel(){}
        void draw(Sculptor &t);

    protected:
        int x, y, z;

    private:
};

#endif // PUTVOXEL_H
