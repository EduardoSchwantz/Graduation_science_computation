#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char *adicionar(char *str);
char *remover(char *str);
char *buscar(char *str);

int main()
{
    SetConsoleOutputCP(650001);

    int repetir, opcao, sair = 1;
    char *pbuffer = calloc(1, sizeof(char));
    printf("---------------Seja Bem Vindo!---------------------\n\n");

    while (sair)
    {
        printf("\n-------------Selecione uma opcao-----------------\n");
        printf(" 1 - Adicionar nome\n");
        printf(" 2 - Remover nome\n");
        printf(" 3 - Listar\n");
        printf(" 4 - Busque um nome na lista\n");
        printf(" 5 - Sair\n");
        printf("Digite uma opcao:\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            repetir = 1;
            while (repetir)
            {
                pbuffer = adicionar(pbuffer);
                printf("\nDigite 1 para adicionar outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();
            }

            break;
        case 2:
            repetir = 1;
            while (repetir)
            {
                printf("------------------Sua lista de Nomes-----------------\n%s\n", pbuffer);
                printf("-----------------------------------------------------\n");
                remover(pbuffer);
                printf("\nDigite 1 pra remover outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();
            }

            break;
        case 3:
            printf("------------------Sua lista de Nomes-----------------\n%s\n", pbuffer);
            break;
        case 4:
            buscar(pbuffer);
            break;
        case 5:
            printf("Saindo....");
            sair = 0;
            break;
        }
    }
    free(pbuffer);
    return 0;
}
char *adicionar(char *str)
{
    int buffer_size, str_size;
    char divisaoNome[] = "\n", dados[200], idade[50], telefone[50];
    char separar_nome_idade[] = " -> Idade: ", complementar_idade[] = " Anos";
    char separar_idade_telefone[] = " -> Telefone: ";
    printf("------------------Insira os Dados-----------------");
    printf("\nInsira o nome: ");
    gets(dados);
    strcat(dados, separar_nome_idade);
    printf("\nInsira a idade do aluno: ");
    gets(idade);
    strcat(dados, idade);
    strcat(dados, complementar_idade);
    strcat(dados, separar_idade_telefone);
    printf("\nInsira o telefone do aluno: ");
    gets(telefone);
    strcat(dados, telefone);
    strcat(dados, divisaoNome);
    buffer_size = strlen(dados);
    str_size = strlen(str);
    str = (char *)realloc(str, (buffer_size + str_size) * sizeof(char) + sizeof(char));
    strcat(str, dados);
    return str;
}

char *remover(char *str)
{
    int tamanho, i;
    char removenome[20], *start, *end, *testeauxiliar, *guard = calloc(strlen(str), sizeof(char));
    printf("Insira o nome a ser removido da lista: ");
    gets(removenome);
    if (strstr(str, removenome) != NULL)
    {
        testeauxiliar = strstr(str, removenome);
        strcat(guard, testeauxiliar);
        guard = strtok(guard, "\n");

        tamanho = strlen(guard) + 1;
        start = strstr(str, testeauxiliar);
        end = start;
        for (i = 0; i < tamanho; i++)
            end++;
        memmove(start, end, strlen(end) + 1);
        tamanho = strlen(str);
        str = (char *)realloc(str, tamanho * sizeof(char) + sizeof(char));
        printf("Nome removido!!\n");
        free(guard);
        return str;
    }
    printf("Nome nao encontrado digite novamente.\n");
    free(guard);
    return str;
}
char *buscar(char *str)
{
    char buscarnome[20], *testeauxiliar, *guard = calloc(strlen(str), sizeof(char));
    printf("Insira o nome para buscar:\n");
    gets(buscarnome);
    if (strstr(str, buscarnome) != NULL)
    {
        testeauxiliar = strstr(str, buscarnome);
        strcat(guard, testeauxiliar);
        guard = strtok(guard, "\n");
        printf("------------------Dados-----------------");
        printf("\n%s\n", guard);
        free(guard);
        return str;
    }
    else
    {
        printf("Nome nao encontrado\n");
        free(guard);
        return str;
    }
}