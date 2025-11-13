#include <iostream>
#include "Queue.h"

using namespace std;


int main() {
    Queue cola;
    int option, value, priority;

    while (true) {
        cout << "\n=== Sistema de Tickets ===\n";
        cout << "1. Agregar ticket (enqueue)\n";
        cout << "2. Desencolar ticket (dequeue)\n";
        cout << "3. Ver ticket con mayor prioridad (front)\n";
        cout << "4. Actualizar prioridad de un ticket\n";
        cout << "5. Ver todos los tickets\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1:  // Agregar ticket
                cout << "Ingrese el número del ticket: ";
                cin >> value;
                cout << "Ingrese la prioridad del ticket: ";
                cin >> priority;
                cola.enqueue(value, priority);
                cout << "Ticket agregado con éxito.\n";
                break;

            case 2:  // Desencolar ticket
                if (cola.isEmpty()) {
                    cout << "La cola está vacía. No hay tickets para desencolar.\n";
                } else {
                    cout << "Ticket desencolado: " << cola.dequeue() << endl;
                }
                break;

            case 3:  // Ver ticket con mayor prioridad
                if (cola.isEmpty()) {
                    cout << "La cola está vacía.\n";
                } else {
                    cout << "Ticket con mayor prioridad: " << cola.front() << endl;
                }
                break;

            case 4:  // Actualizar prioridad de un ticket
                cout << "Ingrese el número del ticket a actualizar: ";
                cin >> value;
                cout << "Ingrese la nueva prioridad: ";
                cin >> priority;
                cola.updatePriority(value, priority);
                cout << "Prioridad actualizada con éxito.\n";
                break;

            case 5:  // Ver todos los tickets
                if (cola.isEmpty()) {
                    cout << "La cola está vacía.\n";
                } else {
                    cout << "Tickets en la cola:\n";
                    cola.printQueue();
                }
                break;

            case 6:  // Salir
                cout << "Saliendo del sistema...\n";
                return 0;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    }

    return 0;
}
