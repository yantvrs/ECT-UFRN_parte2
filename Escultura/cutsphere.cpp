#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a){

    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius  = _radius;


    r = _r;
    g = _g;
    b = _b;
    a = _a;

}

CutSphere::~CutSphere(){

}

void CutSphere::draw(Sculptor &fout){
    float sphere;
    fout.setColor(r, g, b, a);
    for(int i = (xcenter-radius); i < (xcenter+radius); i++ ){
        for(int  j = (ycenter-radius); j < (ycenter+radius) ; j++ ){
            for(int k = (zcenter-radius); k < (zcenter+radius) ; k++ ){
                sphere = ((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter));
                if(sphere < pow(radius,2)){
                    fout.cutVoxel(i,j,k);
                }
            }
        }
    }
}
