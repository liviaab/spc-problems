/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema:METEORO - Meteoros

O preblema se resume a determinar o número de pontos que estão dentro de um retângulo.
Dados os pontos basicos que determinam o retangulo, verifica-se se os pontos do conjunto de teste se encontram no intervalo coberto por ele.
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>


int main(void){
	int supesqX, supesqY, infdirX, infdirY;
	int nmeteoritos, resultado = 0, testen = 0;
	int i, x, y;

	scanf("%d %d %d %d", &supesqX, &supesqY, &infdirX, &infdirY);
	while( supesqX != 0 &&  supesqY != 0 && infdirX != 0 && infdirY != 0 ) {
		scanf("%d", &nmeteoritos);
			
		for( i = 0; i < nmeteoritos ; i++){
			scanf("%d %d", &x, &y);

			if( x >= supesqX && x <= infdirX && y <= supesqY &&  y >= infdirY ) 
				resultado++;					
		}
		

		printf("Teste %d\n%d\n\n", ++testen, resultado);
		scanf("%d %d %d %d", &supesqX, &supesqY, &infdirX, &infdirY);
		resultado = 0;
	}
	return 0;
}
