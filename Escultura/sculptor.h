#ifndef SCULPTOR_H
#define SCULPTOR_H


struct Voxel{

    float r, g, b, a;
    bool isOn;

};

//Classe
class Sculptor{

protected:

    Voxel ***v; //Matriz 3d
    int nx, ny, nz; //Dimensões da matriz
    float r, g, b, a; //Manipulação de cores

public:

    //Construtor e destrutor
    Sculptor(int _nx, int _ny, int _nz); //Construtor
    ~Sculptor(); //Destrutor

    //Declaração dos métodos
    void setColor(float color_r, float color_g, float color_b, float alpha); //Cores
    void putVoxel(int x, int y, int z); //Adiciona voxel nas posições especificadas
    void cutVoxel(int x, int y, int z); //Remove voxel nas posições especificadas
    void writeOFF(char* filename); //Arquivo .off

};

#endif // SCULPTOR_H

