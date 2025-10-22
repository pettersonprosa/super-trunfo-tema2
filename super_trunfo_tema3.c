#include <stdio.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[3];
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
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
}

// Função para exibir o menu principal
void exibirMenuPrincipal() {
    printf("\n=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
    printf("=== COMPARAÇÃO COM DOIS ATRIBUTOS ===\n\n");
}

// Função para exibir menu de atributos dinâmico
void exibirMenuAtributos(int atributoExcluido) {
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("Escolha um atributo para comparação:\n");
    
    // Menu dinâmico - não mostra o atributo já escolhido
    for (int i = 1; i <= 6; i++) {
        if (i != atributoExcluido) {
            switch(i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Populacional\n", i); break;
                case 6: printf("%d - PIB per Capita\n", i); break;
            }
        }
    }
    printf("Digite sua opção: ");
}

// Função para obter o nome do atributo
char* obterNomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "POPULAÇÃO";
        case 2: return "ÁREA";
        case 3: return "PIB";
        case 4: return "PONTOS TURÍSTICOS";
        case 5: return "DENSIDADE POPULACIONAL";
        case 6: return "PIB PER CAPITA";
        default: return "ATRIBUTO DESCONHECIDO";
    }
}

// Função para obter o valor do atributo de uma carta
float obterValorAtributo(struct Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        case 6: return carta.pib_per_capita;
        default: return 0.0f;
    }
}

// Função para comparar dois valores de atributo (retorna 1 se c1 vencer, 0 se c2 vencer)
int compararAtributoIndividual(struct Carta c1, struct Carta c2, int atributo) {
    float valor1 = obterValorAtributo(c1, atributo);
    float valor2 = obterValorAtributo(c2, atributo);
    
    // Operador ternário para densidade populacional (regra especial)
    return (atributo == 5) ? (valor1 < valor2) : (valor1 > valor2);
}

// Função para obter pontuação de um atributo (para soma)
float obterPontuacaoAtributo(struct Carta carta, int atributo) {
    float valor = obterValorAtributo(carta, atributo);
    
    // Para densidade populacional, invertemos a lógica (menor = melhor)
    // Usamos o inverso para manter a consistência na soma
    if (atributo == 5) {
        return (valor > 0) ? (1000000.0f / valor) : 0.0f;
    }
    
    return valor;
}

