#include "../include/explorador.h"
#include "../include/zona.h"
#include <iostream>

Explorador::Explorador(std::string nombre) {
    this->nombre = nombre;
    energia = 100;
    puntajeAmbiental = 0;
    zonaActual = nullptr;
}

void Explorador::cambiarZona(Zona* zona) {
    zonaActual = zona;
}

void Explorador::consumirEnergia(int cantidad) {
    energia -= cantidad;
    if (energia < 0) {
        energia = 0;
    }
}

void Explorador::recuperarEnergia(int cantidad) {
    energia += cantidad;
}

void Explorador::agregarPuntos(int puntos) {
    puntajeAmbiental += puntos;
}

void Explorador::mostrarEstado() {
    std::cout << "Explorador: " << nombre << '\n';
    std::cout << "Energia: " << energia << '\n';
    std::cout << "Puntaje: " << puntajeAmbiental << '\n';
    if (zonaActual != nullptr) {
        std::cout << "Zona actual: " << zonaActual->getNombre() << '\n';
    }
}

Zona* Explorador::getZonaActual() {
    return zonaActual;

}
