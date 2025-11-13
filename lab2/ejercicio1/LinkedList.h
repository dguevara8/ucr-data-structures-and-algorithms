#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"  // Incluir la definición de la clase Node

using namespace std;


class LinkedList {
    private:
        Node* head;   // Puntero al primer nodo de la lista
        Node* tail;   // Puntero al último nodo de la lista
        int length;   // Longitud de la lista enlazada

    public:
        // Constructor que inicializa la lista con un valor inicial
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        // Constructor por defecto {

        LinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        // Destructor que elimina todos los nodos de la lista para liberar memoria
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        // Función para imprimir los valores de los nodos de la lista
        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        // Función para mostrar el valor del primer nodo (head)
        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        // Función para mostrar el valor del último nodo (tail)
        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        // Función para mostrar la longitud actual de la lista
        void getLength() {
            cout << "Longitud: " << length << endl;
        }

        // Función para agregar un nodo al final de la lista
        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        // Función para eliminar el último nodo de la lista
        void deleteLast() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while (temp->next) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        // Función para agregar un nodo al principio de la lista
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        // Función para eliminar el primer nodo de la lista
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

        // Función para obtener un puntero al nodo en un índice específico
        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;
            Node* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            return temp;
        }

        // Función para establecer un nuevo valor en un nodo en un índice específico
        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            } 
            return false;
        }

        // Función para insertar un nodo en un índice específico
        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }       

        // Función para eliminar un nodo en un índice específico
        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();

            Node* prev = get(index - 1);  // Obtener el nodo anterior al que se quiere eliminar
            Node* temp = prev->next;      // Nodo a eliminar

            prev->next = temp->next;      // Saltar el nodo a eliminar
            delete temp;                  // Eliminar el nodo
            length--;        
        }

        void reverse(){
            // Punteros
            Node* current = head;
            Node* prev = nullptr;
            Node* next = nullptr;

            while (current != nullptr) {
                next = current->next;  // Guarda el siguiente nodo antes de modificar la referencia
                current->next = prev; // Invierte el puntero

                prev = current; // Mueve prev al nodo actual
                current = next; // Avanza current al siguiente nodo
            }
            tail = head; // Quien fue head ahora es el tail
            head = prev; // El último nodo recorrido (prev) se convierte en el nuevo head
        }

};

#endif // LINKEDLIST_H