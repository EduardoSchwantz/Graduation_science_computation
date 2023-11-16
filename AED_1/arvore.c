#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct no
{
    int valor;
    struct no *direito, *esquerdo;
    int altura;
} No;

No *novoNo(int valor);
int maior(int a, int b);
int alturaDoNo(No *no);
int fatorDeBalanceamento(No *no);
No *rotacaoEsquerda(No *raiz);
No *rotacaoDireita(No *raiz);
No *rotacaoDuplaDireitaEsquerda(No *raiz);
No *rotacaoDuplaEsquerdaDireita(No *raiz);
No *balancear(No *raiz);
No *inserir(No *raiz, int valor);
void imprimir(No *raiz, int nivel);
No *remover(No *raiz, int valor);

int main()
{
    SetConsoleOutputCP(65001);
    int Qtd_Numeros, valor, *opcao = (int *)malloc(sizeof(int *)), *sair = (int *)malloc(sizeof(int *));
    No *raiz = NULL;
    srand(time(NULL));

    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Inserir número à lista.\n");
        printf(" 2 - Inserir número aleatorio na lista.\n");
        printf(" 3 - Remover número da lista.\n");
        printf(" 4 - Imprimir árvore.\n");
        printf(" 5 - Sair.\n");
        printf("\n             Digite uma opção:             \n");
        scanf("%d", &((int *)opcao)[1]);
        getchar();
        system("clear||cls");

        switch (((int *)opcao)[1])
        {
        case 1:
            valor = 0;
            printf("\nDigite o número que deseja adicionar na árvore: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            Qtd_Numeros = 0;
            printf("\nQuantos números aleatórios deseja Inserir?\n");
            scanf("%d", &Qtd_Numeros);
            for (int i = 0; i < Qtd_Numeros; i++)
            {
                valor = rand() % 3000;
                raiz = inserir(raiz, valor);
            }
            break;
        case 3:
            valor = 0;
            system("clear||cls");
            imprimir(raiz, 1);
            printf("\n\n\nDigite o Valor a ser removido:\n");
            scanf("%d", &valor);
            remover(raiz, valor);
            break;
        case 4:
            system("clear||cls");
            imprimir(raiz, 1);
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

    free(opcao);
    free(sair);
    free(raiz);
    return 0;
}

/*      Função que cria novo nó
        que retornará o endereço do nó criado.
*/
No *novoNo(int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar novo nó\n");
    return novo;
}

/*  função para retornar o maior
    entre dois valores.
*/
int maior(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

/* retorna a altura de um no
    caso seja diferente de
    nula retorna -1
*/
int alturaDoNo(No *no)
{
    if (no != NULL)
    {
        return no->altura;
    }
    else
        return -1;
}
/*
função retorna o fator de Balanceamento, para saber se qual rotação fazer.
*/
int fatorDeBalanceamento(No *no)
{
    if (no)
    {
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    }
    else
    {
        return 0;
    }
}

No *rotacaoEsquerda(No *raiz)
{ // função retorna um ponteiro do tipo no, que sera nossa nova raiz.

    No *novaraiz, *filho; // criasse dois ponteiros auxiliares para salvar endereços da nova raiz e do possivel filho.

    novaraiz = raiz->direito;   // nova raiz recebe  o filho direito da antiga raiz, que sera nossa nova raiz.
    filho = novaraiz->esquerdo; // filho salva o filho esquerdo da nossa nova raiz, se existir.

    novaraiz->esquerdo = raiz; // o filho esquerdo da nova raiz, vai recebem a raiz original.
    raiz->direito = filho;     // antiga raiz que agora é nossa nova raiz, recebe o possivel filho esquerdo novaraiz.(se houver).

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito) + 1);             // recalcula a altura da raiz, agora filho esquerdo da nova raiz.
    novaraiz->altura = maior(alturaDoNo(novaraiz->esquerdo), alturaDoNo(novaraiz->direito) + 1); // recalcula a altura da nova raiz, agora matriz da arvore.

    return novaraiz; // retorna endereço da novaraiz.
}

No *rotacaoDireita(No *raiz)
{                         // função retorna um ponteiro do tipo no, que sera nossa nova raiz.
    No *novaraiz, *filho; // criasse dois ponteiros auxiliares para salvar endereços da nova raiz e do possivel filho.

    novaraiz = raiz->esquerdo; // nova raiz recebe o filho esquerdo da antiga raiz.
    filho = novaraiz->direito; // filho recebe o possivel filho direito da nova raiz.

    novaraiz->direito = raiz; // filho direito da nova raiz recebe a antiga raiz.
    raiz->esquerdo = filho;   // a antiga raiz, agora filho direito da nova raiz, recebe o possivel filho da novaraiz.

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito) + 1);             // recalcula a altura da raiz, agora filho direito da nova raiz.
    novaraiz->altura = maior(alturaDoNo(novaraiz->esquerdo), alturaDoNo(novaraiz->direito) + 1); // recalcula a altura da nova raiz, agora matriz da arvore.
    return novaraiz;                                                                             // retorna endereço da novaraiz.
}

