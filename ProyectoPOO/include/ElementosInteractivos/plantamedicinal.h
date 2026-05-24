#ifndef PLANTAMEDICINAL_H
#define PLANTAMEDICINAL_H
#include "../elementointeractivo.h"

class PlantaMedicinal:public ElementoInteractivo{
private:
    int energiaRecuperada;
public:
    PlantaMedicinal(std::string nombre,int energia);
    void interactuar(Explorador* explorador);
};

#endif
