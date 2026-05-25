#include "../include/zona.h"
#include "../include/explorador.h"
#include <iostream>

Zona::Zona(std::string codigo, std::string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

Zona::~Zona() {
    for (ElementoInteractivo* elemento : elementos) {
        delete elemento;
    }
}

void Zona::agregarElemento(ElementoInteractivo* elemento) {
    elementos.push_back(elemento);
}

void Zona::mostrarElementos() {
    for (int i = 0; i < elementos.size(); i++) {
        std::cout << (i + 1) << ". " << elementos[i]->getNombre() << std::endl;
    }
}

void Zona::interactuarConElemento(int indice, Explorador* explorador) {
    if (indice >= 0 && indice < elementos.size()) {
        elementos[indice]->interactuar(explorador);
    }
}

void Zona::interactuarConElemento(std::string nombre, Explorador* explorador) {
    for (ElementoInteractivo* elemento : elementos) {
        if (elemento->getNombre() == nombre) {
            elemento->interactuar(explorador);
        }
    }
}

std::string Zona::getNombre() {
    return nombre;
}
