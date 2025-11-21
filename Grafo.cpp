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
Grafo::Grafo() : numDeVertices(0), numDeArestas(0), direcionado(false), matrizDeAdjacencias(nullptr), coordenadasX(nullptr), coordenadasY(nullptr) {} // Construtor vazio
Grafo::~Grafo()
{
    liberarMatrizDeAdjacencias();
} // Destrutor

void Grafo::importar(string nomeArquivo_param)
{
    // Abre o arquivo para leitura
    ifstream arq(nomeArquivo_param);
    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string tipoDeGrafo;

    // Lê o tipo de grafo (direcionado ou nao direcionado)
    if (!(arq >> tipoDeGrafo))
    {
        cout << "Erro ao ler o tipo de grafo!" << endl;
        arq.close();
        return;
    }

    // Converte a string lida para booleano
    direcionado = (tipoDeGrafo == "direcionado=sim" || tipoDeGrafo == "direcionado=SIM");

    // Lê o número de vértices
    if (!(arq >> numDeVertices))
    {
        cout << "Erro ao ler o numero de vertices!" << endl;
        arq.close();
        return;
    }

    // Cria o grafo vazio com o número de vértices lido
    criarVazio(numDeVertices, direcionado);
    cout << "Grafo criado com " << numDeVertices << " vertices." << endl;

    // Lê as coordenadas dos vértices
    cout << "Lendo coordenadas dos vertices..." << endl;
    for (int i = 0; i < numDeVertices; ++i)
    {
        int u, x, y;
        if (!(arq >> u >> x >> y))
        {
            cout << "Erro ao ler as coordenadas do vertice " << i << "!" << endl;
            arq.close();
            return;
        }
        editarCoordenadaDoVertice(u, x, y);
    }
    cout << "Coordenadas dos vertices lidas com sucesso." << endl;

    // Lê as arestas
    cout << "Lendo arestas..." << endl;
    int arestasEsperadas, u, v, p;
    if (!(arq >> arestasEsperadas))
    {
        cout << "Erro ao ler o numero de arestas!" << endl;
        arq.close();
        return;
    }

    while (arq >> u >> v >> p)
    {
        inserAresta(u, v, p);
    }

    cout << "Importacao concluida com sucesso." << endl;
    arq.close();
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
    if (!isVerticeValido(u) || !isVerticeValido(v))
    {
        cout << "Vertices invalidos!" << endl;
        return false;
    }
    return matrizDeAdjacencias[u][v] != 0;
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
    if (!isVerticeValido(u) || !isVerticeValido(v))
    {
        cout << "Vertices invalidos!" << endl;
        return;
    }

    if (matrizDeAdjacencias[u][v] == 0)
    {
        cout << "Aresta inexistente entre " << u << " e " << v << "." << endl;
        return;
    }

    matrizDeAdjacencias[u][v] = 0;

    if (!direcionado)
    {
        matrizDeAdjacencias[v][u] = 0;
    }

    numDeArestas--;
    cout << "Aresta removida entre " << u << " e " << v << "." << endl;
}

void Grafo::editarCoordenadaDoVertice(int u, int x, int y)
{
    if (!isVerticeValido(u))
    {
        cout << "Vertice invalido!" << endl;
        return;
    }
    coordenadasX[u] = x;
    coordenadasY[u] = y;
}

int Grafo::primeiroAdjacenteDoVertice(int u)
{
    if (!isVerticeValido(u))
    {
        cout << "Vertice invalido!" << endl;
        return -1;
    }
    for (int v = 0; v < numDeVertices; v++)
    {
        if (matrizDeAdjacencias[u][v] != 0)
        {
            return v;
        }
    }
    return -1; // Nenhum adjacente encontrado
}

int Grafo::proximoAdjacenteDoVertice(int u, int atual)
{
    if (!isVerticeValido(u) || !isVerticeValido(atual))
    {
        cout << "Vertices invalidos!" << endl;
        return -1;
    }
    for (int v = atual + 1; v < numDeVertices; v++)
    {
        if (matrizDeAdjacencias[u][v] != 0)
        {
            return v;
        }
    }
    return -1; // Nenhum adjacente encontrado
}

void Grafo::listaCompletaDeAdjacentesDoVertice(int u)
{
    if (!isVerticeValido(u))
    {
        cout << "Vertice invalido!" << endl;
        return;
    }

    cout << "Adjacentes do vertice " << u << ": ";
    int v = primeiroAdjacenteDoVertice(u);
    while (v != -1)
    {
        int peso = matrizDeAdjacencias[u][v];
        cout << "(" << u << ", " << v << ")" << " com peso " << peso << "; ";

        v = proximoAdjacenteDoVertice(u, v);
    }
}

void Grafo::exportar()
{
}

void Grafo::mostrarGraficamente()
{
}