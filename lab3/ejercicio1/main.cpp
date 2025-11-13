#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree bst;
    int n, value;

    cout << "Ingrese la cantidad de valores a insertar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese un valor: ";
        cin >> value;
        bst.insert(value);
    }

    /* Esta parte no debe ser modificada*/

    cout << "Valor mínimo en el árbol: " << bst.findMin() << endl;
    cout << "Valor máximo en el árbol: " << bst.findMax() << endl;

    /* Esta parte no debe ser modificada*/

    return 0;
}
