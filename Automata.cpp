#include <iostream>
#include <string>

using namespace std;

// Función que procesa la palabra en el autómata
bool automata(string word) {
    // Estado inicial
    string state = "q0";

    // Procesar cada símbolo de la palabra
    for (char symbol : word) {
        if (state == "q0") {
            if (symbol == 'a') {
                state = "q1";
            } else if (symbol == 'b') {
                state = "q2";
            } else {
                return false; // Símbolo no reconocido
            }
        } else if (state == "q1") {
            if (symbol == 'a' || symbol == 'b') {
                state = "q1";
            } else {
                return false;
            }
        } else if (state == "q2") {
            if (symbol == 'b') {
                state = "q2";
            } else if (symbol == 'a') {
                state = "q0";
            } else {
                return false;
            }
        }
    }

    // Verificar si el estado final es de aceptación
    return state == "q1" || state == "q2";
}

int main() {
    // Lista de palabras para probar
    string palabras[] = {"ab", "ba", "aaa", "bba", "abb", "bbb", "aab"};
    int n = sizeof(palabras) / sizeof(palabras[0]);

    for (int i = 0; i < n; i++) {
        if (automata(palabras[i])) {
            cout << "La palabra '" << palabras[i] << "' es aceptada." << endl;
        } else {
            cout << "La palabra '" << palabras[i] << "' no es aceptada." << endl;
        }
    }

    return 0;
}
