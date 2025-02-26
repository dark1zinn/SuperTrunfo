#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
struct Carta
{
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long int populacao; // Modificado para unsigned long int
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional; // Novo campo
    float pibPerCapita;          // Novo campo
    float superPoder;            // Novo campo
};

int main()
{
    struct Carta carta1, carta2;

    // Leitura dos dados da primeira carta
    printf("\nDigite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta1.cidade);
    printf("População: ");
    scanf("%lu", &carta1.populacao); // Modificado para %lu
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculos para carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;
    carta1.superPoder = carta1.populacao / 1000000.0 + carta1.area +
                        carta1.pib * 1000 + carta1.pontosTuristicos * 100 +
                        carta1.pibPerCapita / 1000.0 +
                        1000000.0 / carta1.densidadePopulacional;

    // Leitura dos dados da segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta2.cidade);
    printf("População: ");
    scanf("%lu", &carta2.populacao); // Modificado para %lu
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos para carta 2
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;
    carta2.superPoder = carta2.populacao / 1000000.0 + carta2.area +
                        carta2.pib * 1000 + carta2.pontosTuristicos * 100 +
                        carta2.pibPerCapita / 1000.0 +
                        1000000.0 / carta2.densidadePopulacional;

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n",
           (carta1.populacao > carta2.populacao) ? 1 : 2,
           (carta1.populacao > carta2.populacao));
    printf("Área: Carta %d venceu (%d)\n",
           (carta1.area > carta2.area) ? 1 : 2,
           (carta1.area > carta2.area));
    printf("PIB: Carta %d venceu (%d)\n",
           (carta1.pib > carta2.pib) ? 1 : 2,
           (carta1.pib > carta2.pib));
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 2,
           (carta1.pontosTuristicos > carta2.pontosTuristicos));
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 2,
           (carta1.densidadePopulacional < carta2.densidadePopulacional));
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 2,
           (carta1.pibPerCapita > carta2.pibPerCapita));
    printf("Super Poder: Carta %d venceu (%d)\n",
           (carta1.superPoder > carta2.superPoder) ? 1 : 2,
           (carta1.superPoder > carta2.superPoder));

    return 0;
}
