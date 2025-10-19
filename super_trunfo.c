#include <stdio.h>

// Estrutura para representar uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao;  // Alterado para unsigned long int
    double area;
    double pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
    float super_poder;  // Armazenado como float conforme especificado
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
    scanf("%lu", &carta->populacao);  // %lu para unsigned long int
    
    printf("Área (km²): ");
    scanf("%lf", &carta->area);
    
    printf("PIB (bilhões de reais): ");
    scanf("%lf", &carta->pib);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para calcular densidade populacional
double calcularDensidade(unsigned long int populacao, double area) {
    return (double)populacao / area;
}

// Função para calcular PIB per capita
double calcularPIBperCapita(double pib_bilhoes, unsigned long int populacao) {
    return (pib_bilhoes * 1000000000.0) / populacao;
}

// Função para calcular Super Poder
float calcularSuperPoder(struct Carta carta) {
    float super_poder = 0.0f;
    
    // Conversões explícitas para float conforme especificado
    // População: convertendo unsigned long int para float
    super_poder += (float)carta.populacao;
    
    // Área: convertendo double para float
    super_poder += (float)carta.area;
    
    // PIB: convertendo de bilhões para unidades e depois para float
    super_poder += (float)(carta.pib * 1000000000.0);
    
    // Pontos turísticos: convertendo int para float
    super_poder += (float)carta.pontos_turisticos;
    
    // PIB per capita: convertendo double para float
    super_poder += (float)carta.pib_per_capita;
    
    // Inverso da densidade populacional (quanto menor a densidade, maior o poder)
    // Convertendo double para float
    if (carta.densidade > 0) {
        super_poder += (float)(1.0 / carta.densidade);
    }
    
    return super_poder;
}

// Função para realizar todos os cálculos de uma carta
void realizarCalculos(struct Carta *carta) {
    carta->densidade = calcularDensidade(carta->populacao, carta->area);
    carta->pib_per_capita = calcularPIBperCapita(carta->pib, carta->populacao);
    carta->super_poder = calcularSuperPoder(*carta);
}

// Função para exibir dados de uma carta
void exibirDados(struct Carta carta, int numero_carta) {
    printf("\nCarta %d:\n", numero_carta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

// Função para comparar as cartas e exibir resultados
void compararCartas(struct Carta carta1, struct Carta carta2) {
    printf("\nComparação de Cartas:\n");
    
    // População: maior valor vence
    int resultado_populacao = carta1.populacao > carta2.populacao;
    printf("População: Carta %d venceu (%d)\n", resultado_populacao ? 1 : 2, resultado_populacao);
    
    // Área: maior valor vence
    int resultado_area = carta1.area > carta2.area;
    printf("Área: Carta %d venceu (%d)\n", resultado_area ? 1 : 2, resultado_area);
    
    // PIB: maior valor vence
    int resultado_pib = carta1.pib > carta2.pib;
    printf("PIB: Carta %d venceu (%d)\n", resultado_pib ? 1 : 2, resultado_pib);
    
    // Pontos Turísticos: maior valor vence
    int resultado_pontos = carta1.pontos_turisticos > carta2.pontos_turisticos;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", resultado_pontos ? 1 : 2, resultado_pontos);
    
    // Densidade Populacional: MENOR valor vence (regra especial)
    int resultado_densidade = carta1.densidade < carta2.densidade;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado_densidade ? 1 : 2, resultado_densidade);
    
    // PIB per Capita: maior valor vence
    int resultado_pib_per_capita = carta1.pib_per_capita > carta2.pib_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n", resultado_pib_per_capita ? 1 : 2, resultado_pib_per_capita);
    
    // Super Poder: maior valor vence
    int resultado_super_poder = carta1.super_poder > carta2.super_poder;
    printf("Super Poder: Carta %d venceu (%d)\n", resultado_super_poder ? 1 : 2, resultado_super_poder);
}

int main() {
    // Declaração das cartas
    struct Carta carta1, carta2;
    
    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Cadastre duas cartas para comparacao\n");
    
    // Entrada de dados
    entradaDados(&carta1, 1);
    entradaDados(&carta2, 2);
    
    // Cálculos
    realizarCalculos(&carta1);
    realizarCalculos(&carta2);
    
    // Exibição dos dados completos
    printf("\n=== DADOS DAS CARTAS ===\n");
    exibirDados(carta1, 1);
    exibirDados(carta2, 2);
    
    // Comparação das cartas
    compararCartas(carta1, carta2);
    
    return 0;
}