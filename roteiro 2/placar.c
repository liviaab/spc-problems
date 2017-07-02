/*
Matricula: 2013007579
Aluna: Lívia Almeida Barbosa
Problema: PLACAR - Quem vai ser reprovado

TESTAR
Solucao:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING	20

typedef struct{
	char nome[MAX_STRING];
	int num_problemas;
} Aluno_Problemas;

int cmpfunc (const void * a, const void * b){
	int r = ((Aluno_Problemas*)(a))->num_problemas - ((Aluno_Problemas*)(b))->num_problemas;
	
	if( r == 0){
		return 	strcmp(((Aluno_Problemas*)(b))->nome, ((Aluno_Problemas*)(a))->nome);
	}
	return r;
}

int main(void) {
	int instancia = 1, num_alunos =0;
	int i;		
	scanf("%d", &num_alunos);
		
	while( num_alunos != EOF){		
		Aluno_Problemas *entrada = (Aluno_Problemas *)malloc(num_alunos*sizeof(Aluno_Problemas));
		i=0;
		while( i < num_alunos ){
			scanf("%s %d", entrada[i].nome, &entrada[i].num_problemas);
			i++;
		}
		
		qsort(entrada, num_alunos, sizeof(Aluno_Problemas), cmpfunc);

		printf("Instancia %d\n%s\n\n", instancia, entrada[0].nome);
		instancia++;
		free(entrada);
		scanf("%d", &num_alunos);	
	}	
	return 0;
}
