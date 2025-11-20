#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main() {
    
    Grafo meuGrafo;
    meuGrafo.criarVazio(5, false);
    meuGrafo.exibirTodasAsAdjacencias();
    meuGrafo.inserAresta(0, 1, 10);
    meuGrafo.exibirTodasAsAdjacencias();

    return 0;
}