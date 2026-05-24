#include "../../include/ElementosInteractivos/estacionenergia.h"
#include "../../include/explorador.h"
#include <iostream>

EstacionEnergia::EstacionEnergia(std::string nombre,int energia)
:ElementoInteractivo(nombre){
    energiaDisponible=energia;
}

void EstacionEnergia::interactuar(Explorador* explorador){
    explorador->recuperarEnergia(energiaDisponible);
    std::cout<<"Energia restaurada"<<'\n';

}
