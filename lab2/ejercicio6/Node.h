#ifndef NODE_H  // Preprocesador para evitar múltiples inclusiones
#define NODE_H

#include <iostream>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

#endif // NODE_H