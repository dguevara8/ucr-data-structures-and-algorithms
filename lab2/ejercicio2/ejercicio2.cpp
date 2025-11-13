#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;
    string input;

    while (true) {
        getline(cin, input);  // Lee toda la línea
        if (input.empty()) break;  // Sale del bucle si el usuario presiona enter 

        int numero = stoi(input);  // Convierte de string a int
        list.append(numero); // Llama a la funcion append
    }
    
    // Esta parte del codigo no debe ser modificada
    cout << "Lista original: ";
    list.printList();

    // Llamar al método reverse
    list.removeDuplicates();

    cout << "Lista sin duplicados: ";
    list.printList();

    return 0;
}
