#ifndef PILA_H
#define PILA_H

#include <stdexcept>

// Implementación simple de pila (LIFO) con lista enlazada.
template <typename TipoDato>
class Pila {
private:
    struct Nodo {
        TipoDato dato;
        Nodo* siguiente;

        Nodo(const TipoDato& nuevoDato, Nodo* nuevoSiguiente)
            : dato(nuevoDato), siguiente(nuevoSiguiente) {}
    };

    Nodo* cimaNodo;
    int cantidad;

public:
    Pila() : cimaNodo(nullptr), cantidad(0) {}

    ~Pila() {
        limpiar();
    }

    Pila(const Pila&) = delete;
    Pila& operator=(const Pila&) = delete;

    bool estaVacia() const {
        return cimaNodo == nullptr;
    }

    int tamano() const {
        return cantidad;
    }

    void apilar(const TipoDato& valor) {
        cimaNodo = new Nodo(valor, cimaNodo);
        ++cantidad;
    }

    void desapilar() {
        if (estaVacia()) {
            throw std::out_of_range("No se puede desapilar: la pila está vacía.");
        }

        Nodo* nodoEliminar = cimaNodo;
        cimaNodo = cimaNodo->siguiente;
        delete nodoEliminar;
        --cantidad;
    }

    TipoDato& cima() {
        if (estaVacia()) {
            throw std::out_of_range("No se puede consultar cima: la pila está vacía.");
        }
        return cimaNodo->dato;
    }

    const TipoDato& cima() const {
        if (estaVacia()) {
            throw std::out_of_range("No se puede consultar cima: la pila está vacía.");
        }
        return cimaNodo->dato;
    }

    void limpiar() {
        while (!estaVacia()) {
            desapilar();
        }
    }
};

#endif
