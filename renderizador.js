// Definindo nome do arquivo de grafo
const nomeDoArquivoDeGrafo = "Grafo.json";

async function carregarDesenharGrafo() {
    // Busca o container no DOM
    const container = document.getElementById('cy'); 

    if (!container) {
        console.error("Erro: O elemento container (id='cy') não foi encontrado no HTML.");
        return;
    }
    
    try {
        // const resposta = await fetch(nomeDoArquivoDeGrafo);
        // if (!resposta.ok) {
        //     throw new Error(`Erro ao carregar o arquivo: ${resposta.statusText}`);
        // }

        //const dadosDoGrafo = await resposta.json();
        const dadosDoGrafo = graphData;

        const isDirected = dadosDoGrafo.isDirected || false;

        // 1. Mapeamento de Nós: Lendo 'dadosDoGrafo.nodes'
        const nodes = dadosDoGrafo.nodes.map(v => ({
            group: 'nodes',
            data: {
                id: String(v.id),
            },

            position: {
                x: v.x,
                y: v.y
            }

        }));

        // 2. Mapeamento de Arestas: Lendo 'dadosDoGrafo.edges'
        const edges = dadosDoGrafo.edges.map((a, index) => ({
            group: 'edges',
            data: {
                id: `e${index}`,
                source: String(a.de),
                target: String(a.para),
                peso: a.peso,
                label: String(a.peso)
            }
        }));

        const elementos = nodes.concat(edges);

        var cy = cytoscape({
            container: container,
            elements: elementos,

            layout: {
                name: 'preset',
                padding: 30
            },
            
            style : [
                {
                    selector: 'node',
                    style: {
                        'background-color': '#BD93F9',
                        'label': 'data(id)',
                        'text-valign': 'center',
                        'color': '#fff',
                        'text-outline-width': 2,
                        'text-outline-color': '#BD93F9',
                        'width': '8px',
                        'height': '8px',
                        'font-size': '4px',
                        'border-color': '#8BE9FD',
                    }
                },
                {
                    selector: 'edge',
                    style: {
                        'width': 0.5,
                        'line-color': 'F8F8F2',
                        'target-arrow-color': '#ccc',
                        // Se 'isDirected' for false, a seta é 'none'
                        'target-arrow-shape': isDirected ? 'triangle' : 'none', 
                        'label': 'data(label)',
                        'font-size': 3,
                        'text-rotation': 'autorotate',
                        'color': '#50FA7B',
                        'text-background-color': '#282A36',
                        //'text-background-opacity': 0.7,
                        'text-background-padding': 2
                    }
                }
            ]
        });

        cy.userPanningEnabled(false); // Desabilita o pan com o mouse

        cy.on('tap', 'node', function(evt){
            var node = evt.target;
            alert('Nó clicado: ' + node.id() + '\nCoordenadas: (' + node.position('x') + ', ' + node.position('y') + ')');
        });

    } catch (erro) {
        console.error("Erro ao carregar o grafo:", erro);
        if (container) {
            container.innerHTML = `<h3> Erro ao carregar o grafo. Detalhe: ${erro.message}</h3>`;
        }
        return;
    }
}

document.addEventListener('DOMContentLoaded', carregarDesenharGrafo);

