document.addEventListener('DOMContentLoaded', function() {
    // 1. Tenta carregar o arquivo JSON exportado pelo C++
    fetch('Grafo.json')
        .then(response => {
            if (!response.ok) {
                // Se falhar (problema CORS ou arquivo não encontrado), lança um erro
                throw new Error('Erro ao carregar grafo.json. Status: ' + response.status);
            }
            return response.json();
        })
        .then(data => {
            // Se os dados JSON foram lidos com sucesso
            initializeCytoscape(data);
        })
        .catch(error => {
            console.error('Falha na visualização:', error);
            alert('Não foi possível carregar os dados.');
        });
});