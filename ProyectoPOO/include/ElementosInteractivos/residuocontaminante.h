#ifndef RESIDUOCONTAMINANTE_H
#define RESIDUOCONTAMINANTE_H
#include "../elementointeractivo.h"

class ResiduoContaminante:public ElementoInteractivo{
private:
    int nivelToxicidad;
public:
    ResiduoContaminante(std::string nombre,int toxicidad);
    void interactuar(Explorador* explorador);
};

#endif
