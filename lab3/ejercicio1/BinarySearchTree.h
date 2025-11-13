#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream>

using namespace std;

// Clase que representa un nodo en el árbol
class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        // Constructor que inicializa el árbol vacío
        BinarySearchTree() { root = nullptr; }

        // Función recursiva para eliminar todos los nodos del árbol
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        // Destructor que llama a la función destroy
        ~BinarySearchTree() { destroy(root); }

        // Función para insertar un valor en el árbol de búsqueda binario
        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
        
        int findMin(){
            Node* curr = root;  // Comienza en la raíz
            if (curr == NULL) { // Esta vacio
                return 0;

            }
            while (curr->left != NULL) { // Recorre el lado izquierdo hasta llegar al nodo más pequeño
                curr = curr->left;
            }
            return curr->value;
        }

        int findMax(){
            Node* curr = root;  // Comienza en la raíz
            if (curr == NULL) { // Esta vacio
                return 0;
            }
            while (curr->right != NULL) { // Recorre el lado derecho hasta llegar al nodo más grande
                curr = curr->right;
            }
            return curr->value;
        }

};

#endif