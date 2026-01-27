#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    string *nomeVertices;

    void liberarMatrizDeAdjacencias(); // Libera a memória alocada para a matriz de adjacências
    bool isVerticeValido(int u); // Verifica se o vértice é válido

public:
        Grafo(); // Construtor vazio
        ~Grafo(); // Destrutor

    void importar(string nomeArquivo_param); // Importa o grafo de um arquivo

    void criarVazio(int numDeVertices_param, bool Direcionado); // Cria um grafo vazio

    void exibirTodasAsAdjacencias(); // Exibe todas as adjacências

    bool consultarSeAdjacente(int u, int v); // Consulta se dois vértices são adjacentes

    void inserAresta(int u, int v, int p); // Insere uma aresta com peso p entre os vértices u e v

    void removerAresta(int u, int v); // Remove a aresta entre os vértices u e v

    void editarCoordenadaDoVertice(int u, int x, int y); // Edita as coordenadas do vértice u

    void editarNomeDoVertice(int u, string nome); // Edita o nome do vértice u

    int primeiroAdjacenteDoVertice(int u); // Retorna o primeiro adjacente do vértice u

    int proximoAdjacenteDoVertice(int u, int atual); // Retorna o próximo adjacente do vértice u após o vértice atual

    void listaCompletaDeAdjacentesDoVertice(int u); // Exibe a lista completa de adjacentes do vértice u

    void buscaProfundidade(); // Realiza busca em profundidade a partir do vértice inicio

    void visitaProfundidade(int u, vector<char> &cor, vector<int> &descoberta, vector<int> &termino, vector<int> &antecessor, int &tempo); // Função auxiliar para busca em profundidade

    void buscaLargura(); // Realiza busca em largura a partir do vértice inicio

    void visitaLargura(int u, vector<char> &cor, vector<int> &distancia, vector<int> &antecessor); // Função auxiliar para busca em largura

    void Prim(); // Implementa o algoritmo de Prim para encontrar a árvore geradora mínima

    int buscarVerticePorNome(string& nome); // Busca um vértice pelo seu nome e retorna seu índice

    void imprimirCaminhoComNomes(vector<int>& antecessor, int origem, int destino); // Imprime o caminho mínimo usando nomes dos vértices
    
    void Dijkstra(int origem, int destino); // Implementa o algoritmo de Dijkstra para encontrar o caminho mínimo a partir do vértice origem

    void DijkstraPorNome(string nomeOrigem, string nomeDestino); // Implementa o algoritmo de Dijkstra para encontrar o caminho mínimo a partir do vértice de nome origem

    void exportar(); // Exporta o grafo para um arquivo

    void exportarArquivoJson(); // Método para exportar o grafo em formato JSON
};

#endif // GRAFO_HPP