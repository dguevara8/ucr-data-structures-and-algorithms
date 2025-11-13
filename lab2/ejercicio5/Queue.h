#ifndef QUEUE_H  // Preprocesador para evitar múltiples inclusiones
#define QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
    private:
        Node* first;  // Puntero al primer nodo de la cola
        Node* last;   // Puntero al último nodo de la cola
        int length;   // Longitud de la cola (número de elementos)
        int INT_MIN;

    public:
        // Constructor por defecto: inicializa una cola vacía
        Queue() {
            first = nullptr;
            last = nullptr;
            length = 0;
        }

        // Constructor que inicializa la cola con un único nodo
        Queue(int value) {
            Node* newNode = new Node(value);  // Crear un nuevo nodo con el valor dado
            first = newNode;
            last = newNode;
            length = 1;
        }

        // Método para imprimir todos los elementos de la cola
        void printQueue() {
            Node* temp = first;
            while (temp) {  // Recorre la cola desde el primer hasta el último nodo
                cout << "Value: " << temp->value << ", Priority: " << temp->priority << endl; // Imprime el valor y prioridad del nodo actual
                temp = temp->next;  // Avanza al siguiente nodo
            }
        }

        // Método para obtener el primer elemento de la cola
        void getFirst() {
            if (first == nullptr) {  // Si la cola está vacía, imprime nullptr
                cout << "First: nullptr" << endl;
            } else {
                cout << "First: " << first->value << endl;
            }
        }

        // Método para obtener el último elemento de la cola
        void getLast() {
            if (last == nullptr) {  // Si la cola está vacía, imprime nullptr
                cout << "Last: nullptr" << endl;
            } else { 
                cout << "Last: " << last->value << endl;
            }  
        }

        // Método para obtener la longitud de la cola
        void getLength() {
            cout << "Length: " << length << endl;
        }

        // Método para verificar si la cola está vacía
        bool isEmpty() {
            return (length == 0);  // Devuelve true si la longitud es 0, false en caso contrario
        }

        int front(){
            if (isEmpty()) return (length == 0); // Si esta vacio devuelve 0
            return first->value; // Sino devuelve el primer valor
        }

        // Método para obtener el valor del primer elemento de la cola sin eliminarlo
        int firstValue() { 
            if (first) return first->value;  // Si la cola no está vacía, devuelve el valor del primer nodo
            return INT_MIN;  // Si está vacía, devuelve un valor indicativo (mínimo entero)
        }

        // Método para agregar un nuevo elemento al final de la cola
        void enqueue(int value, int priority){
            // Crea un nuevo nodo con el valor y prioridad proporcionados
             Node* newNode = new Node(value, priority);

            // Si la cola está vacía el nuevo nodo es el primero y el último
            if (first == nullptr) {
                first = newNode;
                last = newNode;
            } 
            // Si el nuevo nodo tiene menor prioridad se inserta al inicio
            else if (priority < first->priority) {
                newNode->next = first;
                first = newNode;
            } 
            else {
                Node* temp = first;
                // Busca la posición correcta donde insertar según prioridad
                while (temp->next != nullptr && temp->next->priority <= priority) {
                    temp = temp->next;
                }
                // Inserta el nuevo nodo en su posición
                newNode->next = temp->next;
                temp->next = newNode;

                // Si el nuevo nodo es el último actualiza el ultimo
                if (newNode->next == nullptr) {
                    last = newNode;
                }
            }
            length++;
        }

        // Método para eliminar y devolver el primer elemento de la cola
        int dequeue() {
            if (isEmpty()) return -1; // Si la cola está vacía

            // Extrae el primer dato de la lista
            int value = first->value;
            Node* temp = first;
            first = first->next; // El primer nodo se actualiza para que apunte al siguiente
            delete temp; 
            length--;
            return value;
        }

        void updatePriority(int value , int newPriority){
            // Si la cola está vacía no hay nada que actualizar
            if (first == nullptr) return;

            // Busca el nodo con el valor especificado y lo elimina
            Node* temp = first;
            Node* prev = nullptr;

            while (temp != nullptr && temp->value != value) {
                prev = temp;
                temp = temp->next;
            }

            // Si no se encontró el nodo con el valor se sale
            if (temp == nullptr) return;

            // Desconecta el nodo encontrado
            if (prev == nullptr) {  // Si es el primer nodo
                first = temp->next;
            } else {
                prev->next = temp->next;
            }

            // Si era el último nodo actualiza el ultimo
            if (temp == last) {
                last = prev;
            }

            delete temp;
            length--;

            // Se inserta el nodo con la nueva prioridad
            enqueue(value, newPriority);
        }


};

#endif // QUEUE_H
