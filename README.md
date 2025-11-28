# 📊 Grafo Matrix - Gerenciador e Visualizador de Grafos
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![License](https://img.shields.io/badge/License-MIT-2ECC71?style=for-the-badge)

Trabalho prático da disciplina de **Algoritmos e Estruturas de Dados III (AEDS III)**.



## 📌 Sobre o Projeto
Esse projeto é uma implementação da estrutura de dados **Grafo**, utilizando a representação por Matriz de Adjacência em C++.
Desenvolvido originalmente como trabalho prático da disciplina de Algoritmos e Estruturas de Dados III (AEDS III), ele serve como um Gerenciador de Grafos robusto,
com um diferencial crucial: a capacidade de exportar o grafo para uma interface web interativa (HTML/JavaScript/Cytoscape.js) para visualização em tempo real.

## 🧠 Funcionalidades do Sistema

- Importação de grafo via arquivo texto  
- Criação de grafo vazio  
- Inserção de arestas individuais ou em conjunto  
- Remoção de arestas  
- Verificação de adjacências  
- Consulta de primeiro e próximo adjacente  
- Listagem completa de adjacentes
- Gerenciar coordenadas dos vertives 
- Exportação para arquivo `.txt`  
- Geração automática de visualização em `.html`

## 🖥️ Tecnologias Utilizadas

- Linguagem C++
- Programação Orientada a Objetos
- Alocação dinâmica de memória
- HTML5
- CSS3
- JavaScript
- Biblioteca Cytoscape.js

## 📂 Estrutura do Projeto
```text
📁 GRAFOS
 ├── Dados.txt
 ├── Grafo_app.exe
 ├── Grafo_base.html
 ├── Grafo.cpp
 ├── Grafo.hpp
 ├── LICENSE
 ├── Main.cpp
 ├── meu_grafo_direcionado.txt
 ├── meu_grafo_nao_direcionado.txt
 ├── renderizador.js
 └── styles.css
```
### 📄 Descrição dos Arquivos

- **Grafo.hpp** → Definição da classe Grafo  
- **Grafo.cpp** → Implementação dos métodos do grafo  
- **Main.cpp** → Programa principal  
- **Grafo_base.html** → Estrutura base da visualização  
- **renderizador.js** → Script de renderização  
- **styles.css** → Estilos da interface  
- **Dados.txt / meu_grafo_*.txt** → Arquivos de entrada  
- **Grafo_app.exe** → Executável do projeto  
- **LICENSE** → Licença do projeto  

## ⚙️ Como usar

### Pré-requisitos

- Usar um compilador C++ (Recomendação: g++)
- Garantir que todos os arquivos estejam em um único diretório

### ⌨️ Pelo Prompt de Comando (CMD)

Navegue até o repositorio raiz e compile o projeto:
```bash
# Compila os arquivos de implementação (Grafo.cpp, main.cpp) em um único executável
g++ main.cpp Grafo.cpp -o Grafo_app
```
Em seguida, execute o binário gerado e interaja com o menu de opções interativo:
```bash
./Grafo_app
```

### 🗂️ Pela Pasta

Encontre o executável dentro da pasta, execute-o e interaja com o menu que irá abrir.

## 📥 Formato do Arquivo de Entrada

Exemplo:
```texto
direcionado=nao
5
0 100 200
1 300 200
2 200 400
3 400 400
4 500 200
6
0 1 10
1 2 5
2 3 8
3 4 12
4 0 7
1 3 6
```

Formato:
- 1ª linha → tipo do grafo (direcionado=sim/direcionado=nao)
- 2ª linha → número de vértices
- Próximas linhas → vértice x y
- Depois → número de arestas
- Em seguida → u v peso

## 🖼️ Visualização do Grafo

Ao selecionar a **opção 13 no menu**, o sistema:
- Gera o arquivo Grafo.html
- Abre automaticamente no navegador
- Permite visualizar vértices, arestas, pesos e direção

## 🤝 Contribuições
Sinta-se à vontade para sugerir melhorias, corrigir bugs ou implementar os próximos algoritmos.

1. Faça um fork deste repositório.
2. Crie uma nova branch para sua funcionalidade.
3. Abra um Pull Request detalhando as mudanças.
