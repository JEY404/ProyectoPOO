#ifndef ESTACIONENERGIA_H
#define ESTACIONENERGIA_H
#include "../elementointeractivo.h"

class EstacionEnergia:public ElementoInteractivo{
private:
    int energiaDisponible;
public:
    EstacionEnergia(std::string nombre,int energia);
    void interactuar(Explorador* explorador);
};

#endif
