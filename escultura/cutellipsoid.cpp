#include "cutellipsoid.h"



CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx      = _rx;
    ry      = _ry;
    rz      = _rz;

}



void CutEllipsoid::draw(Sculptor &t){
    for(int x=(xcenter-rx); x<(xcenter+rx); x++){
        for(int y=(ycenter-ry); y<(ycenter+ry); y++){
            for(int z=(zcenter-rz); z<(zcenter+rz); z++){
                float t1 = ((float)(x-xcenter)/(float)rx)*((float)(x-xcenter)/(float)rx);
                float t2 = ((float)(y-ycenter)/(float)ry)*((float)(y-ycenter)/(float)ry);
                float t3 = ((float)(z-zcenter)/(float)rz)*((float)(z-zcenter)/(float)rz);
                if(t1 + t2 + t3<=1.0){
                    t.cutVoxel(x,y,z);
                }
            }
        }
    }
}

