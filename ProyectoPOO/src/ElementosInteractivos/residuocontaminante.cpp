#include "../../include/ElementosInteractivos/residuocontaminante.h"
#include "../../include/explorador.h"
#include <iostream>

ResiduoContaminante::ResiduoContaminante(std::string nombre,int toxicidad)
:ElementoInteractivo(nombre){
    nivelToxicidad=toxicidad;
}

void ResiduoContaminante::interactuar(Explorador* explorador){
    explorador->consumirEnergia(nivelToxicidad);
    explorador->agregarPuntos(10);
    std::cout<<"Residuo limpiado"<<'\n';
}
