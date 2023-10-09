#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define M 19

typedef struct
{
    int matricula;
    char nome[50];
    int idade, ddd, telefone;
} Pessoa;

typedef struct no
{
    Pessoa pessoa;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

Lista *tabela[M];

Pessoa criarPessoa();
void print(Pessoa p);
Lista *criarLista();
void inserirInicio(Pessoa p, Lista *lista);
No *buscarNo(int matricula, No *inicio);
void imprimirLista(No *inicio);
void inicializar();
int hashing(int matricula);
void inserirTabela();
Pessoa *buscarPessoaTabela(int matricula);
void imprimirTabela();
No *remover(Lista *lista, int matricula);

int main()
{
    SetConsoleOutputCP(65001);
    system("clear||cls");
    printf("\n\t\tTrabalho sobre Hashing\n\n\tDiciplina: Algoritmos e Estruturas de Dados\n\tProfessor: GUILHERME TOMASCHEWSKI NETTO\n\n");
    printf("\n\tIntegrantes do Grupo:");
    printf("\n\tEDUARDO SCHWANTZ.\n\tCECILIA BOTELHO.\n\tPEDRO Henrique Lima de Mesquita\n\n");
    printf("\tProposta do Programa: Agenda de lista encadeada, utilizando o método hashing para inserção, busca e remoção.\n\n");
    int option, exit = 1, matricula;
    Pessoa *p;
    No *removido;
    inicializar();

    do
    {   
        printf("\n\t\t\tSelecione uma opção:\n");
        printf("\t1 - Novo Contato.\n");
        printf("\t2 - Buscar contato.\n");
        printf("\t3 - Remover contato.\n");
        printf("\t4 - Imprimir Agenda.\n");
        printf("\t0 - Sair.\n");
        printf("\n\t\t\tDigite uma opção: ");
        scanf("%d", &option);
        getchar();
        system("clear||cls");
        switch (option)
        {
        case 1:
            inserirTabela();
            break;
        case 2:
            printf("\nDigite a matricula a ser Buscada: ");
            scanf("%d", &matricula);
            p = buscarPessoaTabela(matricula);
            if (p)
            {
                printf("\n\tImprimindo Dados...\n\n");
                printf("\tMatricula do Contato:%d\n\tNome:%s\n\tIdade:%d\n\tTelefone:(%d)%d\n", p->matricula, p->nome, p->idade, p->ddd, p->telefone);
            }
            else
                printf("\n\n\tPessoa não encontrada!\n");

            break;
        case 3:
            printf("\nDigite a matricula a ser Removida: ");
            scanf("%d", &matricula);
            removido = remover(tabela[hashing(matricula)], matricula);
            if (removido)
            {
                printf("\n\tContato: \n");
                printf("\tMatricula do Contato:%d\n\tNome:%s\n\tIdade:%d\n\tTelefone:(%d)%d\n", 
                removido->pessoa.matricula, removido->pessoa.nome, removido->pessoa.idade,
                removido->pessoa.ddd ,removido->pessoa.telefone);
                printf("\n\tRemovido com Sucesso!!\n\n");
                free(removido);
            }
            else
                printf("\n\n\tPessoa não encontrada!\n");
            break;
        case 4:
            imprimirTabela();
            break;
        case 0:
            exit = 0;
            break;

        default:
            printf("\n\tDigite uma opção válida:\n");
        }
    } while (exit);
    free(p);
    return 0;
}

void inicializar()
{
    int i;
    for (i = 0; i < M; i++)
        tabela[i] = criarLista();
}

Lista *criarLista()
{
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

void inserirTabela()
{
    Pessoa pes = criarPessoa();
    int indice = hashing(pes.matricula);
    inserirInicio(pes, tabela[indice]);
}

Pessoa criarPessoa()
{
    Pessoa p;
    printf("\nDigite a matricula do contato: ");
    scanf("%d", &p.matricula);
    printf("\nDigite o Nome do contato: ");
    getchar();
    scanf("%50[^\n]", p.nome);
    printf("\nDigite a idade do contato: ");
    scanf("%d", &p.idade);
    printf("\nDigite o telefone do contato ddd 999999999: ");
    scanf("%d %d", &p.ddd ,&p.telefone);
    getchar();
    return p;
}

int hashing(int matricula)
{
    return matricula % M;
}

void inserirInicio(Pessoa p, Lista *lista)
{
    No *no = malloc(sizeof(No));
    no->pessoa = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

Pessoa *buscarPessoaTabela(int matricula)
{
    int indice = hashing(matricula);
    No *no = buscarNo(matricula, tabela[indice]->inicio);
    if (no)
        return &no->pessoa;
    else
        return NULL;
}

No *buscarNo(int matricula, No *inicio)
{

    while (inicio != NULL)
    {
        if (inicio->pessoa.matricula == matricula)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; // matricula não encontrada
}

No *remover(Lista *lista, int matricula)
{
    No *aux, *remover = NULL;
    if (lista->inicio)
    {
        if (lista->inicio->pessoa.matricula == matricula)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo && aux->proximo->pessoa.matricula != matricula)
                aux = aux->proximo;
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }
    return remover;
}

void imprimirTabela(Lista *lista)
{
    int i, contador = 0;
    for (i = 0; i < M; i++)
    {
        if (tabela[i]->tam != 0)
        {
            printf("\n%d\tLista tamanho: %d\n", i, tabela[i]->tam);
            imprimirLista(tabela[i]->inicio);
        }
        else
        {
            contador++;
        }
    }
    if (contador == M)
    {
        printf("\n\t\tLista de contatos está vázia!!\n");
    }
}

void imprimirLista(No *inicio)
{
    while (inicio != NULL)
    {
        print(inicio->pessoa);
        inicio = inicio->proximo;
    }
}

void print(Pessoa p)
{
    printf("\n\tMatricula do Contato: %d\n\tNome: %s\n\tIdade: %d\n\tTelefone: (%d) %d\n", p.matricula, p.nome, p.idade, p.ddd, p.telefone);
}