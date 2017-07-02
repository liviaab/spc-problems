/*
Matricula: 2013007579
Aluna: Lívia Almeida Barbosa
Problema: ALIENSMG - Alienígenas

Solucao:

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpbase(char a, char b){
	if( a > b) return 1;
	if( a < b) return -1;
	return 0;
}

void ordenabase( char *base){
	
}

int main(void) {
	int c_teste;
	int i;
	char **ind_mtx;

	scanf("%d", &c_teste);
	while(c_teste != 0){
		ind_mtx = (char**) malloc (c_teste * sizeof(char*));
		for (i =0 ; i < c_teste ; i++){
			ind_mtx[i] = (char*) malloc (100 *sizeof(char));
		}			


		for (i =0 ; i < c_teste ; i++){
			scanf("%s", ind_mtx[i]);
		}	



		scanf("%d", &c_teste);
	}
	
	return 0;
}