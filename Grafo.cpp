#include "Grafo.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// todo Implementação dos métodos da classe Grafo
//* Metodos auxiliares
void Grafo::liberarMatrizDeAdjacencias()
{
    if (matrizDeAdjacencias != nullptr)
    {
        for (int i = 0; i < numDeVertices; ++i)
        {
            delete[] matrizDeAdjacencias[i];
        }
        delete[] matrizDeAdjacencias;
        matrizDeAdjacencias = nullptr;
    }

    delete[] coordenadasX;
    coordenadasX = nullptr;

    delete[] coordenadasY;
    coordenadasY = nullptr;
}

bool Grafo::isVerticeValido(int u)
{
    return (u >= 0 && u < numDeVertices);
}

//* Construtor e Destrutor
Grafo::Grafo() : numDeVertices(0), numDeArestas(0), direcionado(false) {} // Construtor vazio
Grafo::~Grafo()
{
    liberarMatrizDeAdjacencias();
} // Destrutor

void Grafo::importar()
{
    ifstream arq("grafo.txt");
    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    arq >> direcionado;
    arq >> numDeVertices;
}

void Grafo::criarVazio(int numDeVertices_param, bool Direcionado)
{
    if (numDeVertices_param <= 0)
    {
        cout << "Numero de vertices invalido!" << endl;
        return;
    }

    liberarMatrizDeAdjacencias();

    this->numDeVertices = numDeVertices_param;
    this->direcionado = Direcionado;
    this->matrizDeAdjacencias = new int *[numDeVertices];
    for (int i = 0; i < numDeVertices; ++i)
    {
        // Aloca cada linha e inicializa com zeros
        this->matrizDeAdjacencias[i] = new int[numDeVertices]{0};
    }
    this->coordenadasX = new int[numDeVertices]{0};
    this->coordenadasY = new int[numDeVertices]{0};
}
void Grafo::exibirTodasAsAdjacencias()
{
    if (numDeVertices == 0 || matrizDeAdjacencias == nullptr)
    {
        cout << "Grafo vazio ou nao inicializado!" << endl;
        return;
    }
    for (int i = 0; i < numDeVertices; i++)
    {
        cout << "Vertice " << i << ": ";
        for (int j = 0; j < numDeVertices; j++)
        {
            cout << matrizDeAdjacencias[i][j] << " ";
        }
        cout << endl;
    }
}

bool Grafo::consultarSeAdjacente(int u, int v)
{
}

void Grafo::inserAresta(int u, int v, int p)
{
    if (u < 0 || u >= numDeVertices || v < 0 || v >= numDeVertices || p <= 0)
    {
        cout << "Parametros invalidos para inserir aresta!" << endl;
        return;
    }

    if (matrizDeAdjacencias[u][v] == 0)
    {
        numDeArestas++;
    }

    matrizDeAdjacencias[u][v] = p;

    if (!direcionado)
    {
        matrizDeAdjacencias[v][u] = p;
    }

    cout << "Aresta inserida entre " << u << " e " << v << " com peso " << p << "." << endl;
}

void Grafo::removerAresta(int u, int v)
{
}

void Grafo::editarCoordenadaDoVertice(int u, int x, int y)
{
}

int Grafo::primeiroAdjacenteDoVertice(int u)
{
}

int Grafo::proximoAdjacenteDoVertice(int u, int atual)
{
}

void Grafo::listaCompletaDeAdjacentesDoVertice(int u)
{
}

void Grafo::exportar()
{
}

void Grafo::mostrarGraficamente()
{
}