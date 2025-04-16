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

// Função para exibir o menu de opções
int exibirMenu()
{
       int opcao;
       printf("\n\nEscolha o atributo para comparação:\n");
       printf("1 - População\n");
       printf("2 - Área\n");
       printf("3 - PIB\n");
       printf("4 - Pontos Turísticos\n");
       printf("5 - Densidade Populacional\n");
       printf("6 - PIB per Capita\n");
       printf("0 - Sair\n");
       printf("Sua escolha: ");
       scanf("%d", &opcao);
       return opcao;
}

// Função genérica para exibir resultado da comparação
void exibirResultadoComparacao(const char *atributo, const char *cidade1, const char *cidade2,
                               float valor1, float valor2, int menorVence)
{
       printf("\nComparação de cartas (Atributo: %s):\n", atributo);
       printf("\nCarta 1 - %s: %.2f", cidade1, valor1);
       printf("\nCarta 2 - %s: %.2f", cidade2, valor2);

       printf("\n\nResultado: ");
       if (valor1 == valor2)
       {
              printf("Empate!\n");
       }
       else
       {
              int carta1Vence = menorVence ? (valor1 < valor2) : (valor1 > valor2);
              printf("Carta %d (%s) venceu!\n",
                     carta1Vence ? 1 : 2,
                     carta1Vence ? cidade1 : cidade2);
       }
}

void compararCartas(struct Carta carta1, struct Carta carta2, int opcao)
{
       switch (opcao)
       {
       case 1: // População
              exibirResultadoComparacao("População", carta1.cidade, carta2.cidade,
                                        (float)carta1.populacao, (float)carta2.populacao, 0);
              break;

       case 2: // Área
              exibirResultadoComparacao("Área", carta1.cidade, carta2.cidade,
                                        carta1.area, carta2.area, 0);
              break;

       case 3: // PIB
              exibirResultadoComparacao("PIB", carta1.cidade, carta2.cidade,
                                        carta1.pib, carta2.pib, 0);
              break;

       case 4: // Pontos Turísticos
              exibirResultadoComparacao("Pontos Turísticos", carta1.cidade, carta2.cidade,
                                        (float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos, 0);
              break;

       case 5: // Densidade Populacional
              exibirResultadoComparacao("Densidade Populacional", carta1.cidade, carta2.cidade,
                                        carta1.densidadePopulacional, carta2.densidadePopulacional, 1);
              break;

       case 6: // PIB per Capita
              exibirResultadoComparacao("PIB per Capita", carta1.cidade, carta2.cidade,
                                        carta1.pibPerCapita, carta2.pibPerCapita, 0);
              break;

       default:
              printf("\nOpção inválida!\n");
       }
}

int main()
{
       struct Carta carta1, carta2;
       int opcao;

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

       // Loop do menu
       do
       {
              opcao = exibirMenu();
              if (opcao != 0)
              {
                     compararCartas(carta1, carta2, opcao);
              }
       } while (opcao != 0);

       return 0;
}
