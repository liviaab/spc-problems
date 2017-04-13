#include <stdlib.h>
#include <stdio.h>

int cmpfct(const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(void){

	int i, n = 1;
	int cteste;
	scanf("%d", &cteste);

	while ( cteste != 0 ){
		int pontuacao = 0;
		int cartas[5];

		for(i =0 ;i < 5 ; i ++) scanf("%d", &cartas[i]);
		qsort(cartas, 5, sizeof(int), cmpfct);
		
		//caso 1 - sequencia
		int sequencia = 1; 
		for(i = 0; i < 4; i++){
			if (cartas[i+1] != cartas[i] + 1){
				sequencia = 0;
			}
		}

		if(sequencia){
			pontuacao = cartas[0] + 200;
		}
		//caso 2 - quadrupla
		else{
			int quadrupla = 0;
			for(i = 0; i < 2 ; i++){
				if(cartas[0 + i] == cartas[1 + i] && cartas[1 + i] == cartas[2 + i] && cartas[2 + i] == cartas[3 + i]){
					quadrupla = 1;
				}
			}
					
			if(quadrupla){
				pontuacao = cartas[2] + 180;
			} 
			//caso 3 - trinca e par
			else{
				if(( cartas[0] == cartas[1] && cartas[1] == cartas[2] && cartas[3]== cartas[4]) || 
					( cartas[0] == cartas[1] && cartas[2] == cartas[3] && cartas[3]== cartas[4])){
					pontuacao = cartas[2]  + 160;
				}

				//caso 4 - trinca e diferente
				else{
					int trinca = 0;
					for(i = 0 ; i < 3; i++){						
						if (cartas[0 + i] == cartas[1 + i ] && cartas[ i + 1] == cartas[ i + 2]){
							trinca = 1;
						}
						if(trinca) break;
					}
						
					if (trinca) pontuacao = cartas[i] + 140;
					//caso 5 - dois pares
					else{

						if(cartas[0] == cartas[1] && cartas[2]== cartas[3]){
							pontuacao = cartas[3] * 3 + cartas[0] * 2 + 20;
						}
						else if ((cartas[0] == cartas[1] && cartas[3]== cartas[4]) || (cartas[1] == cartas[2] && cartas[3] == cartas[4])){
							pontuacao = cartas[3] * 3 + cartas[1] * 2 + 20;
						}
						
						//caso 6 - um par
						else{

							int par = 0;
							for(i = 0; i < 4 ; i++){
								if( cartas[i] == cartas[i+1]){
									par = 1;
									break;
								}
							}
							if(par) pontuacao = cartas[i];
						}
					}
				}
			}
		}		

		printf("Teste %d\n%d\n\n", n, pontuacao);
		cteste -= 1;
		n+= 1;
	}

	return 0;
}