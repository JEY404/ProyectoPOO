#include "../../include/ElementosInteractivos/plantamedicinal.h"
#include "../../include/explorador.h"
#include <iostream>

PlantaMedicinal::PlantaMedicinal(std::string nombre,int energia)
:ElementoInteractivo(nombre){
    energiaRecuperada=energia;
}

void PlantaMedicinal::interactuar(Explorador* explorador){
    explorador->recuperarEnergia(energiaRecuperada);
    std::cout<<"Energia recuperada"<<'\n';
}
