#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    DoublyLinkedList list;
    string input;

    while (true) {
        getline(cin, input);  // Lee toda la línea
        if (input.empty()) break;  // Sale del bucle si el usuario presiona enter 

        int numero = stoi(input);  // Convierte de string a int
        list.append(numero); // Llama a la funcion append
    }

    
    // Esta parte del codigo no debe ser modificada
    cout << "Lista Original: ";
    list.printList();
    cout << "¿Es palíndromo?: " << (list.isPalindrome() ? "Sí" : "No") << endl;

    return 0;
}
