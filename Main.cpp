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
    cout << "2. Exibir todas as adjacencias" << endl;
    cout << "3. Consultar se dois vertices sao adjacentes" << endl;
    cout << "4. Inserir aresta" << endl;
    cout << "5. Remover aresta" << endl;
    cout << "6. Editar coordenada do vertice" << endl;
    cout << "7. Exportar grafo para arquivo" << endl;
    cout << "8. Visualizar grafo graficamente" << endl;
    cout << "9. Sair" << endl;
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
            meuGrafo.exibirTodasAsAdjacencias();
            break;
        case 3:
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
        case 4:
        {
            int u, v, p;
            cout << "Digite os vertices e o peso da aresta a ser inserida (u v p): ";
            cin >> u >> v >> p;
            meuGrafo.inserAresta(u, v, p);
            break;
        }
        case 5:
        {
            int u, v;
            cout << "Digite os vertices da aresta a ser removida (u v): ";
            cin >> u >> v;
            meuGrafo.removerAresta(u, v);
            break;
        }
        case 6:
        {
            int u, x, y;
            cout << "Digite o vertice e suas novas coordenadas (u x y): ";
            cin >> u >> x >> y;
            meuGrafo.editarCoordenadaDoVertice(u, x, y);
            break;
        }
        case 7:
            meuGrafo.exportar();
            break;
        case 8:
            meuGrafo.exportarArquivoJson();
            cout << "Grafo exportado para Grafo.json." << endl;
            break;
        case 9:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 9);

    return 0;
}