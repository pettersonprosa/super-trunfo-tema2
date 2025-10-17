#include <stdio.h>

// Estrutura para representar uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
};

// Função para entrada de dados de uma carta
void entradaDados(struct Carta *carta, int numero_carta) {
    printf("\n=== CADASTRO CARTA %d ===\n", numero_carta);
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome_cidade);
    
    printf("População: ");
    scanf("%d", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%lf", &carta->area);
    
    printf("PIB (bilhões de reais): ");
    scanf("%lf", &carta->pib);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para calcular densidade populacional
double calcularDensidade(int populacao, double area) {
    return (double)populacao / area;
}

// Função para calcular PIB per capita
double calcularPIBperCapita(double pib_bilhoes, int populacao) {
    return (pib_bilhoes * 1000000000.0) / populacao;
}

// Função para realizar todos os cálculos de uma carta
void realizarCalculos(struct Carta *carta) {
    carta->densidade = calcularDensidade(carta->populacao, carta->area);
    carta->pib_per_capita = calcularPIBperCapita(carta->pib, carta->populacao);
}

// Função para exibir dados de uma carta
void exibirDados(struct Carta carta, int numero_carta) {
    printf("\nCarta %d:\n", numero_carta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
}

int main() {
    // Declaração das cartas
    struct Carta carta1, carta2;
    
    // Entrada de dados
    entradaDados(&carta1, 1);
    entradaDados(&carta2, 2);
    
    // Cálculos
    realizarCalculos(&carta1);
    realizarCalculos(&carta2);
    
    // Exibição dos resultados
    exibirDados(carta1, 1);
    exibirDados(carta2, 2);
    
    return 0;
}