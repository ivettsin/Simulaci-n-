
#include <iostream>
#include "BuddySystem.h"
using namespace std;

int main() {

    BuddySystem memoria(1024, 32);

    cout << "       simulador BUDDY SYSTEM\n";


    cout << "memoria inicial:\n";
    memoria.mostrarMemoria();

    

    memoria.asignarMemoria(1, 100);
    memoria.mostrarMemoria();

    memoria.asignarMemoria(2, 240);
    memoria.mostrarMemoria();

    memoria.asignarMemoria(3, 64);
    memoria.mostrarMemoria();

    memoria.asignarMemoria(4, 256);
    memoria.mostrarMemoria();
    


    cout << "\n liberacion de procesos \n";

    memoria.liberarMemoria(3);
    memoria.mostrarMemoria();

    memoria.liberarMemoria(1);
    memoria.mostrarMemoria();

    memoria.liberarMemoria(2);
    memoria.mostrarMemoria();

    memoria.liberarMemoria(4);
    memoria.mostrarMemoria();

    cout << "\n simulacion finalizada \n";

    return 0;

}
