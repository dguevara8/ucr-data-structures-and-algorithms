// Node.h
#ifndef NODE_H  // Preprocesador para evitar múltiples inclusiones
#define NODE_H

class Node {
public:
    int value;    // Almacena el valor del nodo
    Node* next;   // Puntero al siguiente nodo en la lista enlazada

    // Constructor que inicializa el nodo con un valor y establece el puntero next en nullptr
    Node(int value) {
        this->value = value;  // Asignar el valor al nodo actual
        this->next = nullptr; // Inicializar el puntero next como nulo
    }
};

#endif // NODE_H
