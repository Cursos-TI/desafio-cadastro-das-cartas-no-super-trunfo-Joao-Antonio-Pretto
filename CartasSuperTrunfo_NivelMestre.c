#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1; //utilização da letra de A até H
    char codigo1[4]; // 3 caracteres + '\0', A01, B02...
    char cidade1[50]; 
    unsigned long int populacao1; //população só pode ser positivo
    float area1; //deve ser inserida em km²
    float pib1; //deve ser inserido em bilhões de reais
    unsigned int pontos_turisticos1; //pontos turísticos só podem ser positivos

    // Variáveis para a segunda carta
    char estado2; 
    char codigo2[4]; 
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    unsigned int pontos_turisticos2;

    // Variáveis auxiliares
    float densidade_pop1, densidade_pop2, pib_per_cap1, pib_per_cap2; // densidade populacional e pib per capita de cada cidade
    float super_poder1, super_poder2;
    unsigned int comparador_pop, comparador_area, comparador_pib, comparador_densidade, comparador_pib_per_capita;
    unsigned int comparador_pontotur;
    unsigned int comparador_super_poder;

        printf("Bem-vindo ao jogo super-trunfo em C! Você deve cadastrar duas cartas inicialmente. Utilize uma letra de A até H para representar o estado. \n");

    // Leitura dos dados da primeira carta
        printf("Cadastro da Carta 1:\n");
        printf("Estado (A-H): ");
        scanf(" %c", &estado1);
    
        printf("Código da Carta (ex: A01): ");
        scanf("%3s", codigo1); //ler uma string de no máximo 3 caracteres
    
        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cidade1); // '%[^\n' Lê até encontrar uma quebra de linha "\n", nova linha, evitando o problema do "espaço"
    
        printf("População: ");
        scanf("%lu", &populacao1);
    
        printf("Área (em km² e não esqueça de utilizar o ponto '.' ao invés da vírgula ','. Ex.: 12345.33): ");
        scanf("%f", &area1);
    
        printf("PIB (em bilhões de reais, não esqueça de utilizar o ponto '.' ao invés da vírgula ','. Ex.: 12345.33): ");
        scanf("%f", &pib1);
    
        printf("Número de Pontos Turísticos: ");
        scanf("%u", &pontos_turisticos1);

    // Leitura dos dados da segunda carta
        printf("\nCadastro da Carta 2:\n");
        printf("Estado (A-H): ");
        scanf(" %c", &estado2);
    
        printf("Código da Carta (ex: B02): ");
        scanf("%3s", codigo2);
    
        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cidade2);
    
        printf("População: ");
        scanf("%lu", &populacao2);
    
        printf("Área (em km² e não esqueça de utilizar o ponto '.' ao invés da vírgula ','. Ex.: 12345.33): ");
        scanf("%f", &area2);
    
        printf("PIB (em bilhões de reais, não esqueça de utilizar o ponto '.' ao invés da vírgula ','. Ex.: 12345.33): ");
        scanf("%f", &pib2);
    
        printf("Número de Pontos Turísticos: ");
        scanf("%u", &pontos_turisticos2);


        densidade_pop1 = (float) populacao1 / area1; //conversão explícita para float
        densidade_pop2 = (float) populacao2 / area2;
        pib_per_cap1 = (float) (pib1 * 1000000000) / populacao1; //multiplicação por um bilhão, para converter a unidade de bilhões para milhares de reais, mais intuitivo com a ideia de "pib per capita"
        pib_per_cap2 = (float) (pib2 * 1000000000) / populacao2;
        super_poder1 = (float) (populacao1 + area1 + pib1 + pontos_turisticos1 + (1 / densidade_pop1) + pib_per_cap1); //matematicamente, o inverso de um número é uma fração com 1/número especificado
        super_poder2 = (float) (populacao2 + area2 + pib2 + pontos_turisticos2 + (1 / densidade_pop2) + pib_per_cap2);


    // Exibição dos dados da primeira carta
        printf("\nCarta 1:\n");
        printf("Estado: %c\n", estado1);
        printf("Código: %s\n", codigo1);
        printf("Nome da Cidade: %s\n", cidade1);
        printf("População: %lu\n", populacao1);
        printf("Área: %.2f km²\n", area1);
        printf("PIB: %.2f bilhões de reais\n", pib1);
        printf("Número de Pontos Turísticos: %u\n", pontos_turisticos1);
        printf("Densidade populacional: %.2f hab/km² \n", densidade_pop1);
        printf("PIB per capita: %.2f reais \n", pib_per_cap1);
        

    // Exibição dos dados da segunda carta
        printf("\nCarta 2:\n");
        printf("Estado: %c\n", estado2);
        printf("Código: %s\n", codigo2);
        printf("Nome da Cidade: %s\n", cidade2);
        printf("População: %lu\n", populacao2);
        printf("Área: %.2f km²\n", area2);
        printf("PIB: %.2f bilhões de reais\n", pib2);
        printf("Número de Pontos Turísticos: %u\n", pontos_turisticos2);
        printf("Densidade populacional: %.2f hab/km² \n", densidade_pop2);
        printf("PIB per capita: %.2f reais \n", pib_per_cap2);

    // Comparação de cartas
        comparador_pop = (int) populacao1 > populacao2; //compara a população da carta 1 com a da carta 2
        comparador_area = (int) area1 > area2; //compara a área da carta 1 com a da carta 2
        comparador_pib = (int) pib1 > pib2; //compara o PIB da carta 1 com o da carta 2
        comparador_pontotur = (int) pontos_turisticos1 > pontos_turisticos2; //compara o número de pontos turísticos da carta 1 com o da carta 2
        comparador_densidade = (int) densidade_pop1 < densidade_pop2; //compara a densidade populacional da carta 1 com a carta 2, retornando a vitória para a menor densidade
        comparador_pib_per_capita = (int) pib_per_cap1 > pib_per_cap2; //compara o pib per capita da carta 1 com o da carta 2
        comparador_super_poder = (int) super_poder1 > super_poder2;

        printf("\nPara a leitura do resultado, considere o seguinte: quando o resultado for '1', a Carta 1 venceu. Quando o resultado for '0', a Carta 2 venceu! \n");
        printf("\n");
        printf("\nResultado do Super-Trunfo: \n");
        printf("\nPopulação: %u\n", comparador_pop);
        printf("\nÁrea: %u\n", comparador_area);
        printf("\nPIB: %u\n", comparador_pib);
        printf("\nPontos Turísticos: %u\n", comparador_pontotur);
        printf("\nDensidade Populacional: %u\n", comparador_densidade);
        printf("\nPIB Per Capita: %u \n", comparador_pib_per_capita);
        printf("\nSuper-Poder: %u \n", comparador_super_poder);

    return 0;
}
