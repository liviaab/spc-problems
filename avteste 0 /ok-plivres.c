#include <stdio.h>
#include <stdlib.h>

int main(void){
	int largura, altura, nsubpartes;
	int x1, y1, x2, y2, i, j, k, min, max, min2, max2;

	while(scanf("%d %d %d", &largura, &altura, &nsubpartes)  && 
		!(largura == 0 && altura == 0 && nsubpartes == 0 ) ){

		int numcheios = 0, numvazios =0;
		int tabuleiro[500][500] = {0};
		
		for(k = 0 ; k < nsubpartes; k++){
			scanf("\n%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--; y1--; x2--; y2--;

			min = (y1 < y2)? y1 : y2;
			max = (y1 >= y2)? y1 : y2;
			min2 = (x1 < x2)? x1: x2;
			max2 = (x1 >= x2)? x1: x2;
			for(i = min; i <= max ; i++){
				for(j = min2 ; j <= max2 ; j++){
					if(tabuleiro[j][i] == 0){
						tabuleiro[j][i] = 1;
						numcheios++;
					}
					
				}
			}
		}

	/*	printf("Print matrix\n");	
		for(i = 0; i < altura ; i++){
			for(j = 0 ; j < largura ; j++){
				printf("%d ", tabuleiro[i][j]);
			}
			printf("\n");
		}
		printf("\n");
*/
/*		for(i = 0; i < altura ; i++){
			for(j = 0 ; j <  largura ; j++){
				if(tabuleiro[i][j] == 0 ) numvazios++;
			}
		}*/

		numvazios = altura * largura - numcheios;
		if( numvazios == 0){
			printf("There is no empty spots.\n");
		}else if( numvazios == 1){
			printf("There is one empty spot.\n");
		}else{
			printf("There are %d empty spots.\n", numvazios);
		}

	}

	return 0;
}