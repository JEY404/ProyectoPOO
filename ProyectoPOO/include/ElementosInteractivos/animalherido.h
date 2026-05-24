#ifndef ANIMALHERIDO_H
#define ANIMALHERIDO_H
#include "../elementointeractivo.h"

class AnimalHerido : public ElementoInteractivo {
private:
    bool curado;

public:
    AnimalHerido(std::string nombre);
    void interactuar(Explorador* explorador);
};

#endif
