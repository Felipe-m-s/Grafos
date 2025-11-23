// Definindo nome do arquivo de grafo
const nomeDoArquivoDeGrafo = "Grafo.json";

async function carregarDesenharGrafo() {
    try {
        const resposta = await fetch(nomeDoArquivoDeGrafo);
        if (!resposta.ok) {
            throw new Error(`Erro ao carregar o arquivo: ${resposta.statusText}`);
        }

        const dadosDoGrafo = await resposta.json();

        const vertices = dadosDoGrafo.vertices.map(v => ({
            group: 'vertices',
            data: {
                id: v.id,
                x: v.x,
                y: v.y
            }
        }));

        const arestas = dadosDoGrafo.arestas.map((a, index) => ({
            group: 'arestas',
            data: {
                id: `a${index}`,
                de: a.de,
                para: a.para,
                peso: a.peso,
                label: String(a.peso)
            }
        }));

        const elementos = vertices.concat(arestas);

        var cy = cytoscape({
            container: container,
            elements: elementos,
            layout: {
                name: 'cose',
                seed: 42,
                animade: false,
                paddinf: 30
            },
        
        });

    } catch (erro) {
        console.error("Erro ao carregar o grafo:", erro);
        container.innerHTML = "<h3>Erro ao carregar o grafo.</h3>";
        return;
    }
}