No *rotacaoDuplaDireitaEsquerda(No *raiz)
{

    raiz->direito = rotacaoDireita(raiz->direito); // realiza a rotação direita
    return rotacaoEsquerda(raiz->direito);         // retorna o retorno da função rotação Esquerda.
}

No *rotacaoDuplaEsquerdaDireita(No *raiz)
{
    raiz->esquerdo = rotacaoEsquerda(raiz->esquerdo); // realiza rotação Esquerda
    return rotacaoDireita(raiz->esquerdo);
    // retorna o retorno da função rotação direita.
}

/*
    Insere um novo nó na árvore
    Retorno: endereço do novo nó ou nova raiz após o balanceamento
*/
No *inserir(No *raiz, int valor)
{
    if (raiz == NULL) // árvore vazia
        return novoNo(valor);
    else
    {
        if (valor < raiz->valor) // será inserido a esquerda
            raiz->esquerdo = inserir(raiz->esquerdo, valor);
        else if (valor > raiz->valor) // será inserido direita
            raiz->direito = inserir(raiz->direito, valor);
        else
            printf("\nO elemento '%d' já existe!\n", valor); // se for igual a algum elemento aparecerá a mensagem
    }

    // recalcula a altura da raiz
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção
    Recebe o nó que está desbalanceado e retorna a nova raiz após o balanceamento
*/
No *balancear(No *raiz)
{
    int fb = fatorDeBalanceamento(raiz);

    // rotação para esquerda
    if (fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // rotação para direita
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // rotação dupla esquerda direita
    else if (fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoDuplaEsquerdaDireita(raiz);

    // rotação dupla direita esquerda
    else if (fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDuplaDireitaEsquerda(raiz);

    return raiz; // retorna ela balanceada, caso necessario.
}

/*
    função para imprimir
*/
void imprimir(No *raiz, int nivel)
{
    int i;
    if (raiz)
    {
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
            printf("      ");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
    printf("\n\n");
}

No *remover(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        printf("\n             Valor não Encontrado!!             \n");
        return NULL;
    }
    else
    {
        if (raiz->valor == valor)
        { // procura o nó a remover
            if (raiz->esquerdo == NULL && raiz->direito == NULL)
            { // remove nós folhas (nós sem filhos)
                free(raiz);
                printf("\n             Elemento folha removido: %d !             \n", valor);
                return NULL;
            }
            else
            {
                if (raiz->esquerdo != NULL && raiz->direito != NULL)
                { // remover nós que possuem 2 filhos
                    No *aux = raiz->esquerdo;
                    while (aux->direito != NULL)
                        aux = aux->direito;
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerdo = remover(raiz->esquerdo, valor);
                    return raiz;
                }
                else
                {
                    // remover nós que possuem apenas 1 filho
                    No *aux;
                    if (raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("\nElemento com 1 filho removido: %d !\n", valor);
                    // recalcula a altura da raiz
                    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

                    // verifica a necessidade de rebalancear a árvore
                    raiz = balancear(raiz);
                    return aux;
                }
            }
        }
        else
        {
            if (valor < raiz->valor)
                raiz->esquerdo = remover(raiz->esquerdo, valor);
            else
                raiz->direito = remover(raiz->direito, valor);
        }

        // recalcula a altura da raiz
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}