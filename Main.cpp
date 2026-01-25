#include <iostream>
#include <cstdlib> // Para usar system()
#include "Grafo.hpp"

using namespace std;

void imprimirMensagemDeBoasVindas()
{
    cout << "======================================" << endl;
    cout << "      Bem-vindo ao Gerenciador de     " << endl;
    cout << "                 Grafos               " << endl;
    cout << "======================================" << endl;
}

void imprimirMenu()
{
    cout << "\nMenu de Opcoes:" << endl;
    cout << "1. Importar grafo de arquivo" << endl;
    cout << "2. Criar Grafo vazio" << endl;
    cout << "3. Exibir todas as adjacencias" << endl;
    cout << "4. Consultar se dois vertices sao adjacentes" << endl;
    cout << "5. Inserir aresta" << endl;
    cout << "6. Inserir arestas em conjunto" << endl;
    cout << "7. Remover aresta" << endl;
    cout << "8. Editar coordenada do vertice" << endl;
    cout << "9. Editar nome do vertice" << endl;
    cout << "10. Consultar o primeiro adjacente" << endl;
    cout << "11. Consultar o proximo adjacente" << endl;
    cout << "12. Consultar lista de adjacentes" << endl;
    cout << "13. Realizar busca em profundidade" << endl;
    cout << "14. Realizar busca em largura" << endl;
    cout << "15. Executar Algoritmo de Prim" << endl;
    cout << "16. Exportar grafo para arquivo" << endl;
    cout << "17. Visualizar grafo graficamente" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main()
{
    imprimirMensagemDeBoasVindas();
    int opcao;
    Grafo meuGrafo;

    do
    {
        imprimirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            string nomeArquivo;
            cout << "Digite o nome do arquivo para importar o grafo: ";
            cin >> nomeArquivo;
            meuGrafo.importar(nomeArquivo);
            break;
        }
        case 2:
        {
            cout << "Criando grafo vazio..." << endl;
            cout << "Digite o numero de vertices: ";
            int numVertices;
            cin >> numVertices;
            cout << "O grafo sera direcionado? (1 para sim, 0 para nao): ";
            bool direcionado;
            cin >> direcionado;
            meuGrafo.criarVazio(numVertices, direcionado);
            cout << "Grafo vazio criado com sucesso." << endl;
            break;
        }
        case 3:
            meuGrafo.exibirTodasAsAdjacencias();
            break;
        case 4:
        {
            int u, v;
            cout << "Digite os dois vertices para consultar adjacencia (u v): ";
            cin >> u >> v;
            if (meuGrafo.consultarSeAdjacente(u, v))
                cout << "Os vertices " << u << " e " << v << " sao adjacentes." << endl;
            else
                cout << "Os vertices " << u << " e " << v << " nao sao adjacentes." << endl;
            break;
        }
        case 5:
        {
            int u, v, p;
            cout << "Digite os vertices e o peso da aresta a ser inserida (u v p): ";
            cin >> u >> v >> p;
            meuGrafo.inserAresta(u, v, p);
            break;
        }
        case 6:
        {
            int numArestas;
            cout << "Quantas arestas deseja inserir? ";
            cin >> numArestas;
            for (int i = 0; i < numArestas; ++i)
            {
                int u, v, p;
                cout << "Digite os vertices e o peso da aresta " << (i + 1) << " (u v p): ";
                cin >> u >> v >> p;
                meuGrafo.inserAresta(u, v, p);
            }
            break;
        }
        case 7:
        {
            int u, v;
            cout << "Digite os vertices da aresta a ser removida (u v): ";
            cin >> u >> v;
            meuGrafo.removerAresta(u, v);
            break;
        }
        case 8:
        {
            int u, x, y;
            cout << "Digite o vertice e suas novas coordenadas (u x y): ";
            cin >> u >> x >> y;
            meuGrafo.editarCoordenadaDoVertice(u, x, y);
            break;
        }
        case 9:
        {
            int u;
            string nome;
            cout << "Digite o vertice e seu novo nome (u nome): ";
            cin >> u;
            cin.ignore(); // Limpa o buffer do cin
            getline(cin, nome);
            meuGrafo.editarNomeDoVertice(u, nome);
            break;
        }
        case 10:
        {
            int u;
            cout << "Digite o vertice para consultar o primeiro adjacente (u): ";
            cin >> u;
            int primeiroAdj = meuGrafo.primeiroAdjacenteDoVertice(u);
            if (primeiroAdj != -1)
                cout << "O primeiro adjacente do vertice " << u << " e: " << primeiroAdj << endl;
            else
                cout << "O vertice " << u << " nao possui adjacentes." << endl;
            break;
        }
        case 11:
        {
            int u, atual;
            cout << "Digite o vertice e o adjacente atual para consultar o proximo adjacente (u atual): ";
            cin >> u >> atual;
            int proximoAdj = meuGrafo.proximoAdjacenteDoVertice(u, atual);
            if (proximoAdj != -1)
                cout << "O proximo adjacente do vertice " << u << " apos " << atual << " e: " << proximoAdj << endl;
            else
                cout << "Nao ha mais adjacentes para o vertice " << u << " apos " << atual << "." << endl;
            break;
        }
        case 12:
        {
            int u;
            cout << "Digite o vertice para consultar a lista completa de adjacentes (u): ";
            cin >> u;
            meuGrafo.listaCompletaDeAdjacentesDoVertice(u);
            break;
        }
        case 13:
            cout << "Realizando busca em profundidade..." << endl;
            meuGrafo.buscaProfundidade();
            break;
        case 14:
            meuGrafo.buscaLargura();
            break;
        case 15:
            cout << "Executando Algoritmo de Prim..." << endl;
            meuGrafo.Prim();
            break;
        case 16:
            meuGrafo.exportar();
            break;
        case 17:
            meuGrafo.exportarArquivoJson();
            cout << "Grafo exportado para Grafo.json." << endl;
            system("start Grafo.html"); // Abre o arquivo HTML no navegador padrão
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}