#ifndef HASTABLEH  // Preprocesador para evitar múltiples inclusiones
#define HASHTABLE_H

#include <iostream>
#include "Node.h"

using namespace std;

class HashTable {
    private:
        static const int SIZE = 7;  // Tamaño fijo de la tabla hash
        Node* dataMap[SIZE];  // Arreglo de punteros a nodos, que representa la tabla hash

        // Función hash: calcula un índice a partir de la clave proporcionada
        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);  // Obtiene el valor ASCII del carácter
                hash = (hash + asciiValue * 23) % SIZE;  // Calcula el hash usando una constante multiplicadora y el módulo del tamaño de la tabla
            }
            return hash;  // Devuelve el índice calculado
        }

    public:
        // ---------------------------------------------------
        //  Destructor: libera la memoria de todos los nodos
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];  // Apunta al primer nodo de la lista en esa posición
                Node* temp = head;
                while (head) {  // Recorre la lista y libera la memoria de cada nodo
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        // Método para imprimir el contenido de la tabla hash
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {  // Si hay elementos en esa posición de la tabla
                    Node* temp = dataMap[i];
                    while (temp) {  // Recorre la lista y muestra los pares clave-valor
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
        // Método para agregar un nuevo par clave-valor a la tabla hash
        void set(string key, int value) {
            int index = hash(key);  // Calcula el índice usando la función hash
            Node* newNode = new Node(key, value);  // Crea un nuevo nodo con la clave y el valor
            if (dataMap[index] == nullptr) {  // Si no hay elementos en esa posición, agrega el nodo directamente
                dataMap[index] = newNode;
            } else {  // Si ya hay una lista en esa posición, se agrega el nuevo nodo al final de la lista
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {  // Recorre la lista hasta el último nodo
                    temp = temp->next;
                }
                temp->next = newNode;  // Agrega el nuevo nodo al final de la lista
            }
        }
    
        // Método para obtener el valor asociado a una clave
        int get(string key) {
            int index = hash(key);  // Calcula el índice usando la función hash
            Node* temp = dataMap[index];
            while (temp != nullptr) {  // Recorre la lista en esa posición
                if (temp->key == key) return temp->value;  // Si encuentra la clave, devuelve el valor
                temp = temp->next;
            }
            return 0;  // Si no encuentra la clave, devuelve 0 (valor indicativo)
        }

        // Método para obtener todas las claves almacenadas en la tabla hash
        vector<string> keys(){
            vector<string> claves; // Vector que almacenar las claves del hash table
            for (int i = 0; i < SIZE; i++) { // Recorre las posiciones de dataMap
                Node* temp = dataMap[i]; // Apunta al primer nodo de la lista
                while (temp != nullptr) { // Recorre la lista enlazada
                    claves.push_back(temp->key); // Va anadiendo las clave al vector
                    temp = temp->next; // Avanza al siguiente nodo
                }
            }
            return claves; // Devuelve todas las llaves almacenadas en el hashtable
        }

};

#endif // HASTABLE_H
