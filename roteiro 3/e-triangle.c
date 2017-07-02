/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: 	TRIANGLE - Triangle


Solucao: Primeiramente, foi feita uma funcao que, dadas as coordenadas, retorna se o triangulao e' 
retangulo ou nao. Na main, e' feita a leitura da entrada e verifica-se se o triangulo original e' 
retangulo. Caso nao seja, as coordenadas sao variadas de +1 e -1, para verificar se o triangulo e' 
quase retangulo. Se nao, nao e' um triangulo retangulo.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int triRet(int x1, int x2, int y1, int y2, int z1, int z2){
	float d1, d2, d3;
	d1	=  pow((x1 - y1), 2) + pow((x2 - y2),2) ;
	d2	=  pow((x1 - z1), 2) + pow((x2 - z2),2) ;
	d3	=  pow((y1 - z1), 2) + pow((y2 - z2),2) ;

	if(d1 == d2 + d3 && d3 > 0 && d2 > 0){
		return 1;
	}else if( d2 == d1 + d3 && d1 > 0 && d3 > 0){
		return 1;
	}else if( d3 == d2 + d1 && d2 > 0 && d1 >0){
		return 1;
	}
		
	return 0;
}

int main(void){
	int x1, x2, y1, y2, z1, z2;
	scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &y2, &z1, &z2);

	if(triRet(x1, x2, y1, y2, z1, z2)){
		printf("RIGHT\n");
	}else if(
		triRet(x1 + 1, x2, y1, y2, z1, z2) || triRet(x1 -1, x2, y1, y2, z1, z2) ||
		triRet(x1, x2 + 1, y1, y2, z1, z2) || triRet(x1, x2 -1, y1, y2, z1, z2) ||
		triRet(x1, x2, y1 + 1, y2, z1, z2) || triRet(x1, x2, y1 -1, y2, z1, z2) ||
		triRet(x1, x2, y1, y2 + 1, z1, z2) || triRet(x1, x2, y1, y2 -1, z1, z2) ||
		triRet(x1, x2, y1, y2, z1 + 1, z2) || triRet(x1, x2, y1, y2, z1 -1, z2) ||
		triRet(x1, x2, y1, y2, z1, z2 + 1) || triRet(x1, x2, y1, y2, z1, z2 -1)  ){
		printf("ALMOST\n");
	}else{
		printf("NEITHER\n");
	}

	return 0;
}