// Definindo nome do arquivo de grafo
const nomeDoArquivoDeGrafo = "Grafo.json";

async function carregarDesenharGrafo() {
    try {
        const resposta = await fetch(nomeDoArquivoDeGrafo);
        if (!resposta.ok) {
            throw new Error(`Erro ao carregar o arquivo: ${resposta.statusText}`);
        }

        const dadosDoGrafo = await resposta.json();
    } catch (erro) {
        console.error("Erro ao carregar o grafo:", erro);
        container.innerHTML = "<h3>Erro ao carregar o grafo.</h3>";
        return;
    }
}
