
#include "buddysystem.h"
#include <algorithm>

BuddySystem::BuddySystem(int memoria, int minimo) {

    memoriaTotal = memoria;
    divisionMinima = minimo;

    bloques.push_back({0, memoriaTotal, 0});
}

int BuddySystem::calcularBloque(int solicitado) {

    int tamano = divisionMinima;

    while (tamano < solicitado) {
        tamano *= 2;
    }

    return tamano;
}

void BuddySystem::ordenarBloques() {

    sort(bloques.begin(), bloques.end(),
        [](Bloque a, Bloque b) {
            return a.inicio < b.inicio;
        });
}

void BuddySystem::asignarMemoria(int id, int solicitado) {

    if (solicitado <= 0) {
        cout << "tamaño no valido.\n";
        return;
    }

    int necesario = calcularBloque(solicitado);
    int posicion = -1;

    cout << "\nllega proceso " << id
         << " - solicita " << solicitado << " KB\n";

    // Buscar el bloque disponible mas pequeno
    for (int i = 0; i < bloques.size(); i++) {

        if (bloques[i].idProceso == 0 &&
            bloques[i].tamano >= necesario) {

            if (posicion == -1 ||
                bloques[i].tamano < bloques[posicion].tamano) {
                posicion = i;
            }
        }
    }

    if (posicion == -1 || necesario > memoriaTotal) {
        cout << "no hay memoria disponible \n";
        return;
    }

    // Dividir el bloque
    while (bloques[posicion].tamano > necesario) {

        int mitad = bloques[posicion].tamano / 2;

        cout << "dividiendo bloque de "
             << bloques[posicion].tamano << " KB\n";

        bloques[posicion].tamano = mitad;

        bloques.push_back({
            bloques[posicion].inicio + mitad, mitad, 0
        });
    }

    bloques[posicion].idProceso = id;

    cout << "Proceso asignado correctamente \n";
    cout << "Memoria desperdiciada: "
         << necesario - solicitado << " KB\n";

    ordenarBloques();
}

void BuddySystem::unirBloques(int inicio, int tamano) {

    while (tamano < memoriaTotal) {

        int buddy = inicio ^ tamano;
        int posicion = -1;

        // Buscar al compañero libre
        for (int i = 0; i < bloques.size(); i++) {

            if (bloques[i].inicio == buddy &&
                bloques[i].tamano == tamano &&
                bloques[i].idProceso == 0) {

                posicion = i;
                break;
            }
        }

        if (posicion == -1) {
            break;
        }

        // Buscar el bloque que se acaba de liberar
        int actual = -1;

        for (int i = 0; i < bloques.size(); i++) {

            if (bloques[i].inicio == inicio &&
                bloques[i].tamano == tamano &&
                bloques[i].idProceso == 0) {

                actual = i;
                break;
            }
        }

        if (actual == -1) {
            break;
        }

        // Eliminar ambos bloques
        int mayor = max(actual, posicion);
        int menor = min(actual, posicion);

        bloques.erase(bloques.begin() + mayor);
        bloques.erase(bloques.begin() + menor);

        // Crear el bloque unido
        inicio = min(inicio, buddy);
        tamano *= 2;

        bloques.push_back({inicio, tamano, 0});

        cout << "bloques unidos: " << tamano << " KB\n";
    }

    ordenarBloques();
}

void BuddySystem::liberarMemoria(int id) {

    for (int i = 0; i < bloques.size(); i++) {

        if (bloques[i].idProceso == id) {

            int inicio = bloques[i].inicio;
            int tamano = bloques[i].tamano;

            bloques[i].idProceso = 0;

            cout << "\n Liberando proceso " << id << "\n";

            unirBloques(inicio, tamano);

            cout << "La memoria se libero correctamente \n";
            return;
        }
    }

    cout << "Proceso no encontrado. \n";
}

void BuddySystem::mostrarMemoria() {

    cout << "\n MEMORIA \n";

    for (int i = 0; i < bloques.size(); i++) {

        cout << "[" << bloques[i].inicio << " - "
             << bloques[i].inicio + bloques[i].tamano << ") ";

        cout << bloques[i].tamano << " KB ";

        if (bloques[i].idProceso == 0)
            cout << "LIBRE\n";
        else
            cout << "PROCESO " << bloques[i].idProceso << "\n";
    }

    cout << endl;
}
