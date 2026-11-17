#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H

#include <iostream>
#include <vector>

using namespace std;

class BuddySystem{

    private:

        struct Bloque{
            int inicio;
            int tamano;
            int idProceso;
        };
        
        int memoriaTotal;
        int divisionMinima;

        vector<Bloque> bloques;

        int calcularBloque(int solicitado);
        void ordenarBloques();
        void unirBloques(int inicio, int tamano);
    
    public:

        BuddySystem(int memoria, int minimmo);
        void asignarMemoria(int id, int solicitado);
        void liberarMemoria(int id);
        void mostrarMemoria();
};
#endif