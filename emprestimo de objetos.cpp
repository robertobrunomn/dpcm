#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct emprestimo{
    char amigo [50];
    char objeto [50];
    char contato [50];
    char dataEmprestimo [11];
	char dataDevolucao [11];
    struct emprestimo *prox;
}EMPRESTIMO;

EMPRESTIMO *aloca(){
    return malloc(sizeof (EMPRESTIMO));
}

void inicia(EMPRESTIMO *LISTA)
{
	LISTA->prox = NULL;
}
int vazia(EMPRESTIMO *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}
int menuDevolucao(){
	int op;
    printf("Tem prazo para devolução?\n1.Sim\n2.Não\n");
    scanf("%d",&op);
}

void cadastro(EMPRESTIMO *LISTA){
    EMPRESTIMO *aux, *novo;
    aux = LISTA;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    novo=aloca();
    fflush(stdin);
    printf("Qual objeto vai emprestar?\n");
    gets(novo->objeto);
    fflush(stdin);
    printf("Digite o nome do amigo que vai receber o objeto:\n");
    gets(novo->amigo);
    fflush(stdin);
    printf ("Digite o contato do seu amigo(email e/ou telefone):\n");
    gets(novo->contato);
    fflush(stdin);
    printf("Digite a data do empréstimo (usar formato: dd/mm/aaaa):\n");
    gets(novo->dataEmprestimo);
    fflush(stdin);
    int op;
        
 	do{
 		op=menuDevolucao();
 		switch(op){
 			case 1:
 				printf ("Digite a data para devolução (usar formato: dd/mm/aaaa):\n");
 				gets(novo->dataDevolucao);
 				fflush(stdin);
 				break;
 			case 2:
 				novo->dataDevolucao[11]="Sem prazo!";
 				fflush(stdin);
 				break;
 			default:
 				printf("Digite uma opção válida!!!\n");
 				system("pause");
 				break;
		 }
	 }while(op!=1||op!=2);
    
    novo->prox=NULL;
    aux->prox=novo;
    fflush(stdin);
    system("pause");
    system("cls");
}

void consulta(EMPRESTIMO *LISTA){
    if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		system("pause");
        system("cls");
		return ;
	}

    EMPRESTIMO *tmp;
	tmp = LISTA->prox;

	while( tmp != NULL){
		printf("Amigo: %s\nObjeto: %s\nContato: %s\nData do Empréstimo: %d\n\n",tmp->amigo,tmp->objeto,tmp->contato,tmp->dataEmprestimo);
		tmp = tmp->prox;
}
system("pause");
system("cls");
}
int menu(){
int op;
printf("1 - cadastrar objeto\n2 - consultar acervo\n0 - sair\n");
 scanf("%d",&op);
 return op;
}
int main(){
    setlocale(LC_ALL,"");
    EMPRESTIMO V;
    inicia(&V);
    int op;
 do{
    op = menu();
    switch(op){
case 1:
    cadastro(&V);
    break;
case 2:
    consulta(&V);
    break;
default: printf("\nopção invalida!!!!\n");
    system("pause");
    system("cls");
    }
}while(op!=0);
}
