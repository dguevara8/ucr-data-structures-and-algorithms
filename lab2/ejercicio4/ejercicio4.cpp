#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack pila;
    string input;

    getline(cin, input);  // Lee toda la línea

    
    cout << "String Original: ";
    // TODO: Imprimir la cadena original
    string reversed = pila.reverseString(input);
    cout << "String invertido: " << reversed << endl;

    return 0;
}
