/*Faça um programa que armazena nomes.
• O programa deve armazenar todos os nomes na mesma string.
• O tamanho da string deve crescer e diminuir conforme nomes
forem colocados ou removidos. Não pode ter desperdício de
memória.
• Faça o seguinte menu:
– 1) Adicionar nome
– 2) Remover nome
– 3) Listar
– 4) Sair*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *adicionar(char *str);
char *remover(char *str);

int main()
{

    int repetir, opcao, sair = 1;
    char *nome = calloc(1, sizeof(char));

    while (sair)
    {

        printf("\n-------------Selecione uma opcao-----------------\n");
        printf(" 1 - Adicionar nome\n");
        printf(" 2 - Remover nome\n");
        printf(" 3 - Listar\n");
        printf(" 4 - Sair\n");
        printf("Digite uma opcao:\n");
        scanf("%d", &opcao);
        getchar();
        system("cls");
        switch (opcao)
        {
        case 1:
            repetir = 1;
            while (repetir)
            {
                nome = adicionar(nome);
                printf("\nDigite 1 para adicionar outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
            }

            break;

        case 2:
            repetir = 1;
            while (repetir)
            {
                remover(nome);
                printf("\nRemovido, verifique na opcao 3\n");
                printf("\nDigite 1 pra remover outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();
            }

            break;

        case 3:
            printf("------------------Sua lista de Nomes-----------------\n%s\n", nome);
            break;
        case 4:

            printf("Saindo....");
            sair = 0;
            break;
        }
    }
    return 0;
}
char *adicionar(char *str)
{
    int buffer_size, str_size;
    char divisao[] = ",", nomealuno[25];
    printf("Insira o nome: ");
    scanf("%s", nomealuno);
    getc(stdin);
    strcat(nomealuno, divisao);
    buffer_size = strlen(nomealuno);
    str_size = strlen(str);
    str = (char *)realloc(str, (buffer_size + str_size) * sizeof(char) + sizeof(char));
    strcat(str, nomealuno);
    return str;
}

char *remover(char *str)
{
    int tamanho, i;
    char removenome[25], divisao[] = ",", *start, *end, *test;

inicio:
    printf("Insira o nome a ser removido da lista: ");
    scanf("%s", removenome);
    getc(stdin);
    strcat(removenome, divisao);
    test = strstr(str, removenome);

    if (test != NULL)
    {
        tamanho = strlen(removenome);
        start = strstr(str, removenome); // achado o ponteiro pro começo da palavra a ser retirada, ou Null caso ela n exista
        end = start;                     // guarda o local do começo da palavra a ser retirada
        for (i = 0; i < tamanho; i++)    // end agora aponta pra primeira letra da proxima palavra
            end++;
        memmove(start, end, strlen(end) + 1); // sobrescreve a palavra com o restante da string. o +1 é para trazer o caractere nulo também.
        tamanho = strlen(str);
        str = (char *)realloc(str, tamanho * sizeof(char) + sizeof(char)); // diminue a quantidade de memória alocada, o +1 é para contar o caractere nulo.
        return str;
    }
    else
    {
        printf("Nome nao encontrado digite novamente.\n");
        goto inicio;
    }
}