/*Faça um programa que armazene a informação de várias
pessoas.
typedef struct
{
   char nome[30];
   int idade;
   int altura;
}pessoa;
•
O programa só deve sair quando o usuário disser que não
deseja mais entrar com os dados de outra pessoa.
•
Antes de sair o programa deve apresentar, de forma
organizada, os dados de todas as pessoas.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tamanhostruct = 0;
void *adicionar(void *pbuffer, int tamanhostruct);
void *listar(void *pbuffer, int tamanhostruct);
typedef struct
{
    char nome[30];
    int idade;
    float altura;
} pessoa;

int main(void)
{

    int sair = 1, opcao, repetir = 1;
    void *pbuffer = calloc(1, sizeof(pessoa));
    while (sair)
    {

        printf("\n-----------------Selecione uma opcao-----------------\n");
        printf(" 1 - Adicionar nome\n");
        printf(" 2 - Listar\n");
        printf(" 3 - Sair\n");
        printf("Digite uma opcao:\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {

        case 1:
            repetir = 1;
            while (repetir)
            {
                pbuffer = adicionar(pbuffer, tamanhostruct);
                tamanhostruct++;
                printf("\nDigite 1 para adicionar outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();
            }
            break;
        case 2:
            listar(pbuffer, tamanhostruct);
            break;
        case 3:
            free(pbuffer);
            sair = 0;

            break;
        }
    }
    free(pbuffer);
}
void *adicionar(void *pbuffer, int tamanhostruct)
{
    pessoa p;
    pessoa *ptr;
    pbuffer = (void *)realloc(pbuffer, (tamanhostruct + 1) * sizeof(pessoa));
    printf("\n---------------------------Digite os dados da pessoa-------------------------\n");
    printf("Nome da pessoa: ");
    fgets(p.nome, 30, stdin);
    printf("Idade da Pessoa: ");
    scanf("%d", &p.idade);
    printf("Altura: ");
    scanf("%f", &p.altura);
    getchar();
    ptr = pbuffer + (tamanhostruct * sizeof(pessoa));
    *ptr = p;
    return pbuffer;
    free(ptr);
}

void *listar(void *pbuffer, int tamanhostruct)
{
    pessoa p;
    pessoa *ptr;
    int i;

    if (tamanhostruct == 0)
    {
        printf("\n-----------------Lista Vazia-----------------\n");
    }
    else
    {
        printf("\n-----------------Exibindo Dados-----------------\n");
        for (i = 0; i < tamanhostruct; i++)
        {
            ptr = pbuffer + (i * sizeof(pessoa));
            p = *ptr;

            printf("Nome: %s", p.nome);
            printf("Idade: %d Anos\n", p.idade);
            printf("Altura: %.2f Metros\n\n", p.altura);
        }
    }
    return pbuffer;
}
