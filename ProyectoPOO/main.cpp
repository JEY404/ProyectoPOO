#include <iostream>
#include <string>
#include "include/ecomision.h"

void mostrarMenu() {
    std::cout << "\n                 MENU               \n";
    std::cout << "1. Mostrar las zonas de la reserva\n";
    std::cout << "2. Mostrar los exploradores\n";
    std::cout << "3. Interactuar con un objeto de la zona\n";
    std::cout << "4. Reporte de exploradores y destinos disponibles\n";
    std::cout << "5. Crear un nuevo explorador\n";
    std::cout << "0. Salir del programa\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    EcoMision* experienciaInteractiva = new EcoMision();
    experienciaInteractiva->iniciarSistema();

    int opcion = -1;
    while (opcion != 0) {
        mostrarMenu();
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::string descarte;
            std::cin >> descarte;
            continue;
        }

        std::cout << "\n----------------------------------------------------\n";

        switch (opcion) {
            case 1:
                experienciaInteractiva->mostrarInformacion();
                break;
            case 2:
                experienciaInteractiva->buscarExplorador();
                break;
            case 3: {
                int idx = experienciaInteractiva->seleccionarExplorador();
                if (idx != -1) {
                    Explorador* exp = experienciaInteractiva->getExplorador(idx);
                    Zona* z = exp->getZonaActual();

                    std::cout << "Elementos disponibles:\n";
                    z->mostrarElementos();

                    std::cout << "\nDesea ingresar?\n1. Por número\n2. Por nombre\nOpcion: ";
                    int modo;
                    std::cin >> modo;

                    if (modo == 1) {
                        int sel;
                        std::cout << "Ingresa tu número: ";
                        std::cin >> sel;
                        z->interactuarConElemento(sel - 1, exp);
                    } else if (modo == 2) {
                        std::string nombre;
                        std::cout << "Ingrese el nombre del objeto: ";
                        std::cin.ignore();
                        std::getline(std::cin, nombre);
                        z->interactuarConElemento(nombre, exp);
                    } else {
                        std::cout << "Opción incorrecta, parce\n";
                    }
                }
                break;
            }
            case 4: {
                std::cout << "\n Reporte de Exploradores y Destinos \n";
                for (int i = 0; i < experienciaInteractiva->cantidadExploradores(); i++) {
                    Explorador* exp = experienciaInteractiva->getExplorador(i);
                    Zona* z = exp->getZonaActual();
                    std::cout << "\n" << (i + 1) << ". " << exp->getNombre()
                              << " está en: " << z->getNombre() << "\n";
                    std::cout << "Elementos/Destinos en esta zona:\n";
                    z->mostrarElementos();
                    std::cout << "\n----------------------------------------------------\n";
                }
                break;
            }
            case 5: {
                std::string nombre;
                std::cout << "Nombre del nuevo explorador: ";
                std::cin.ignore(); getline(std::cin, nombre);
                experienciaInteractiva->crearExplorador(nombre);
                experienciaInteractiva->asignarZonaInicial();
                break;
            }
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
    delete experienciaInteractiva;
    return 0;
}