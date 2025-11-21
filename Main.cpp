#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main()
{

    Grafo meuGrafo;
    meuGrafo.importar("Dados.txt");
    meuGrafo.exibirTodasAsAdjacencias();
    cout << meuGrafo.consultarSeAdjacente(0, 3) << endl;
    int u = 1;
    int v = meuGrafo.primeiroAdjacenteDoVertice(u);

    while (v != -1)
    {
        cout << "Adjacente de " << u << ": " << v << endl;

        // Move para o próximo vizinho, usando o vizinho atual (v) como ponto de partida
        v = meuGrafo.proximoAdjacenteDoVertice(u, v);
    }

    return 0;
}