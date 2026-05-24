#include "../../include/ElementosInteractivos/animalherido.h"
#include "../../include/explorador.h"
#include <iostream>

AnimalHerido::AnimalHerido(std::string nombre)
: ElementoInteractivo(nombre) {
    curado = false;
}

void AnimalHerido::interactuar(Explorador* explorador) {
    if (curado == false) {
        curado = true;
        explorador->agregarPuntos(20);
        std::cout << "Animal curado" << '\n';
    }
}
