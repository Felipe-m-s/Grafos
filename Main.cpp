#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main() {
    
    Grafo meuGrafo;
    meuGrafo.importar("Dados.txt");
    meuGrafo.exibirTodasAsAdjacencias();

    return 0;
}