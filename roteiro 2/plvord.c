/*
Nome: Lívia Almeida Barbosa
Matrícula: 2013007579
Problema: PALAVRMG - Palavras Ordenadas

OK
Solução:

*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define	MAX_BUFFER	42
#define P_MAX		30
#define	true		1
#define	false		0

int main(void){
	int i = 0,j = 0, num_words = 0;
	int ord = true;

	scanf("%d", &num_words); 
	char **input_matrix = (char **) malloc(num_words * sizeof(char*));
	for(i=0; i < num_words; i++) input_matrix[i] = (char*) malloc(MAX_BUFFER*sizeof(char));

	while(num_words > 0){		
		scanf("%s", input_matrix[j] );		
		j++;		
		num_words--;
	}

	while(num_words < j ){
		for(i = 1; input_matrix[num_words][i] != '\0' ; i++){
			if( tolower(input_matrix[num_words][i]) <= tolower(input_matrix[num_words][i-1]) ){				
				ord = false;
				break;				
			}				
		}		

		printf("%s: %c\n", input_matrix[num_words], (ord)?'O':'N' );
		num_words++;
		ord = true;
	}

	for( i =0 ; i < num_words ; i++) free(input_matrix[i]);
	free(input_matrix);
	
	return 0;
}