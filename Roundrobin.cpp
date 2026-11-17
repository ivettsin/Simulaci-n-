#include "Procesos.hpp"
#include "Buddysystem.cpp"
#include  <iostream>
#include <queue>
#pragma once

using namespace std;

class Roundrobin{
 private:
    queue<Proceso>cola;
    int quantum,quantumMax;
 public:
    Roundrobin(int qMax) : quantum(0), quantumMax(qMax) {}

    void setQuantum(int q){
        if(q>0 && q<=quantumMax){
            this->quantum= q;
        }
        else 
            cout << "ERROR";
            return;
    }

    void agregarProceso(Proceso p){
        this->cola.push(p);
    }

    void ejecutar(){
        if(cola.empty()){
            cout << " No hay procesos pendientes ";
            return;
        }
        Proceso p= cola.front();
        cola.pop();
        cout << "Atendiendo proceso: [ " << p.getID() << "," << p.getTamano() << "," << p.getTiempores() << "] " << endl;
       
        if (p.getTiempores() > quantum){
            p.setTiempores(p.getTiempores()-quantum);
            cola.push(p);
            mostrarCola();
        }
        else{
            mostrarCola();
            p.setTiempores(0);
            cout << "Descargando proceso: [" << p.getID() << "," << p.getTamano() << "," << p.getTiempores() << "] " << endl;
            // liberarProceso(p.getID());
        }
    }

    void mostrarCola() {
        queue<Proceso> aux = cola;
        cout << "Lista RR: ";
        while (!aux.empty()) {
            cout << "[" << aux.front().getID() << "," << aux.front().getTamano() << "," << aux.front().getTiempores()
                << "] ";

            aux.pop();
        }
        cout << endl;
    }
};
