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

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n=== MENU DE COMPARAÇÃO - SUPER TRUNFO ===\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("0 - Sair do jogo\n");
    printf("Digite sua opção (0-6): ");
}

// Função para comparar as cartas baseado na opção escolhida
void compararCartas(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Carta 1: %s (%s)\n", c1.nome_cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.nome_cidade, c2.estado);
    
    // Estrutura switch para determinar o atributo a comparar
    switch(opcao) {
        case 1: // População
            printf("Atributo: POPULAÇÃO\n");
            printf("%s: %d habitantes\n", c1.nome_cidade, c1.populacao);
            printf("%s: %d habitantes\n", c2.nome_cidade, c2.populacao);
            
            // Estruturas de decisão aninhadas para população
            if (c1.populacao > c2.populacao) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Tem maior população\n");
            } else if (c2.populacao > c1.populacao) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Tem maior população\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: ÁREA\n");
            printf("%s: %.2f km²\n", c1.nome_cidade, c1.area);
            printf("%s: %.2f km²\n", c2.nome_cidade, c2.area);
            
            // Estruturas de decisão aninhadas para área
            if (c1.area > c2.area) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Tem maior área territorial\n");
            } else if (c2.area > c1.area) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Tem maior área territorial\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões de reais\n", c1.nome_cidade, c1.pib);
            printf("%s: %.2f bilhões de reais\n", c2.nome_cidade, c2.pib);
            
            // Estruturas de decisão aninhadas para PIB
            if (c1.pib > c2.pib) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Tem maior Produto Interno Bruto\n");
            } else if (c2.pib > c1.pib) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Tem maior Produto Interno Bruto\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: PONTOS TURÍSTICOS\n");
            printf("%s: %d pontos turísticos\n", c1.nome_cidade, c1.pontos_turisticos);
            printf("%s: %d pontos turísticos\n", c2.nome_cidade, c2.pontos_turisticos);
            
            // Estruturas de decisão aninhadas para pontos turísticos
            if (c1.pontos_turisticos > c2.pontos_turisticos) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Oferece mais atrações turísticas\n");
            } else if (c2.pontos_turisticos > c1.pontos_turisticos) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Oferece mais atrações turísticas\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        case 5: // Densidade Populacional (REGRA ESPECIAL)
            printf("Atributo: DENSIDADE POPULACIONAL\n");
            printf("%s: %.2f hab/km²\n", c1.nome_cidade, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nome_cidade, c2.densidade);
            printf("REGRA ESPECIAL: Menor densidade vence!\n");
            
            // Estruturas de decisão aninhadas para densidade (regra invertida)
            if (c1.densidade < c2.densidade) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Tem menor densidade populacional (mais espaço)\n");
            } else if (c2.densidade < c1.densidade) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Tem menor densidade populacional (mais espaço)\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        case 6: // PIB per Capita
            printf("Atributo: PIB PER CAPITA\n");
            printf("%s: %.2f reais\n", c1.nome_cidade, c1.pib_per_capita);
            printf("%s: %.2f reais\n", c2.nome_cidade, c2.pib_per_capita);
            
            // Estruturas de decisão aninhadas para PIB per capita
            if (c1.pib_per_capita > c2.pib_per_capita) {
                printf("RESULTADO: %s VENCEU! \n", c1.nome_cidade);
                printf("Motivo: Tem maior riqueza por habitante\n");
            } else if (c2.pib_per_capita > c1.pib_per_capita) {
                printf("RESULTADO: %s VENCEU! \n", c2.nome_cidade);
                printf("Motivo: Tem maior riqueza por habitante\n");
            } else {
                printf("RESULTADO: EMPATE!\n");
            }
            break;
            
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
}

int main() {
    // Declaração das cartas
    struct Carta carta1, carta2;
    int opcao;
    
    printf("=== SUPER TRUNFO - NÍVEL AVENTUREIRO ===\n");
    printf("=== SISTEMA INTERATIVO DE COMPARAÇÃO ===\n\n");
    
    // Cadastro das cartas pré-definidas
    printf("Cadastrando cartas...\n");
    cadastrarCarta(&carta1, "SP", "A01", "São Paulo", 
                  12325000, 1521.11f, 699.28f, 50);
    cadastrarCarta(&carta2, "RJ", "B02", "Rio de Janeiro", 
                  6748000, 1200.25f, 300.50f, 30);
    
    printf("Cartas cadastradas com sucesso!\n");
    
    // Exibir dados das cartas
    printf("\n=== CARTAS DISPONÍVEIS ===\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    // Loop principal do menu interativo
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        // Limpar buffer do teclado
        while (getchar() != '\n');
        
        if (opcao == 0) {
            printf("\nObrigado por jogar Super Trunfo!\n");
            printf("Até a próxima!\n");
            break;
        }
        
        // Verificar se a opção é válida
        if (opcao >= 1 && opcao <= 6) {
            compararCartas(carta1, carta2, opcao);
            
            // Perguntar se quer continuar
            printf("\nDeseja fazer outra comparação? (s/n): ");
            char continuar;
            scanf(" %c", &continuar);
            
            if (continuar == 'n' || continuar == 'N') {
                printf("\n🎮 Obrigado por jogar Super Trunfo!\n");
                break;
            }
        } else {
            printf("Opção inválida! Por favor, escolha uma opção entre 0 e 6.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}