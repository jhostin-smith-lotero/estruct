#include "HistorialNavegacion.h"

#include <ctime>
#include <iostream>

HistorialNavegacion::HistorialNavegacion() : tieneSitioActual(false) {}

std::string HistorialNavegacion::obtenerFechaHoraActual() const {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* fechaLocal = std::localtime(&tiempoActual);

    char bufferFecha[20];
    std::strftime(bufferFecha, sizeof(bufferFecha), "%Y-%m-%d %H:%M:%S", fechaLocal);
    return std::string(bufferFecha);
}

void HistorialNavegacion::abrirSitio(const std::string& sitioVisitado, int idUsuario) {
    if (tieneSitioActual) {
        pilaAtras.apilar(sitioActual);
    }

    pilaAdelante.limpiar();

    sitioActual = {sitioVisitado, obtenerFechaHoraActual(), idUsuario};
    tieneSitioActual = true;

    std::cout << "\nSitio abierto correctamente.\n";
    mostrarSitioActual();
}

void HistorialNavegacion::irAtras() {
    if (pilaAtras.estaVacia()) {
        std::cout << "\nNo hay páginas para retroceder.\n";
        return;
    }

    if (tieneSitioActual) {
        pilaAdelante.apilar(sitioActual);
    }

    sitioActual = pilaAtras.cima();
    pilaAtras.desapilar();
    tieneSitioActual = true;

    std::cout << "\nRetrocediste una página.\n";
    mostrarSitioActual();
}

void HistorialNavegacion::irAdelante() {
    if (pilaAdelante.estaVacia()) {
        std::cout << "\nNo hay páginas para avanzar.\n";
        return;
    }

    if (tieneSitioActual) {
        pilaAtras.apilar(sitioActual);
    }

    sitioActual = pilaAdelante.cima();
    pilaAdelante.desapilar();
    tieneSitioActual = true;

    std::cout << "\nAvanzaste una página.\n";
    mostrarSitioActual();
}

void HistorialNavegacion::cerrarSitioActual() {
    if (!tieneSitioActual) {
        std::cout << "\nNo hay un sitio abierto para cerrar.\n";
        return;
    }

    std::cout << "\nSitio cerrado: " << sitioActual.sitioVisitado << "\n";

    if (!pilaAtras.estaVacia()) {
        sitioActual = pilaAtras.cima();
        pilaAtras.desapilar();
        std::cout << "Regresaste al sitio anterior.\n";
        mostrarSitioActual();
        return;
    }

    tieneSitioActual = false;
    pilaAdelante.limpiar();
    std::cout << "No quedan sitios abiertos.\n";
}

void HistorialNavegacion::mostrarSitioActual() const {
    if (!tieneSitioActual) {
        std::cout << "No hay sitio actual abierto.\n";
        return;
    }

    std::cout << "Sitio actual: " << sitioActual.sitioVisitado << "\n"
              << "Fecha visita: " << sitioActual.fechaVisita << "\n"
              << "ID usuario: " << sitioActual.idUsuario << "\n";
}

void HistorialNavegacion::responderPreguntasTeoricas() const {
    std::cout << "\n=== Respuestas Teóricas ===\n";
    std::cout << "1) ¿La pila fue adecuada?\n";
    std::cout << "Sí. Para atrás/adelante, la pila es adecuada por su comportamiento LIFO.\n";
    std::cout << "La recomendación práctica es usar dos pilas: una para retroceder y otra para avanzar.\n\n";

    std::cout << "2) Complejidad BigO de las 4 operaciones:\n";
    std::cout << "- abrirSitio: O(1) en operaciones de pila; limpiar pilaAdelante puede ser O(n).\n";
    std::cout << "- irAtras: O(1).\n";
    std::cout << "- irAdelante: O(1).\n";
    std::cout << "- cerrarSitioActual: O(1) normalmente; O(n) si se limpia pilaAdelante completa.\n";
}
