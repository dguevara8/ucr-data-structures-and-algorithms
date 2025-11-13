#include <iostream>
#include <vector>
#include "HashTable.h"  // Incluir la definición de la clase HashTable

using namespace std;

int main() {
    HashTable hashTable;  // Crear una instancia de la tabla hash
    int option;
    string key;
    int value;

    while (true) {
        cout << "\n=== Menú de Operaciones ===\n";
        cout << "1. Agregar un par clave-valor (set)\n";
        cout << "2. Obtener todas las claves (keys)\n";
        cout << "3. Imprimir la tabla hash\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        vector<string> claves;

        switch (option) {
            case 1:  // Agregar un par clave-valor
                cout << "Ingrese la clave: ";
                cin >> key;
                cout << "Ingrese el valor: ";
                cin >> value;
                hashTable.set(key, value);
                cout << "Par clave-valor agregado con éxito.\n";
                break;

            case 2:  // Obtener todas las claves
                cout << "Claves almacenadas en la tabla hash:\n";
                claves = hashTable.keys();  // Llamar al método keys()
                for (string clave : claves) {
                    cout << clave << endl;
                }
                break;

            case 3:  // Imprimir la tabla hash
                hashTable.printTable();
                break;

            case 4:  // Salir
                cout << "Saliendo del programa...\n";
                return 0;

            default:  // Opción inválida
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    }

    return 0;
}
