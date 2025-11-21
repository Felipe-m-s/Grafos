#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Grafo
{

private:
    int numDeVertices;
    int numDeArestas;
    int **matrizDeAdjacencias;
    int *coordenadasX;
    int *coordenadasY;
    bool direcionado;

    void liberarMatrizDeAdjacencias(); // Libera a memória alocada para a matriz de adjacências
    bool isVerticeValido(int u); // Verifica se o vértice é válido

public:
        Grafo(); // Construtor vazio
        ~Grafo(); // Destrutor

    void importar(); // Importa o grafo de um arquivo

    void criarVazio(int numDeVertices_param, bool Direcionado); // Cria um grafo vazio

    void exibirTodasAsAdjacencias(); // Exibe todas as adjacências

    bool consultarSeAdjacente(int u, int v); // Consulta se dois vértices são adjacentes

    void inserAresta(int u, int v, int p); // Insere uma aresta com peso p entre os vértices u e v

    void removerAresta(int u, int v); // Remove a aresta entre os vértices u e v

    void editarCoordenadaDoVertice(int u, int x, int y); // Edita as coordenadas do vértice u

    int primeiroAdjacenteDoVertice(int u); // Retorna o primeiro adjacente do vértice u

    int proximoAdjacenteDoVertice(int u, int atual); // Retorna o próximo adjacente do vértice u após o vértice atual

    void listaCompletaDeAdjacentesDoVertice(int u); // Exibe a lista completa de adjacentes do vértice u

    void exportar(); // Exporta o grafo para um arquivo

    void mostrarGraficamente(); // Mostra o grafo graficamente
};

#endif // GRAFO_HPP