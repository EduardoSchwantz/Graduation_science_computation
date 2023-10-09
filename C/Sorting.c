#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>
void preenche_vetor(int *vetor, int tam);
void imprimir(int *vetor, int tam);
void selection_sort(int *vetor, int tam);
void insertion_sort(int *vetor, int tam);
void quick_sort(int *vetor, int pos_esq, int pos_dir);
void merge_sort(int *vetor, int inicio, int fim);
int particiona_quick_sort(int *vetor, int inicio, int fim);
void particiona_merge_sort(int *vetor, int inicio, int meio, int fim);

int main()
{
    SetConsoleOutputCP(65001);
    int tam, opcao, sair, *vetor;
    clock_t tempo;
    srand(time(NULL));

    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Criar vetor e preencher aleatóriamente o vetor.\n");
        printf(" 2 - Ordenação SELECTION SORT. \n");
        printf(" 3 - Ordenação INSERTION SORT.\n");
        printf(" 4 - Ordenação QUICK SORT.\n");
        printf(" 5 - Ordenação MERGE SORT.\n");
        printf(" 6 - Imprimir vetor.\n");
        printf(" 7 - Limpar vetor.\n");
        printf(" 0 - Sair.\n");
        printf("\n             Digite uma opção:             \n");
        scanf("%d", &opcao);
        getchar();
        system("clear||cls");
        switch (opcao)
        {
        case 1:

            printf("\nDigite o tamanho do vetor: ");
            scanf("%d", &tam);
            vetor = (int *)malloc(tam * sizeof(int));
            preenche_vetor(vetor, tam);
            break;

        case 2:
            tempo = 0;
            tempo = clock();
            selection_sort(vetor, tam - 1);
            printf("\nVetor ordenado utilizando SELECTION SORT\n");
            tempo = clock() - tempo;
            imprimir(vetor, tam);
            printf("\n             tempo gasto para ordenar utilizando SELECTION SORT: %lf\n", ((double)(tempo) / CLOCKS_PER_SEC));
            break;

        case 3:
            tempo = 0;
            tempo = clock();
            insertion_sort(vetor, tam - 1);
            printf("\n             Vetor ordenado utilizando INSERTION SORT             \n");
            tempo = clock() - tempo;
            imprimir(vetor, tam);
            printf("\n             tempo gasto para ordenar utilizando INSERTION SORT: %lf\n", ((double)(tempo) / CLOCKS_PER_SEC));
            break;

        case 4:
            tempo = 0;
            tempo = clock();
            quick_sort(vetor, 0, tam - 1);
            printf("\n             Vetor ordenado utilizando QUICK SORT             \n");
            tempo = clock() - tempo;
            imprimir(vetor, tam);
            printf("\n             tempo gasto para ordenar utilizando QUICK SORT: %lf\n", ((double)(tempo) / CLOCKS_PER_SEC));
            break;

        case 5:
            tempo = 0;
            tempo = clock();
            merge_sort(vetor, 0, tam - 1);
            printf("\n             Vetor ordenado utilizando MERGE SORT             \n");
            tempo = clock() - tempo;
            imprimir(vetor, tam);
            printf("\n             tempo gasto para ordenar utilizando MERGE SORT: %lf\n", ((double)(tempo) / CLOCKS_PER_SEC));
            break;

        case 6:
            imprimir(vetor, tam);
            break;

        case 7:
            free(vetor);
            tam = 0;
            break;

        case 0:
            sair = 0;
            break;

        default:
            printf("\n             Digite uma opção válida:             \n");
        }

    } while (sair);

    free(vetor);
    return 0;
}
void preenche_vetor(int *vetor, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 99999;
    }
}

void imprimir(int *vetor, int tam)
{
    printf("\n             Imprimindo Vetor:             \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d, ", vetor[i]);
    }
}

