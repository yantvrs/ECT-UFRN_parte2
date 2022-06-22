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

    fin.open("ect2.off");

    if(!fin.is_open()){
        exit(0);
    }

    int nx, ny, nz;

    getline(fin, s);
    ss.clear();
    ss.str(s);
    ss >> s;
    ss >> nx >> ny >> nz;


    Sculptor t(nx, ny, nz);











    fin.close();

    for(int i=0; i<int(figura.size()); i++){
        figura[i]->draw(t);
    }

    t.writeOFF((char*)"ect2.off");
    return 0;
}
