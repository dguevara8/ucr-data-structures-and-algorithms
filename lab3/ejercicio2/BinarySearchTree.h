#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream>
#include <queue>

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
            if (currentNode) {
                destroy(currentNode->left);
                destroy(currentNode->right);
                delete currentNode;
            }
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

        // Función que indica si un valor se encuentra en el árbol de búsqueda binario
        bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;
            while(temp) {
                if (value < temp->value) {
                    temp = temp->left;
                } else if (value > temp->value) {
                    temp = temp->right;
                } else {
                    return true; 
                }
            }
            return false;
        }

        // Función que realiza un recorrido de izq a der en el arbol
        void BFS() {
            Node* currentNode = root;
            queue<Node*> myQueue;
            myQueue.push(currentNode);

            while (myQueue.size() > 0) {
                currentNode = myQueue.front();
                myQueue.pop();
                cout << currentNode->value << " ";
                if (currentNode->left) {
                    myQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    myQueue.push(currentNode->right);
                }
            }
        }

        // Función que realiza un recorrido izq raiz der
        void inOrder(Node* currentNode) {
            if (currentNode->left != nullptr) {
                inOrder(currentNode->left);
            }
            cout << currentNode->value << " ";
            if (currentNode->right != nullptr) {
                inOrder(currentNode->right);
            }
        }

        // Función para realizar un recorrido en orden desde la raíz
        void inOrder() { inOrder(root); }

         // Función para eliminar un nodo con un valor específico en el árbol
        void deleteNode(int value) {
            root = deleteNode(root, value); // Llama a la funcion recursiva
        }

        // Busca el nodo más pequeño en el subárbol derecho
        Node* getSuccessor(Node* curr){
            curr = curr->right; // Comienza en el subárbol derecho
            while (curr != nullptr && curr->left != nullptr) // Busca el nodo más a la izquierda
                curr = curr->left;
            return curr;
        }

        // Función recursiva para eliminar un nodo con un valor específico
        Node* deleteNode(Node* root, int value){
            if (root == nullptr) // No hay nada que eliminar
                return root;

            if (root->value > value) // Si el valor es menor se va al subárbol izquierdo
                root->left = deleteNode(root->left, value);
            else if (root->value < value) // Si el valor es mayor se va al subárbol derecho
                root->right = deleteNode(root->right, value);
            else {  // Si se encuentra el valor ...
                if (root->left == nullptr) { // Si no tiene "hijo" izquierdo lo reemplaza por el "hijo" derecho
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }

                if (root->right == nullptr) { // Si no tiene "hijo" derecho lo reemplaza por el "hijo" izquierdo
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // Si tiene ambos "hijos" lo reemplaza por el sucesor inorden
                Node* succ = getSuccessor(root);
                root->value = succ->value;
                root->right = deleteNode(root->right, succ->value);
            }
            return root;
        }
            

};

#endif