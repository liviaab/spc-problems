#include <stdio.h>
#include <stdlib.h>

int main(void){

	int tam, i, a, b,temp, nummoves;
	while( scanf("%d", &tam) && tam){
		int vetor[100000] = {0};
		for(i = 0; i < tam; i++) scanf("%d", &vetor[i] );

		nummoves=0;
		for(i = 0; i < tam; i++){
			while( (i+1) != vetor[i] ){
    			b = vetor[i] - 1;
				temp = vetor[i];
				vetor[i] = vetor[ b ];
				vetor[b] = temp;
				nummoves = 1- nummoves;				
			}
		}
		
		if(nummoves % 2 == 0) printf("Carlos\n");
		else printf("Marcelo\n");
	}

	return 0;
}
