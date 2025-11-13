#ifndef NODE_H  // Preprocesador para evitar múltiples inclusiones
#define NODE_H

#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

#endif // NODE_H