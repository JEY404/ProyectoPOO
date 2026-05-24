#include "../include/reserva.h"
#include <iostream>

Reserva::Reserva() {
}

Reserva::~Reserva() {
    for (auto zona : zonas) {
        delete zona.second;
    }
}

void Reserva::agregarZona(std::string codigo, Zona* zona) {
    zonas[codigo] = zona;
}

Zona* Reserva::buscarZona(std::string codigo) {
    if (zonas.find(codigo) != zonas.end()) {
        return zonas[codigo];
    }
    return nullptr;
}

void Reserva::mostrarZonas() {
    for (auto zona : zonas) {
        std::cout << zona.first << std::endl;
    }
}

void Reserva::mostrarElementosZona(Zona* zona) {
    zona->mostrarElementos();
}

void Reserva::contarElementos(Zona* zona) {
    zona->mostrarElementos();
}

void Reserva::mostrarEstadoZona(Zona* zona) {
    std::cout << zona->getNombre() << std::endl;
}
