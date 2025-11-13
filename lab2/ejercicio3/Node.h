// Node.h
#ifndef NODEDLL_H  // Preprocesador para evitar múltiples inclusiones
#define NODEDLL_H

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

#endif // NODEDLL_H
