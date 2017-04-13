#include <stdio.h>
#include <stdlib.h>

int main(void){

	int parede[9][9] = {0};
	int vecaux[15];
	int cteste;
	int i, j, k, coluna;
	scanf("%d", &cteste);


	while(cteste > 0){
		coluna = 0;
		for(i = 0; i < 15; i++){
			scanf("%d", &vecaux[i]);			 
		}

		printf("Print vetor\n");
		for(i =0 ; i < 15 ; i++) printf("%d ", vecaux[i]);
		printf("\n");
		k = 0;

		for(i = 0 ; i < 9  ; i+= 2){
			for( j = 0  ; j < i+1 ; j+=2){
				parede[i][j] = vecaux[k];
				k++;
			}			
		}

		printf("Print matrix\n");	
		for(i = 8; i >= 0 ; i--){
			for(j = 8 ; j >=  0 ; j--){
				printf("%d\t", parede[i][j]);
			}
			printf("\n");
		}
		printf("\n");




		cteste--;
	}



	return 0;
}