void selection_sort(int *vetor, int tam)
{
    int i, j, menor, troca;
    for (i = 0; i < tam; i++)
    {
        menor = i;
        for (j = i + 1; j < tam; j++) //  procura o menor valor dentro do vetor
        {
            if (vetor[j] < vetor[menor]) // testa posição por posição
                menor = j;               // salva a posição do valor menor
        }
        if (i != menor) //  se a posição for diferente
        {
            troca = vetor[i];        //  troca recebe o valor da posição maior
            vetor[i] = vetor[menor]; //  o menor é posto na posição certa
            vetor[menor] = troca;    // o maior vai para a posição do menor
        }                            //    ou seja faz a troca.
    }
}
void insertion_sort(int *vetor, int tam) //  insere na posição correta diretamente.
{
    int i, j, aux;
    for (i = 1; i < tam; i++) //  tam = ultima posição do vetor para testar com todos valores do vetor
    {
        aux = vetor[i];                                   //  aux recebe o valor da posição do vetor que esta checando.
        for (j = i; (j > 0) && (aux < vetor[j - 1]); j--) // repete até encontrar o menor que ele
        {
            vetor[j] = vetor[j - 1]; //    faz a troca o maior passa pra frente.
            vetor[j - 1] = aux;      //    menor fica antes.
        }
    } //    isso repete até testar o ultimo termo do vetor
}

void quick_sort(int *vetor, int inicio, int fim) //  algoritmo que particiona o vetor, com base no pivo,  onde todos antes serão menores e todos dps dele serão maiores
{                                                //  "dividir e conquistar."
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona_quick_sort(vetor, inicio, fim); //  chama a função para organizar o vetor com base no pivo, todos menores antes e maiores depois.
        quick_sort(vetor, inicio, pivo - 1);              //  chama a função novamente sendo a ultima posição 1 antes do pivo
        quick_sort(vetor, pivo + 1, fim);                 //  chama a função novamente sendo a primeira posição 1 dps do pivo
    }
}

int particiona_quick_sort(int *vetor, int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;         //  esq recebe a posição do primeiro termo passada para a função
    dir = fim;            //  dir recebe a posição do último termo passado para a função
    pivo = vetor[inicio]; //  pivo sempre sera a primeira posição da partição passada

    while (esq < dir) // repete enquanto for esq < dir, no momento que chegarem na mesma posição a repetição para.
    {
        while (vetor[esq] <= pivo) //  repete até encontar um valor maior que o pivo,  e para na posição para fazer a troca.
            esq++;                 //  cada repetição incrementa 1 posição a esquerda
        while (vetor[dir] > pivo)  //  repete até encontar um valor menor que o pivo,  e para na posição para fazer a troca.
            dir--;                 //  cada repetição decrementa 1 na posição da direita

        if (esq < dir) //  sempre que esquerda for menor que direita faz a troca dos valores.
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir]; // o primeiro termo vai receber o ultimo valor antes do pivo.
    vetor[dir] = pivo;          // e o ultimo valor antes do pivo recebe o valor do primeiro termo.
    return dir;                 // retorna a posição do pivo dentro do vetor.
}

void merge_sort(int *vetor, int inicio, int fim) // sistema de ordenação onde se divide o vetor em duas partes, utilizando algoritimo testando as duas partes
{                                                //  e armazenando em um vetor auxiliar.
    int meio;
    if (inicio < fim) //  se a primeira posição for menor que a última
    {
        meio = floor(inicio + fim) / 2;  //  faz o calculo arrendonando para baixo, para saber o meio do vetor.
        merge_sort(vetor, inicio, meio); //  chama a função novamente para cada parte.
        merge_sort(vetor, meio + 1, fim);
        particiona_merge_sort(vetor, inicio, meio, fim); // faz a ordenação das metades.
    }
}

void particiona_merge_sort(int *vetor, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));

    if (temp != NULL) //  se diferente de nulo
    {
        for (i = 0; i < tamanho; i++) //  repete para todo vetor
        {
            if (!fim1 && !fim2) // se contrario de fim1 e contrario de fim2
            {
                if (vetor[p1] < vetor[p2]) // se primeira posição de p1 for menor que
                    temp[i] = vetor[p1++]; // entao salva na posição i do vetor auxiliar o valor de p1 e incrementa ele para proximo teste
                else
                    temp[i] = vetor[p2++]; // caso contrario  salva o valor do vetor p2,  e incrementa o p2

                if (p1 > meio) //  caso um dos duas metades acabe seta ele em 1
                    fim1 = 1;
                if (p2 > fim) //  para cair no caso do outra metade ser maior e terminar de escrever no vetor auxiliar
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vetor[k] = temp[j]; //    passa para o vetor posição por posição ordenadamente.
    }
    free(temp);
}