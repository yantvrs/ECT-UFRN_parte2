#include "cutellipsoid.h"
#include <cmath>


CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx      = _rx;
    ry      = _ry;
    rz      = _rz;
    r       = _r;
    g       = _g;
    b       = _b;
    a       = _a;
}

CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);
    float elipsoid;
       for(int i = xcenter - rx; i < xcenter + rx; i++){
           for(int j = ycenter - ry; j < ycenter + ry; j++){
               for(int k = zcenter - rz; k < zcenter + rz; k++){
                   elipsoid = pow(i - xcenter, 2)/pow(rx,2) + pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2);
                   if(elipsoid < 1){
                       t.cutVoxel(i,j,k);
                   }
               }
           }
       }
}

