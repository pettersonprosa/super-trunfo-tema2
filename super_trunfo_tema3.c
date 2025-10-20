#include <stdio.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[3];  // Para armazenar siglas como "SP", "RJ"
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
};

// Função para cadastrar os dados de uma carta
void cadastrarCarta(struct Carta *carta, char estado[], char codigo[], char nome[], 
                   int pop, float area_cidade, float pib_cidade, int pontos) {
    // Copia os dados básicos
    sprintf(carta->estado, "%s", estado);
    sprintf(carta->codigo, "%s", codigo);
    sprintf(carta->nome_cidade, "%s", nome);
    carta->populacao = pop;
    carta->area = area_cidade;
    carta->pib = pib_cidade;
    carta->pontos_turisticos = pontos;
    
    // Calcula densidade populacional e PIB per capita
    carta->densidade = (float)carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000000.0f) / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\n=== CARTA %d ===\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
}

// Função para comparar as cartas por população
void compararPorPopulacao(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", c1.nome_cidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %d\n", c2.nome_cidade, c2.estado, c2.populacao);
    
    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar as cartas por área
void compararPorArea(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: Área):\n");
    printf("Carta 1 - %s (%s): %.2f km²\n", c1.nome_cidade, c1.estado, c1.area);
    printf("Carta 2 - %s (%s): %.2f km²\n", c2.nome_cidade, c2.estado, c2.area);
    
    if (c1.area > c2.area) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.area > c1.area) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar as cartas por PIB
void compararPorPIB(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: PIB):\n");
    printf("Carta 1 - %s (%s): %.2f bilhões\n", c1.nome_cidade, c1.estado, c1.pib);
    printf("Carta 2 - %s (%s): %.2f bilhões\n", c2.nome_cidade, c2.estado, c2.pib);
    
    if (c1.pib > c2.pib) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.pib > c1.pib) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar as cartas por densidade populacional
void compararPorDensidade(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: Densidade Populacional):\n");
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", c1.nome_cidade, c1.estado, c1.densidade);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", c2.nome_cidade, c2.estado, c2.densidade);
    
    // Para densidade, menor valor vence (regra especial)
    if (c1.densidade < c2.densidade) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.densidade < c1.densidade) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar as cartas por PIB per capita
void compararPorPIBperCapita(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: PIB per Capita):\n");
    printf("Carta 1 - %s (%s): %.2f reais\n", c1.nome_cidade, c1.estado, c1.pib_per_capita);
    printf("Carta 2 - %s (%s): %.2f reais\n", c2.nome_cidade, c2.estado, c2.pib_per_capita);
    
    if (c1.pib_per_capita > c2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (c2.pib_per_capita > c1.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Declaração das cartas
    struct Carta carta1, carta2;
    
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE CARTAS ===\n");
    printf("=== NÍVEL NOVATO ===\n\n");
    
    // Cadastro das cartas pré-definidas (dados fixos no código)
    printf("Cadastrando cartas pré-definidas...\n");
    
    // Carta 1: São Paulo
    cadastrarCarta(&carta1, "SP", "A01", "São Paulo", 
                  12325000, 1521.11f, 699.28f, 50);
    
    // Carta 2: Rio de Janeiro
    cadastrarCarta(&carta2, "RJ", "B02", "Rio de Janeiro", 
                  6748000, 1200.25f, 300.50f, 30);
    
    // Exibir dados das cartas cadastradas
    printf("\n=== DADOS DAS CARTAS CADASTRADAS ===\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // COMPARAÇÕES - ATRIBUTO ESCOLHIDO DIRETAMENTE NO CÓDIGO
    printf("\n=== INICIANDO COMPARAÇÕES ===\n");
    
    // Comparação por POPULAÇÃO (atributo escolhido no código)
    compararPorPopulacao(carta1, carta2);
    
    // Comparação por ÁREA
    compararPorArea(carta1, carta2);
    
    // Comparação por PIB
    compararPorPIB(carta1, carta2);
    
    // Comparação por DENSIDADE POPULACIONAL (regra especial: menor valor vence)
    compararPorDensidade(carta1, carta2);
    
    // Comparação por PIB PER CAPITA
    compararPorPIBperCapita(carta1, carta2);
    
    printf("\n=== FIM DAS COMPARAÇÕES ===\n");
    
    return 0;
}