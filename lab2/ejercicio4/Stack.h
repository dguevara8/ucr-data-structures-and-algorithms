#ifndef STACK_H  // Preprocesador para evitar múltiples inclusiones
#define STACK_H

#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
    private:
        Node* top;     // Puntero al nodo superior (top) de la pila
        int height;    // Altura de la pila, es decir, el número de elementos en ella
        int INT_MIN;   // Definicion de INT_MIN

    public:
        // Constructor por defecto: inicializa una pila vacía
        Stack() {
            top = nullptr;   // No hay nodos, por lo que el top es nullptr
            height = 0;      // La altura de la pila es 0
        }

        // Constructor que inicializa la pila con un solo nodo cuyo valor es el proporcionado
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;    // El nuevo nodo es el nodo superior de la pila
            height = 1;       // Inicialmente, la pila tiene una altura de 1
        }

        // Destructor: libera la memoria de todos los nodos de la pila
        ~Stack() {
            Node* temp = top;
            while (top) {          // Itera mientras haya nodos en la pila
                top = top->next;   // Avanza al siguiente nodo
                delete temp;       // Libera la memoria del nodo actual
                temp = top;
            }
        }

        // Método para imprimir todos los elementos de la pila
        void printStack() {
            Node* temp = top;
            while (temp) {                     // Recorre la pila desde el nodo superior hasta el final
                cout << temp->value << endl;   // Imprime el valor del nodo actual
                temp = temp->next;             // Avanza al siguiente nodo
            }
        }

        // Método para obtener el valor del nodo superior (top) de la pila
        void getTop() {
            if (top == nullptr) {               // Si la pila está vacía
                cout << "Top: nullptr" << endl;
            } else {
                cout << "Top: " << top->value << endl;
            }
        }

        // Método para obtener la altura de la pila
        void getHeight() {
            cout << "Height: " << height << endl;
        }

        // Método para verificar si la pila está vacía
        bool isEmpty() {
            return (height == 0);   // Devuelve true si la altura es 0, false en caso contrario
        }

        // Método para agregar un elemento en la parte superior de la pila
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;  // El nuevo nodo apunta al nodo que estaba en el tope
            top = newNode;        // El nuevo nodo se convierte en el nodo superior
            height++;             // Incrementa la altura de la pila
        }

        // Método para obtener el valor del nodo superior sin eliminarlo
        int topValue() { 
            if (top) return top->value;  // Si la pila no está vacía, devuelve el valor del nodo superior
            return INT_MIN;              // Si está vacía, devuelve un valor mínimo indicativo
        }

        // Método para eliminar y devolver el valor del nodo superior de la pila
        int pop() {
            if (height == 0) return INT_MIN;  // Si la pila está vacía, devuelve un valor mínimo indicativo

            Node* temp = top;             // Almacena el nodo superior para eliminarlo
            int poppedValue = top->value; // Almacena el valor del nodo superior
            top = top->next;              // Actualiza el puntero top al siguiente nodo
            delete temp;                  // Libera la memoria del nodo eliminado
            height--;                     // Decrementa la altura de la pila

            return poppedValue;           // Devuelve el valor del nodo eliminado
        }

        string reverseString(const string str){
            // Se crea una pila
            Stack charStack; 

             // Se recorre cada caracter de la cadena original
            for (char ch : str) { 
                // Se empuja cada caracter en la pila
                charStack.push(ch); 
            } 
        
             // Cadena vacía donde se almacena la cadena invertida
            string reversedString; 
        
             // Mientras la pila no esté vacía continua
            while (!charStack.isEmpty()) { 
                 // Se anade el caracter superior de la pila al final de la cadena invertida
                reversedString += charStack.topValue(); 
                // Se elimina el caracter superior 
                charStack.pop();
            } 
        
            return reversedString;

        }
};


#endif // STACK_H