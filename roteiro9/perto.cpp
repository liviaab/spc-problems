/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema:PARPROX - Pontos

Dados vários pontos no plano, deve-se determinar a distância do par de pontos mais próximos.
O algoritmo implementado é da ordem de O(n^2), já que calcula a distância entre todos os pares de pontos (armazenados em uma lista), sempre armazenando a menor distância entre todas encontrada. 

*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>


//using namespace std;

int main(void){
	int npontos, i, j;
	long int x, y;
	long int listapontos[1000][2];
	float min = DBL_MAX, auxmin = DBL_MAX;

	scanf("%d", &npontos);
	for(i = 0 ; i < npontos ; i++) {
		scanf("%ld %ld", &listapontos[i][0], &listapontos[i][1]);
	} 

	for( i = 0 ; i < npontos -1 ; i++){
		for(j = i+1; j < npontos ; j++){

			auxmin = (float) sqrt( (float)( (float)(listapontos[i][0] - listapontos[j][0])*(float)(listapontos[i][0] - listapontos[j][0]) ) + 
				       (float)( (float)(listapontos[i][1] - listapontos[j][1])*(float)(listapontos[i][1] - listapontos[j][1]) ) );

			if ( auxmin < min ) min = auxmin;
			
		}
	}
	
	printf("%.3f\n", min);
	return 0;
}
