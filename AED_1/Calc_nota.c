#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    int tam, i, opcao, sair;
    float *notas, *pesos, calc_notas, soma_pesos, resultado, peso_prova_a_fazer;
    system("clear||cls");
    printf("Programa feito para ajudar alunos desesperados.\n");
    printf("Direitos autorais reservados a Eduardo Schwantz\n");
    printf("Link do meu GitHub para acessar futuras atualizações ou outros algoritmos\n");
    printf("https://github.com/EduardoSchwantz\n");
    printf("\nCaso queira contribuir\n");
    printf("pix: eduardo_schwantz@hotmail.com\n");
    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Calcular Média e saber se passou ou ficou em exame, e a nota que terá que tirar no exame.\n");
        printf(" 2 - Saber quanto precisa tirar em 1 prova para atingir 7,0.\n");
        printf(" 0 - Sair.\n");
        printf("\n             Digite uma opção:             \n");
        scanf("%d", &opcao);
        getchar();
        system("clear||cls");
        printf("\nAtenção: Ao separar casas decimais utilizar . 'PONTO' \n");
        switch (opcao)
        {
        case 1:
            resultado = 0;
            soma_pesos = 0;
            calc_notas = 0;
            printf("Digite quantas notas deseja calcular: ");
            scanf("%d", &tam);

            notas = (float *)malloc(tam * sizeof(float));
            pesos = (float *)malloc(tam * sizeof(float));
            for (i = 0; i < tam; i++)
            {
                printf("\nDigite a nota da prova %d: ", i + 1);
                scanf("%f", &notas[i]);
                printf("\nDigite o peso da prova %d: ", i + 1);
                scanf("%f", &pesos[i]);
            }
            for (i = 0; i < tam; i++)
            {
                calc_notas = calc_notas + (notas[i] * pesos[i]);
                soma_pesos = soma_pesos + (pesos[i]);
            }

            resultado = calc_notas / soma_pesos;

            printf("\nSua nota é: %.2f\n", resultado);

            if (resultado >= 7.0)
            {
                printf("\nVocê passou sem exame!!\n");
            }
            else if (resultado >= 3.0 && resultado < 7.0)
            {
                printf("\nVocê está em exame!!\n");
                resultado = 10.0 - resultado;
                printf("\nPara atingir 5.0, irá ter que tirar: %f ", resultado);
            }
            else if (resultado < 3.0)
            {
                printf("\nVocê rodou e não tem direito ao exame!\n");
            }
        case 2:
            resultado = 0;
            calc_notas = 0;
            peso_prova_a_fazer = 0;
            printf("Digite a quantidade de provas -1 'Exemplos: se são 3 provas digite 2...' : ");
            scanf("%d", &tam);

            notas = (float *)malloc(tam * sizeof(float));
            pesos = (float *)malloc(tam * sizeof(float));
            for (i = 0; i < tam; i++)
            {
                printf("\nDigite a nota da prova %d: ", i + 1);
                scanf("%f", &notas[i]);
                printf("\nDigite o peso da prova %d: ", i + 1);
                scanf("%f", &pesos[i]);
            }
            printf("\nDigite o peso da prova a fazer: ");
            scanf("%f", &peso_prova_a_fazer);

            for (i = 0; i < tam; i++)
            {
                calc_notas = calc_notas + (notas[i] * pesos[i]);
            }
            resultado = (7.0 - calc_notas) / peso_prova_a_fazer;
            if (resultado <= 10.0)
            {
                printf("\nVocê precisa tirar %.2f para atingir média 7.0 no semestre", resultado);
            }
            else
            printf("\nvocê já está em exame mesmo tirando 10.0\n");
            
            break;
        case 0:
            sair = 0;
            break;
        default:
            printf("\n             Digite uma opção válida:             \n");
        }

    } while (sair);
    free(notas);
    free(pesos);
    return 0;
}