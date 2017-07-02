/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: CANDY - Candy I

Solução: É feita a leitura e calculada a média da quantidade de balas por pacote. 
Em seguida, é medida a distância entre a média e a quantidade de balas em cada pacote
e conta-se os movimentos. Um movimento é tirar a bala de um pacote e colocar em outro. 
Assim, se a quantidade de balas movidas entre os pacotes terminar em 0, significa que 
todos os pacotes podem ter um numero igual de balas.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num_cpck, i, mean, count, moves ;
	int arr_cpck[10001];
	scanf("%d", &num_cpck);
	
	while (  num_cpck != -1 ){
		mean= 0; count=0; moves = 0;
		
		for(i=0; i < num_cpck; i++){
			scanf("%d", &arr_cpck[i]);
			mean += arr_cpck[i];
		}

		mean /= num_cpck;
		for(i = 0 ; i < num_cpck; i++){			
			if( mean > arr_cpck[i]){
				count += mean - arr_cpck[i];
				moves += mean - arr_cpck[i];
			}else{
				count -= arr_cpck[i] - mean;
			}
		}
		if(count == 0 ) printf("%d\n", moves);
		else printf("-1\n");
		scanf("%d", &num_cpck);
	}
	return 0;
}