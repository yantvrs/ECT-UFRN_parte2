#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){
    ifstream fin;
    string s;
    stringstream ss;
    vector <FiguraGeometrica*> figura;

    fin.open("C:/Users/yanta/off_sculptor/esculturas/teste.txt");
    if(!fin.is_open()){
        exit(0);
    }

    int nx, ny, nz;

    getline(fin, s);
    ss.clear();
    ss.str(s);
    ss >> s;
    ss >> nx >> ny >> nz;
//    cout << s << endl;
//    cout << nx << ny << nz << endl;

    Sculptor t(nx, ny, nz);

    while(getline(fin, s)){
        ss.clear();
        ss.str(s);
        ss >> s;
//        cout << s << endl;

        if(s.compare("putvoxel")==0){
            int x, y, z;
            float r, g, b, a;

            ss >> x >> y >> z >> r >> g >> b >> a;
            cout << x << y << z << r << g << b << a;
            figura.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }
        if(s.compare("cutvoxel")==0){
            int x, y, z;
            float r, g, b, a;

            ss >> x >> y >> z >> r >> g >> b >> a;
            cout << x << y << z << r << g << b << a;
            figura.push_back(new CutVoxel(x, y, z, r, g, b, a));
        }
        if(s.compare("putbox")==0){
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figura.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        if(s.compare("cutbox")==0){
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figura.push_back(new CutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        if(s.compare("putsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figura.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        if(s.compare("cutsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figura.push_back(new CutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        if(s.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figura.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
        }
        if(s.compare("cutellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figura.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
        }
    }

    fin.close();

    for(int i=0; i<int(figura.size()); i++){
        figura[i]->draw(t);
    }

    t.writeOFF((char*)"C:/Users/yanta/off_sculptor/esculturas//teste.off");
    return 0;
}
