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

// Função para exibir o menu de opções, excluindo uma opção já escolhida
int exibirMenuSegundoAtributo(int primeiraEscolha)
{
       int opcao;
       printf("\n\nEscolha o segundo atributo para comparação:\n");
       if (primeiraEscolha != 1)
              printf("1 - População\n");
       if (primeiraEscolha != 2)
              printf("2 - Área\n");
       if (primeiraEscolha != 3)
              printf("3 - PIB\n");
       if (primeiraEscolha != 4)
              printf("4 - Pontos Turísticos\n");
       if (primeiraEscolha != 5)
              printf("5 - Densidade Populacional\n");
       if (primeiraEscolha != 6)
              printf("6 - PIB per Capita\n");
       printf("0 - Sair\n");
       printf("Sua escolha: ");
       scanf("%d", &opcao);
       return opcao == primeiraEscolha ? 0 : opcao;
}

// Função para obter o valor do atributo baseado na opção
float obterValorAtributo(struct Carta carta, int opcao)
{
       switch (opcao)
       {
       case 1:
              return (float)carta.populacao;
       case 2:
              return carta.area;
       case 3:
              return carta.pib;
       case 4:
              return (float)carta.pontosTuristicos;
       case 5:
              return carta.densidadePopulacional;
       case 6:
              return carta.pibPerCapita;
       default:
              return 0.0f;
       }
}

// Função para obter o nome do atributo
const char *obterNomeAtributo(int opcao)
{
       switch (opcao)
       {
       case 1:
              return "População";
       case 2:
              return "Área";
       case 3:
              return "PIB";
       case 4:
              return "Pontos Turísticos";
       case 5:
              return "Densidade Populacional";
       case 6:
              return "PIB per Capita";
       default:
              return "Desconhecido";
       }
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

void compararCartasDoisAtributos(struct Carta carta1, struct Carta carta2, int opcao1, int opcao2)
{
       float valor1_atr1 = obterValorAtributo(carta1, opcao1);
       float valor2_atr1 = obterValorAtributo(carta2, opcao1);
       float valor1_atr2 = obterValorAtributo(carta1, opcao2);
       float valor2_atr2 = obterValorAtributo(carta2, opcao2);

       // Ajusta valores para densidade populacional (menor é melhor)
       if (opcao1 == 5)
       {
              valor1_atr1 = -valor1_atr1;
              valor2_atr1 = -valor2_atr1;
       }
       if (opcao2 == 5)
       {
              valor1_atr2 = -valor1_atr2;
              valor2_atr2 = -valor2_atr2;
       }

       float soma1 = valor1_atr1 + valor1_atr2;
       float soma2 = valor2_atr1 + valor2_atr2;

       printf("\nComparação de cartas com dois atributos:\n");
       printf("\nCarta 1 - %s:", carta1.cidade);
       printf("\n%s: %.2f", obterNomeAtributo(opcao1), valor1_atr1);
       printf("\n%s: %.2f", obterNomeAtributo(opcao2), valor1_atr2);
       printf("\nSoma: %.2f", soma1);

       printf("\n\nCarta 2 - %s:", carta2.cidade);
       printf("\n%s: %.2f", obterNomeAtributo(opcao1), valor2_atr1);
       printf("\n%s: %.2f", obterNomeAtributo(opcao2), valor2_atr2);
       printf("\nSoma: %.2f", soma2);

       printf("\n\nResultado: ");
       if (soma1 == soma2)
       {
              printf("Empate!\n");
       }
       else
       {
              printf("Carta %d (%s) venceu!\n",
                     (soma1 > soma2) ? 1 : 2,
                     (soma1 > soma2) ? carta1.cidade : carta2.cidade);
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
       int opcao1, opcao2;
       do
       {
              opcao1 = exibirMenu();
              if (opcao1 != 0)
              {
                     opcao2 = exibirMenuSegundoAtributo(opcao1);
                     if (opcao2 != 0)
                     {
                            compararCartasDoisAtributos(carta1, carta2, opcao1, opcao2);
                     }
              }
       } while (opcao1 != 0);

       return 0;
}
