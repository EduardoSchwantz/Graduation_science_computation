#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define tam 10000
int matriz[tam][tam];
int roboAltura = 0, roboDistancia = 0;
char direcao[2];

void inicializar(int largura, int comprimento);
void imprimir(int largura, int comprimento);
void incrementar(int largura, int comprimento);
void decrementar(int largura, int comprimento);
void girarEsquerda();
void girarDireita();
int main()
{
    SetConsoleOutputCP(65001);
    int largura, comprimento, exit;
    char escolha[2];
    printf("\nDigite a largura do plano cartesiano: ");
    scanf("%d", &largura);
    printf("\nDigite a comprimento do plano cartesiano: ");
    scanf("%d", &comprimento);
    inicializar(largura, comprimento);
    do
    {
        imprimir(largura, comprimento);
        printf("\n\n\n\n\tPara avançar 1 posicação para frente digite 'F'");
        printf("\n\tPara voltar 1 posicação para frente digite 'T'");
        printf("\n\tPara fazer uma rotação 90º para a esquerda sem se movimentar digite 'E'");
        printf("\n\tPara fazer uma rotação 90º para a direita sem se movimentar digite 'D'");
        printf("\n\tPara sair do Programa digite 'Sair': ");
        getchar();
        scanf("%s", escolha);
        system("cls||clear");
        if (strcmp(escolha, "sair") == 0 || strcmp(escolha, "Sair") == 0 || strcmp(escolha, "SAIR") == 0)
        {
            printf("\n\t\tSaindo....\n");
            exit = 0;
        }

        if (strcmp(escolha, "f") == 0 || strcmp(escolha, "F") == 0)
        { // incrementar
            incrementar(largura, comprimento);
        }

        if (strcmp(escolha, "t") == 0 || strcmp(escolha, "T") == 0)
        { // decrementar
            decrementar(largura, comprimento);
        }

        if (strcmp(escolha, "e") == 0 || strcmp(escolha, "E") == 0)
        {
            girarEsquerda();
        }
        if (strcmp(escolha, "D") == 0 || strcmp(escolha, "d") == 0)
        {
            girarDireita();
        }
    } while (exit);
    return 0;
}
void inicializar(int largura, int comprimento)
{
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; i < comprimento; i++)
        {
            matriz[i][j] = 0;
        }
    }
    matriz[roboAltura][roboDistancia] = 1;
    direcao[0] = 'N';
}

void imprimir(int largura, int comprimento)
{
    int i, j;
    printf("\n\n\tO robo esta em x: %d e y: %d ", roboDistancia, roboAltura);
    printf("\n\tDireção: %c", direcao[0]);

    for (i = 0; i < largura; i++)
    {
        printf("\n\n");
        for (j = 0; j < comprimento; j++)
        {
            printf("\t%d", matriz[i][j]);
        }
    }
}
void incrementar(int largura, int comprimento)
{
    if (strcmp(direcao, "N") == 0)
    {
        if (roboAltura > 0)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboAltura--;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "L") == 0)
    {
        if (roboDistancia < comprimento - 1)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboDistancia++;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "S") == 0)
    {
        if (roboAltura < largura - 1)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboAltura++;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "O") == 0)
    {
        if (roboDistancia > 0)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboDistancia--;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
}
void decrementar(int largura, int comprimento)
{
    if (strcmp(direcao, "N") == 0)
    {
        if (roboAltura < largura - 1)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboAltura++;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "L") == 0)
    {
        if (roboDistancia > 0)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboDistancia--;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "S") == 0)
    {
        if (roboAltura > 0)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboAltura--;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
    else if (strcmp(direcao, "O") == 0)
    {
        if (roboDistancia < comprimento - 1)
        {
            matriz[roboAltura][roboDistancia] = 0;
            roboDistancia++;
            matriz[roboAltura][roboDistancia] = 1;
        }
        else
        {
            printf("\n\n\tErro!!\n\n\tRobo não pode passar limites do plano Cartesiano!!");
        }
    }
}
void girarEsquerda()
{
    if (strcmp(direcao, "N") == 0)
    {
        printf("\n\tGirando para Oeste");
        direcao[0] = 'O';
    }
    else if (strcmp(direcao, "O") == 0)
    {
        printf("\n\tGirando para Sul");
        direcao[0] = 'S';
    }
    else if (strcmp(direcao, "S") == 0)
    {
        printf("\n\tGirando para Leste");
        direcao[0] = 'L';
    }
    else if (strcmp(direcao, "L") == 0)
    {
        printf("\n\tGirando para Norte");
        direcao[0] = 'N';
    }
}
void girarDireita()
{
    if (strcmp(direcao, "N") == 0)
    {
        printf("\n\tGirando para Leste");
        direcao[0] = 'L';
    }
    else if (strcmp(direcao, "L") == 0)
    {
        printf("\n\tGirando para Sul");
        direcao[0] = 'S';
    }
    else if (strcmp(direcao, "S") == 0)
    {
        printf("\n\tGirando para Oeste");
        direcao[0] = 'O';
    }
    else if (strcmp(direcao, "O") == 0)
    {
        printf("\n\tGirando para Norte");
        direcao[0] = 'N';
    }
}