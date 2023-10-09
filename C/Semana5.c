#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// Definindo tamanho de cada dado.
#define nome (sizeof(char) * 10)
#define idade (sizeof(int))
#define telefone (sizeof(int))

// Denifindo primeira pessoa e ultima pessoa.
#define primeiro (sizeof(int))
#define ultimo (sizeof(int) + sizeof(void **))

// Definindo anterio e sucessor
#define anterior (sizeof(char) * 10 + sizeof(int) + sizeof(int) + sizeof(void **))
#define sucessor (sizeof(char) * 10 + sizeof(int) + sizeof(int))

// Declarações de Funções.
void *adicionar(void *pbuffer, void *pAux);
void buscar(void *pBuffer, void *pAux, void *pRun);
void listar(void *pbuffer, void *pAux);

int main()
{
    SetConsoleOutputCP(65001);
    int *opcao = (int *)malloc(sizeof(int *)), *sair = (int *)malloc(sizeof(int *));

    void *pAux = NULL;
    pAux = malloc(sizeof(int) + sizeof(int) + sizeof(void **));
    *(int *)(pAux) = 0;

    void *pbuffer = NULL;
    pbuffer = malloc(sizeof(int) + sizeof(void **));

    void *pRun = NULL;

    if (!pbuffer || !pAux)
    {
        printf("Erro de alocação de Memória.\n");
        exit(1);
    }
    do
    {

        printf("\n             Selecione uma opção:             \n");
        printf(" 1 - Adicionar Nome\n");
        printf(" 2 - Remover Nome\n");
        printf(" 3 - Listar\n");
        printf(" 4 - Busque um nome na lista\n");
        printf(" 5 - Sair\n");
        printf("Digite uma opção:\n");
        scanf("%d", &((int *)opcao)[1]);
        getchar();
        system("clear||cls");

        switch (((int *)opcao)[1])
        {
        case 1:
            adicionar(pbuffer, pAux);

            break;
        case 2:
            printf("\n             Sua lista de Nomes             \n");

            break;
        case 3:
            listar(pbuffer, pAux);

            break;
        case 4:
            buscar(pbuffer, pAux, pRun);

            break;
        case 5:
            printf("\n             Encerrando Programa!!             \n");
            *(int *)sair = 0;

            break;
        default:
            printf("\n             Opção Invalida!!                         \n");
            printf("\n             Digite Uma Opção valida.             \n");
        }
    } while (*(int *)sair);

    free(pbuffer);
    free(pRun);
    free(pAux);
    free(opcao);
    free(sair);
    return 0;
}

void *adicionar(void *pbuffer, void *pAux)
{
    int *contador = (int *)(pAux);
    void *pInf_Pessoa = NULL;
    pInf_Pessoa = malloc(nome + idade + telefone + (2 * sizeof(void *)));

    void *pAux_Inf_Pessoa = NULL;
    if (!pInf_Pessoa)
    {
        printf("Erro de alocação de Memória.\n");
        exit(1);
    }

    printf("\nDigite o nome:\n ");
    scanf("%s", (char *)pInf_Pessoa);
    getchar();

    printf("\nDigite a idade:\n ");
    scanf("%d", &*(int *)(pInf_Pessoa + nome));
    getchar();

    printf("\nDigite o telefone:\n ");
    scanf("%d", &*(int *)(pInf_Pessoa + nome + idade));
    getchar();

    *(void **)(pInf_Pessoa + sucessor) = NULL;
    *(void **)(pInf_Pessoa + anterior) = NULL;

    if (*contador == 0)
    {
        *(void **)(pAux + ultimo) = pInf_Pessoa;
        *(void **)(pAux + primeiro) = pInf_Pessoa;
        *contador += 1;
        return 0;
    }

    pbuffer = *(void **)(pAux + primeiro);

    while (pbuffer != NULL)
    {
        if (strcmp((char *)pInf_Pessoa, (char *)pbuffer) < 0)
        {
            *(void **)(pInf_Pessoa + anterior) = *(void **)(pbuffer + anterior);
            *(void **)(pInf_Pessoa + sucessor) = pbuffer;

            if (*contador > 1 && *(void **)(pbuffer + anterior) != NULL)
            {
                pAux_Inf_Pessoa = *(void **)(pbuffer + anterior);
                *(void **)(pAux_Inf_Pessoa + sucessor) = pInf_Pessoa;
            }

            *(void **)(pbuffer + anterior) = pInf_Pessoa;

            if (*(void **)(pInf_Pessoa + anterior) == NULL)
            {
                *(void **)(pAux + primeiro) = pInf_Pessoa;
            }

            if (*contador == 1 && *(void **)(pbuffer + sucessor) == NULL)
            {
                *(void **)(pAux + ultimo) = pbuffer;
            }

            *contador += 1;

            return 0;
        }

        if (*(void **)(pbuffer + sucessor) == NULL)
        {
            pAux_Inf_Pessoa = pbuffer;
        }

        pbuffer = *(void **)(pbuffer + sucessor);
    }

    *(void **)(pAux_Inf_Pessoa + anterior) = pAux_Inf_Pessoa;
    *(void **)(pAux_Inf_Pessoa + sucessor) = pInf_Pessoa;
    *(void **)(pAux + ultimo) = pInf_Pessoa;

    *contador += 1;

    return 0;
}

void listar(void *pbuffer, void *pAux)
{
    void *pInf_Pessoa = NULL;
    pInf_Pessoa = *(void **)(pAux + primeiro);

    int *contador = (int *)(pAux);

    if (*contador == 0)
    {
        printf("             Lista Vazia!!             \n");
    }
    else
    {
        printf("             Sua lista de Nomes             \n\n");
        while (pInf_Pessoa != NULL)
        {
            printf("Nome: %s\n", (char *)pInf_Pessoa);
            printf("Idade: %d\n", *(int *)(pInf_Pessoa + nome));
            printf("Numero: %d\n\n", *(int *)(pInf_Pessoa + nome + idade));

            pInf_Pessoa = *(void **)(pInf_Pessoa + sucessor);
        }
    }
}
void buscar(void *pbuffer, void *pAux, void *pRun)
{
    int *contador = (int *)(pAux);

    void *busca_auxiliar = malloc(sizeof(char) * 10);

    pRun = *(void **)(pAux + primeiro);

    if (*contador == 0)
    {
        printf("             Lista Vazia!!             \n");
        free(busca_auxiliar);

        return;
    }
    else
    {
        printf("Digite um nome para buscar:\n");
        scanf("%s", (char *)busca_auxiliar);
        getchar();

        while (pRun != NULL)
        {
            if (strcmp(pRun, (char *)busca_auxiliar) == 0)
            {
                printf("Nome: %s\n", (char *)pRun);
                printf("Idade: %d\n", *(int *)(pRun + nome));
                printf("Numero: %d\n\n", *(int *)(pRun + nome + idade));

                free(busca_auxiliar);

                return;
            }
            pRun = *(void **)(pRun + sucessor);
        }
    }

    free(busca_auxiliar);

    return;
}