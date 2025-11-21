#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main() {
    
    Grafo meuGrafo;
    meuGrafo.importar("Dados.txt");
    meuGrafo.exibirTodasAsAdjacencias();
    cout << meuGrafo.consultarSeAdjacente(0, 3);

    return 0;
}