// Função principal de comparação com dois atributos
void compararComDoisAtributos(struct Carta c1, struct Carta c2, int atributo1, int atributo2) {
    printf("\n=== RESULTADO DA COMPARAÇÃO AVANÇADA ===\n");
    printf("Carta 1: %s (%s)\n", c1.nome_cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.nome_cidade, c2.estado);
    printf("Atributos escolhidos: %s e %s\n", 
           obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
    
    printf("\n--- COMPARAÇÃO INDIVIDUAL ---\n");
    
    // Comparação do primeiro atributo
    int resultado1 = compararAtributoIndividual(c1, c2, atributo1);
    float valor1_c1 = obterValorAtributo(c1, atributo1);
    float valor1_c2 = obterValorAtributo(c2, atributo1);
    
    printf("\n%s:\n", obterNomeAtributo(atributo1));
    printf("%s: ", c1.nome_cidade);
    
    // Operador ternário para formatação de valores
    (atributo1 == 1 || atributo1 == 4) ? printf("%.0f", valor1_c1) : printf("%.2f", valor1_c1);
    (atributo1 == 1) ? printf(" hab") : 
    (atributo1 == 2) ? printf(" km²") :
    (atributo1 == 3) ? printf(" bilhões") :
    (atributo1 == 5) ? printf(" hab/km²") :
    (atributo1 == 6) ? printf(" reais") : printf("");
    
    printf("\n%s: ", c2.nome_cidade);
    (atributo1 == 1 || atributo1 == 4) ? printf("%.0f", valor1_c2) : printf("%.2f", valor1_c2);
    (atributo1 == 1) ? printf(" hab") : 
    (atributo1 == 2) ? printf(" km²") :
    (atributo1 == 3) ? printf(" bilhões") :
    (atributo1 == 5) ? printf(" hab/km²") :
    (atributo1 == 6) ? printf(" reais") : printf("");
    
    // Operador ternário para resultado
    printf("\nVencedor: %s\n", 
           (valor1_c1 == valor1_c2) ? "EMPATE" : 
           (resultado1) ? c1.nome_cidade : c2.nome_cidade);
    
    // Comparação do segundo atributo
    int resultado2 = compararAtributoIndividual(c1, c2, atributo2);
    float valor2_c1 = obterValorAtributo(c1, atributo2);
    float valor2_c2 = obterValorAtributo(c2, atributo2);
    
    printf("\n%s:\n", obterNomeAtributo(atributo2));
    printf("%s: ", c1.nome_cidade);
    (atributo2 == 1 || atributo2 == 4) ? printf("%.0f", valor2_c1) : printf("%.2f", valor2_c1);
    (atributo2 == 1) ? printf(" hab") : 
    (atributo2 == 2) ? printf(" km²") :
    (atributo2 == 3) ? printf(" bilhões") :
    (atributo2 == 5) ? printf(" hab/km²") :
    (atributo2 == 6) ? printf(" reais") : printf("");
    
    printf("\n%s: ", c2.nome_cidade);
    (atributo2 == 1 || atributo2 == 4) ? printf("%.0f", valor2_c2) : printf("%.2f", valor2_c2);
    (atributo2 == 1) ? printf(" hab") : 
    (atributo2 == 2) ? printf(" km²") :
    (atributo2 == 3) ? printf(" bilhões") :
    (atributo2 == 5) ? printf(" hab/km²") :
    (atributo2 == 6) ? printf(" reais") : printf("");
    
    printf("\nVencedor: %s\n", 
           (valor2_c1 == valor2_c2) ? "EMPATE" : 
           (resultado2) ? c1.nome_cidade : c2.nome_cidade);
    
    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    
    // Cálculo da soma dos atributos (com ajuste para densidade)
    float soma_c1 = obterPontuacaoAtributo(c1, atributo1) + obterPontuacaoAtributo(c1, atributo2);
    float soma_c2 = obterPontuacaoAtributo(c2, atributo1) + obterPontuacaoAtributo(c2, atributo2);
    
    printf("%s: %.2f pontos\n", c1.nome_cidade, soma_c1);
    printf("%s: %.2f pontos\n", c2.nome_cidade, soma_c2);
    
    printf("\n--- RESULTADO FINAL ---\n");
    
    // Determinação do vencedor final com operador ternário
    if (soma_c1 == soma_c2) {
        printf("EMPATE! As cartas têm a mesma pontuação total.\n");
    } else {
        char* vencedor = (soma_c1 > soma_c2) ? c1.nome_cidade : c2.nome_cidade;
        float pontuacaoVencedor = (soma_c1 > soma_c2) ? soma_c1 : soma_c2;
        
        printf("CAMPEÃO: %s\n", vencedor);
        printf("Pontuação total: %.2f pontos\n", pontuacaoVencedor);
        
        // Análise detalhada do resultado
        printf("\nANÁLISE:\n");
        printf("- Venceu em %d dos 2 atributos\n", 
               (resultado1 + resultado2));
        
        if (soma_c1 > soma_c2) {
            printf("- %s teve melhor desempenho geral\n", c1.nome_cidade);
        } else {
            printf("- %s teve melhor desempenho geral\n", c2.nome_cidade);
        }
    }
}

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;
    char continuar;
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, "SP", "A01", "São Paulo", 
                  12325000, 1521.11f, 699.28f, 50);
    cadastrarCarta(&carta2, "RJ", "B02", "Rio de Janeiro", 
                  6748000, 1200.25f, 300.50f, 30);
    
    do {
        exibirMenuPrincipal();
        
        // Exibir cartas disponíveis
        printf("=== CARTAS DISPONÍVEIS ===\n");
        exibirCarta(carta1, 1);
        exibirCarta(carta2, 2);
        
        // Escolha do primeiro atributo
        printf("\n--- ESCOLHA DO PRIMEIRO ATRIBUTO ---\n");
        exibirMenuAtributos(0); // 0 significa nenhum atributo excluído
        scanf("%d", &atributo1);
        
        // Validação da primeira escolha
        if (atributo1 < 1 || atributo1 > 6) {
            printf("Opção inválida! Escolha um número entre 1 e 6.\n");
            continue;
        }
        
        // Escolha do segundo atributo (menu dinâmico)
        printf("\n--- ESCOLHA DO SEGUNDO ATRIBUTO ---\n");
        printf("💡 Dica: Escolha um atributo diferente do primeiro!\n");
        exibirMenuAtributos(atributo1); // Exclui o primeiro atributo
        scanf("%d", &atributo2);
        
        // Validação da segunda escolha
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Opção inválida! Escolha um atributo diferente do primeiro.\n");
            continue;
        }
        
        // Executar comparação avançada
        compararComDoisAtributos(carta1, carta2, atributo1, atributo2);
        
        // Perguntar se deseja continuar
        printf("\nDeseja fazer outra comparação? (s/n): ");
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    printf("\nObrigado por jogar Super Trunfo - Nível Mestre!\n");
    
    return 0;
}