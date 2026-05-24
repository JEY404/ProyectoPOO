#ifndef PORTALTP_H
#define PORTALTP_H
#include "../elementointeractivo.h"

class Zona;
class Portaltp:public ElementoInteractivo{
private:
    Zona* destino;
public:
    Portaltp(std::string nombre,Zona* destino);
    void interactuar(Explorador* explorador);
};

#endif
