#pragma once

#include "Procesos.hpp"
#include <iostream>
#include <queue>

using namespace std;

 //class buddy;
 // clase de mejor ajuste

class Roundrobin {
private:
    bool Colocación; // true = Mejor Ajuste, false = Buddy System
    
    // bf = nullptr; modificar cuando tengas mejor ajuste 
    //buddy = nullptr;

    queue<Proceso*> cola;
    int quantum;
    int quantumMax;



public:
    Roundrobin(int qMax): quantum(0), quantumMax(qMax) {}

    /*void conectarBuddy(....* b) {
        buddy = b;
    }

    void conectarMejorAjuste(...*m) {
        bf = m;
    }*/

    void setColocacion(bool c) {
        Colocación = c;
    }

    void setQuantum(int q);

    void agregarProceso(Proceso* p);

    void ejecutar();

    void mostrarCola();
};