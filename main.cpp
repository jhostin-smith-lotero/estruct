#include <iostream>
#include <limits>
#include <string>

#include "HistorialNavegacion.h"

int leerOpcionMenu() {
    int opcionMenu;

    while (true) {
        std::cout << "\n===== MENÚ HISTORIAL =====\n";
        std::cout << "1. Abrir un sitio\n";
        std::cout << "2. Ir hacia atrás\n";
        std::cout << "3. Ir hacia adelante\n";
        std::cout << "4. Cerrar sitio actual\n";
        std::cout << "5. Ver sitio actual\n";
        std::cout << "6. Ver respuestas teóricas\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";

        if (std::cin >> opcionMenu) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return opcionMenu;
        }

        std::cout << "Entrada inválida. Intente nuevamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    HistorialNavegacion historialNavegacion;
    int opcionMenu;

    do {
        opcionMenu = leerOpcionMenu();

        switch (opcionMenu) {
            case 1: {
                std::string sitioVisitado;
                int idUsuario;

                std::cout << "Ingrese URL o nombre del sitio: ";
                std::getline(std::cin, sitioVisitado);

                std::cout << "Ingrese ID de usuario: ";
                while (!(std::cin >> idUsuario)) {
                    std::cout << "ID inválido. Ingrese un número entero: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                historialNavegacion.abrirSitio(sitioVisitado, idUsuario);
                break;
            }
            case 2:
                historialNavegacion.irAtras();
                break;
            case 3:
                historialNavegacion.irAdelante();
                break;
            case 4:
                historialNavegacion.cerrarSitioActual();
                break;
            case 5:
                historialNavegacion.mostrarSitioActual();
                break;
            case 6:
                historialNavegacion.responderPreguntasTeoricas();
                break;
            case 0:
                std::cout << "\nSaliendo del programa...\n";
                break;
            default:
                std::cout << "\nOpción no válida.\n";
                break;
        }
    } while (opcionMenu != 0);

    return 0;
}
