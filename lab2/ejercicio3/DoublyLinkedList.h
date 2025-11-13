#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"  // Incluir la definición de la clase Node

using namespace std;

// Definición de la clase DoublyLinkedList (Lista doblemente enlazada)
class DoublyLinkedList {
    private:
        Node* head;  // Puntero al primer nodo (cabeza) de la lista
        Node* tail;  // Puntero al último nodo (cola) de la lista
        int length;  // Almacena la longitud actual de la lista

    public:
        // Constructor: crea una lista con un solo nodo que contiene el valor dado
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        // Constructor por defecto

            DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        // Destructor: libera la memoria de todos los nodos de la lista
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {  // Itera mientras haya nodos en la lista
                head = head->next;
                delete temp;  // Libera la memoria del nodo actual
                temp = head;
            }
        }

        // Método para imprimir los valores de los nodos en la lista
        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;  // Imprime el valor del nodo actual
                temp = temp->next;  // Avanza al siguiente nodo
            }
        }

        // Método para mostrar el valor de la cabeza (head) de la lista
        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        // Método para mostrar el valor de la cola (tail) de la lista
        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        // Método para mostrar la longitud actual de la lista
        void getLength() {
            cout << "Length: " << length << endl;
        }

        // Método para agregar un nuevo nodo al final de la lista
        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {  // Si la lista está vacía, el nuevo nodo será head y tail
                head = newNode;
                tail = newNode;
            } else {  // Si no está vacía, se agrega el nuevo nodo al final
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;  // Actualiza el puntero tail
            }
            length++;  // Incrementa la longitud de la lista
        }

        // Método para eliminar el último nodo de la lista
        void deleteLast() {
            if (length == 0) return;  // Si la lista está vacía, no se hace nada
            Node* temp = tail;
            if (length == 1) {  // Si la lista tiene un solo nodo, head y tail se vuelven nullptr
                head = nullptr;
                tail = nullptr;
            } else {  // Si hay más de un nodo, se actualiza tail
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;  // Libera la memoria del nodo eliminado
            length--;  // Decrementa la longitud de la lista
        }

        // Método para agregar un nuevo nodo al principio de la lista
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {  // Si la lista está vacía, el nuevo nodo será head y tail
                head = newNode;
                tail = newNode;
            } else {  // Si no está vacía, se agrega el nuevo nodo al principio
                newNode->next = head;
                head->prev = newNode;
                head = newNode;  // Actualiza el puntero head
            }
            length++;  // Incrementa la longitud de la lista
        }

        // Método para eliminar el primer nodo de la lista
        void deleteFirst() {
            if (length == 0) return;  // Si la lista está vacía, no se hace nada
            Node* temp = head;
            if (length == 1) {  // Si la lista tiene un solo nodo, head y tail se vuelven nullptr
                head = nullptr;
                tail = nullptr;
            } else {  // Si hay más de un nodo, se actualiza head
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;  // Libera la memoria del nodo eliminado
            length--;  // Decrementa la longitud de la lista
        }

        // Método para obtener el nodo en una posición específica
        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;  // Índice fuera de rango
            Node* temp = head;
            if (index < length / 2) {  // Si el índice está en la primera mitad, recorre desde head
                for (int i = 0; i < index; ++i) {
                    temp = temp->next;
                }
            } else {  // Si el índice está en la segunda mitad, recorre desde tail
                temp = tail;
                for (int i = length - 1; i > index; --i) {
                    temp = temp->prev;
                }
            }
            return temp;
        }

        // Método para establecer un nuevo valor en un nodo de una posición específica
        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        // Método para insertar un nuevo nodo en una posición específica
        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;  // Índice fuera de rango
            if (index == 0) {  // Si el índice es 0, se agrega al principio
                prepend(value);
                return true;
            } 
            if (index == length) {  // Si el índice es igual a la longitud, se agrega al final
                append(value);
                return true;
            } 
    
            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;
            newNode->prev = before;
            newNode->next = after;
            before->next = newNode;
            after->prev = newNode;
            length++;  // Incrementa la longitud de la lista
            return true;
        }       

        // Método para eliminar un nodo en una posición específica
        void deleteNode(int index) {
            if (index < 0 || index >= length) return;  // Índice fuera de rango
            if (index == 0) return deleteFirst();  // Si el índice es 0, elimina el primer nodo
            if (index == length - 1) return deleteLast();  // Si es el último, elimina el último nodo
            
            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;  // Libera la memoria del nodo eliminado
            length--;  // Decrementa la longitud de la lista
        }

        bool isPalindrome(){
            // Punteros
            Node* start = head;
            Node* end = tail;
            
            // Si solamente hay un numero se cumple
            if (head == nullptr)
                return true;

            // Se comparan los valores desde los extremos hacia el centro
            while (start != end && end != start->prev)
            {
                // Si no son iguales no es palindromo
                if (start->value != end->value)
                    return false;

                // Se avanza al centro
                start = start->next;
                end = end->prev;
            }
            // Si se cumplio si es palindromo
            return true;
        }

};

#endif
