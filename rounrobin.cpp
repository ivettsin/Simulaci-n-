#include "rounrobin.hpp"
//#include "buddysystem"
//#include "mejorajuste"


// Establecer el quantum
void Roundrobin::setQuantum(int q) {
    if (q > 0 && q <= quantumMax) {
        quantum = q;
    }
    else {
        cout << "ERROR: Quantum no valido.\n";
    }
}

// Agregar un proceso a la cola
void Roundrobin::agregarProceso(Proceso* p) {
    cola.push(p);
}

// Ejecutar un proceso
void Roundrobin::ejecutar() {

    if (quantum <= 0) {
        return;
    }

    if (cola.empty()) {
        return;
    }

    Proceso* p = cola.front();
    cola.pop();

    cout << "\nAtendiendo proceso: ["<< p->getID() << "," << p->getTamano() << "," << p->getTiempores() << "]\n";
    
    mostrarCola();

    if (p->getTiempores() > quantum) {

        // El proceso no ha terminado
        p->setTiempores(p->getTiempores() - quantum);

        cola.push(p);
    }
    else {

        // El proceso terminó
        p->setTiempores(0);

        cout << "Descargando proceso: ["<< p->getID() << "," << p->getTamano() << "," << p->getTiempores() << "]\n";


        // Liberar su memoria

        if (Colocación == true){
            //liberarMemoria(p->getID()); de BF
        }
        else{
            //liberarMemoria(p->getID()); de buddy
        }
    }

}

// Mostrar los procesos pendientes
void Roundrobin::mostrarCola() {

    queue<Proceso*> aux = cola;
    if(!aux.empty())
        cout << "Lista RR: ";

    while (!aux.empty()) {
        cout << "["<< aux.front()->getID() << "," << aux.front()->getTamano() << "," << aux.front()->getTiempores()<< "] ";
        aux.pop();
    }

    cout << endl;
}