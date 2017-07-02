/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: BANDA09 - Banda

Solucao: É feita a leitura dos pares e as afinidades sao colocadas em uma "matriz de afinidades", 
que pode representar um grafo nao direcionado de afinidades. Após a leitura e preenchimento da matriz,
é feito um loop que verifica todas as possibilidades de conjunto de 3 pessoas, armazenando o que a 
soma de afinidades é maior ao longo das iteracoes.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int num_musicos, num_pares;
	int p1, p2, af;
	int mtx_mus[101][101];
	int i, j, k;
	for(i = 0; i < 101; i++)
		for(j = 0; j < 101; j++) mtx_mus[i][j] = 0;
	

	scanf("%d %d", &num_musicos, &num_pares);
	while(num_pares > 0){
		scanf("%d %d %d", &p1, &p2, &af);
		mtx_mus[p1][p2] = af;
		mtx_mus[p2][p1] = af;
		num_pares--;
	} 

	int afinidade_aux = 0;
	int afinidade_final = -1;
	int m1=0, m2=0, m3=0;

	for(i = 1; i <= num_musicos; i++){
		for(j = 1; j <= num_musicos; j++){
			for(k = 1; k <= num_musicos; k++){
				if(  i != j && i != k && j != k ){
					afinidade_aux = mtx_mus[i][j] + mtx_mus[i][k] + mtx_mus[j][k];
					
					if( afinidade_final < afinidade_aux ){ // ou menor igual
						afinidade_final = afinidade_aux;
						m1 = i ;
						m2 = j ;
						m3 = k ;
					} 
				}
			}
		}
	}

	printf("%d %d %d\n", m1, m2, m3);
	return 0;	
}
