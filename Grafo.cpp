#include <iostream>
#include <fstream>

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

public:
    void importar()
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

public:
    Grafo() : numDeVertices(0), numDeArestas(0), direcionado(false) {} // Construtor vazio

    void criarVaio(int NumVertices, bool Direcionado)
    {
        this->numDeVertices = NumVertices;
        this->direcionado = Direcionado;
        this->matrizDeAdjacencias[numDeVertices][numDeVertices] = {0};
        this->coordenadasX[numDeVertices] = {0};
        this->coordenadasY[numDeVertices] = {0};
    }
    void exibirTodasAsAdjacencias()
    {
    }

    bool consultarSeAdjacente(int u, int v)
    {
    }

    void inserAresta(int u, int v, int p)
    {
    }

    void removerAresta(int u, int v)
    {
    }

    void editarCoordenadaDoVertice(int u, int x, int y)
    {
    }

    int primeiroAdjacenteDoVertice(int u)
    {
    }

    int proximoAdjacenteDoVertice(int u, int atual)
    {
    }

    void listaCompletaDeAdjacentesDoVertice(int u)
    {
    }

    void exportar()
    {
    }

    void mostrarGraficamente()
    {
    }
};