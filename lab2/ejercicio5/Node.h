#ifndef NODE_H  // Preprocesador para evitar múltiples inclusiones
#define NODE_H

#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        int priority;
        Node* next;

        // Se  crea nodo para manejar prioridades
        Node(int value, int priority) {
            this->value = value;
            this->priority = priority;
            next = nullptr;
        }

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

#endif // NODE_H