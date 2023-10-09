#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

/* aqui é criado o no da lista encadeada */
typedef struct _thing /* cria uma struct do tipo _thing */
{
	char *item;			 /* cria dentro da struct um ponteiro do tipo char chamado item */
	struct _thing *next; /* cria um ponteiro do tipo _thing chamada next  */
} THING;				 /* define do nome da struct */

THING *start = NULL; /* inicia o ponteiro do tipo thing chamada start com valor nulo, sera a cabeça do nó */

THING *newelement(char *text) /* cria uma função ponteiro do tipo thing chamada newlement que recebe */
							  /* como parametro um ponteiro do tipo char chamada text  */
{
	THING *newp;								   /* cria uma variavel local ponteiro do tipo thing chamada newp */
	newp = (THING *)malloc(sizeof(THING));		   /* newp recebe uma alocação de tamanho thing, e essa alocação é definida para um ponteiro do tipo thing  */
	newp->item = (char *)malloc(strlen(text) + 1); /* struct newp no campo item, recebem uma alocação de tamanho do char text +1, e essa alocação é para um tipo ponteiro char */
	strcpy(newp->item, text);					   /* copia o conteudo do ponteiro text para o a struct newp no campo item*/
	newp->next = NULL;							   /* a struct newp no campo next recebe nulo */
	return newp;								   /* função retorna newp */
}

THING *delelement(THING *head, char *text) /* cria uma função ponteiro do tipo thing chama delelement que recebe como paramentro um ponteiro do tipo thing*/
										   /* chamada head  e um ponteiro do tipo char chamada text*/
{
	THING *p, *prev; /*cria dois ponteiro do tipo thing chamadas p e prev*/
	prev = NULL;	 /* o ponteiro prev recebe nulo*/
	for (p = head; p != NULL; p = p->next)
	{ /* inicia um for que p recebe head, repete ate p for diferente de nulo, e tem como incremento p recebe struct p campo next.*/
		if (strcmp(text, p->item) == 0)
		{							  /* se a comparação de text e struct p no campo item forem iguais, faça*/
			if (prev == NULL)		  /* se prev for igual a nulo */
				head = p->next;		  /* head recebe a struct no campo next*/
			else					  /* se a prev for diferente de nulo*/
				prev->next = p->next; /* a struct prev no campo next recebe a struct p no campo next */
			free(p->item);			  // limpa o buffer da struct p no campo item.
			free(p);				  // limpa o buffer da struct p
			return head;			  // se a struct prev for nulo retorna head
		}
		prev = p; /* em cada repeticação prev recebe p*/
	}
}

THING *addfront(THING *head, THING *newp) /* cria uma função ponteiro do tipo thing chamada addfront, recebe como parametro dois ponteiro do tipo thing, head e newp */
{
	newp->next = head; /* struct newp no campo next recebe head. */
	return newp;	   /* retorna newp */
}

THING *addend(THING *head, THING *newp) /*cria uma função ponteiro do tipo thing chamada addend, recebe como parametro dois ponteiro do tipo thing, head e newp */
{
	THING *p2;		  /* cria um ponteiro do tipo truct chamada p2*/
	if (head == NULL) /* se head for = a null */
		return newp;  /* retorna newp */

	for (p2 = head; p2->next != NULL; p2 = p2->next) /*repete ate encontrar o fim da lista*/
		;
	p2->next = newp; /* apos encontrar o fim da lista a struct p2 no campo next recebe newp*/
	return head;	 /* retorna head */
}

THING *addmiddle(THING *head, THING *newp) /*cria uma função ponteiro do tipo thing chamada addmiddle, recebe como parametro dois ponteiro do tipo thing, head e newp */
{
	BOOL found = FALSE;
	THING *p1, *p2;
	if (head == NULL)
	{ /* caso especial se a lista for vazia. */
		head = addfront(head, newp);
		return head;
	}
	p2 = p1 = head; /* p1 recebe head e p2 recebe p1. */
	while (!found)
	{ /* repita ate for diferente de found. "( 0 )" */
		if (found = strcmp(p1->item, newp->item) >= 1)
		{ /* se found for igual a comparação de struct campo item a struct newp campo item e a comparação maior ou igual a 1 faça */
			if (p1 == head)
			{	/* se p1 for igual a head faça */
				//					adiciona na frente
				head = addfront(head, newp);
				return (head);
			}
			else
			{

				p2->next = newp;
				;				 /* struct p2 campo next recebe newp. */
				newp->next = p1; /*struct newp no campo next recebe p1 */
				return head;
			}
		}

		if (p1->next == NULL)
		{							   // caso não encontre o inicio da lista adiciona no fim
			head = addend(head, newp); // head recebem a função  de adicionar no fim
			return (head);
		}
		// go round while loop one more time
		p2 = p1;
		p1 = p1->next;

	} // end of while
}

void printlist(THING **head)
// usa a tecnica de ponteiros duplos para imprimir a lista.
{
	THING **tracer = head; // ponteiro duplo recebe a o inicio da lista
	while ((*tracer) != NULL)
	{ /* repita ate *tracer for diferente de nulo,  seja repita até o proximo no for nulo*/
		printf("%s \n", (*tracer)->item);
		tracer = &(*tracer)->next; // agora trace recebe o endereço de memoria do proximo nó
	}
}

int main(int argc, char **argv)
{
	start = addmiddle(start, newelement("chips"));
	start = addmiddle(start, newelement("wine"));
	start = addmiddle(start, newelement("beer"));
	start = addmiddle(start, newelement("pizza"));
	start = addmiddle(start, newelement("zucchini"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("slaw"));
	printf("\nINITIAL LIST\n");
	printlist(&start);
	delelement(start, "pizza");
	delelement(start, "zucchini");
	delelement(start, "burgers");
	printf("\nALTERED LIST\n");
	printlist(&start);
}
