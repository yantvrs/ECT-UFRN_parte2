#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
//Construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel **[nx];

    for(int i = 0; i < nx ; i++){
        v[i] = new Voxel *[ny];
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }

    for(int i= 0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}
//Destrutor
Sculptor::~Sculptor(){

    for(int i=0; i<nx; i++){

        for(int j=0; j<ny; j++){

            delete[] v[i][j];

        }

    }
    for(int i = 0; i < nx; i++){

        delete[] v[i];

    }

    delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _alpha){

    r = _r;
    g = _g;
    b = _b;
    a = _alpha;

}

void Sculptor::putVoxel(int x, int y, int z){

    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;

}

void Sculptor::cutVoxel(int x, int y, int z){

    v[x][y][z].isOn = false;

}

void Sculptor::writeOFF(char *filename){
    int total;
    std::ofstream f;
    total = 0;
    f.open(filename);
    if(!f.is_open()){
        std::cout << "ERRO!\n";
        exit(0);
    }
    f<<"OFF\n";
    for(int i=0; i<nx; i++){

        for(int j=0; j<ny; j++){

            for(int k=0; k<nz; k++){

                if(v[i][j][k].isOn == true){
                    total ++;

                }

            }

        }

    }
    cout<<total<<endl;
    f << total*8 << " " << total*6 << " 0\n";
    for(int x=0; x<nx; x++){

        for(int y=0; y<ny; y++){

            for(int z=0; z<nz; z++){

                if(v[x][y][z].isOn==true){

                    f << -0.5 + x << " " <<  0.5 + y << " " << -0.5 + z << "\n";
                    f << -0.5 + x << " " << -0.5 + y << " " << -0.5 + z << "\n";
                    f <<  0.5 + x << " " << -0.5 + y << " " << -0.5 + z << "\n";
                    f <<  0.5 + x << " " <<  0.5 + y << " " << -0.5 + z << "\n";
                    f << -0.5 + x << " " <<  0.5 + y << " " <<  0.5 + z << "\n";
                    f << -0.5 + x << " " << -0.5 + y << " " <<  0.5 + z << "\n";
                    f <<  0.5 + x << " " << -0.5 + y << " " <<  0.5 + z << "\n";
                    f <<  0.5 + x << " " <<  0.5 + y << " " <<  0.5 + z << "\n";

                }

            }

        }

    }

    int contador = 0;

    for(int x=0; x<nx; x++){

        for(int y=0; y<ny; y++){

            for(int z=0; z<nz; z++){

                if(v[x][y][z].isOn==true){

                    f << 4 << " " << 0+(contador*8) << " " << 3+(contador*8) << " " << 2+(contador*8) << " " << 1+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 4+(contador*8) << " " << 5+(contador*8) << " " << 6+(contador*8) << " " << 7+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 0+(contador*8) << " " << 1+(contador*8) << " " << 5+(contador*8) << " " << 4+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 0+(contador*8) << " " << 4+(contador*8) << " " << 7+(contador*8) << " " << 3+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 3+(contador*8) << " " << 7+(contador*8) << " " << 6+(contador*8) << " " << 2+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    f << 4 << " " << 1+(contador*8) << " " << 2+(contador*8) << " " << 6+(contador*8) << " " << 5+(contador*8) << " ";
                    f << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";

                    contador++;

                }
            }
        }
    }

    f.close();

}
