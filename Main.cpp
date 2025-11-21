#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main() {
    
    Grafo meuGrafo;
    meuGrafo.criarVazio(3, false);
    meuGrafo.exibirTodasAsAdjacencias();
    meuGrafo.inserAresta(0, 1, 1);
    meuGrafo.inserAresta(1, 50, 10);
    meuGrafo.inserAresta(2, 10, 30);
    meuGrafo.exibirTodasAsAdjacencias();

    return 0;
}