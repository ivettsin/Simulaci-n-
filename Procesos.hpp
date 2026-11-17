
#pragma once

class Proceso
{
protected:
    int id;
    int tamano;
    int tiempoTotal;
    int tiempoRestante;
public:
    Proceso(int id, int tamano, int tiempo): id(id),tamano(tamano),
    tiempoTotal(tiempo),tiempoRestante(tiempo) {}

    int getID(){
        return this->id;
    }
    int getTamano(){
        return this->tamano;
    }
    int getTiempotot(){
        return this->tiempoTotal;
    }
    int getTiempores(){
        return this->tiempoRestante;
    }
   void setTiempores(int t){
        this->tiempoRestante=t;
    }
    
};


