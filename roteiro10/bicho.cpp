/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: BICHO - Jogo do bicho

É feita a leitura da entrada e para cada numero apostado e sorteado é verificado se os 
quatro, três ou dois ultimos digitos sao iguais ou então se fazem parte do mesmo grupo. 
Em cada uma das funções que calcula a quantidade de digitos iguais, é feita uma verificação para que, se um numero tiver mais digitos que o outro, os dígitos "extra"
serão comparados com zero.

*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

bool last4digits(int a, int b){
	int a1, b1, a2, b2, a3, b3, a4, b4;
	a1 = a%10;
	b1 = b%10;
	a2 = (a%100) - a1;
	b2 = (b%100) - b1;
	a3 = (a%1000) - a2;
	b3 = (b%1000) - b2;
	a4 = (a%10000) - a3;
	b4 = (b%10000) - b3;
	if( a2 < 0 ) a2 = 0;
	if( b2 < 0 ) b2 = 0;
	if( a3 < 0 ) a3 = 0;
	if( b3 < 0 ) b3 = 0;
	if( a4 < 0 ) a3 = 0;
	if( b4 < 0 ) b3 = 0;
	
	if(a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4) return true;
	 return false;	
}


bool last3digits(int a, int b){
	int a1, b1, a2, b2, a3, b3;
	a1 = a%10;
	b1 = b%10;
	a2 = (a%100) - a1;
	b2 = (b%100) - b1;
	a3 = (a%1000) - a2;
	b3 = (b%1000) - b2;
	if( a2 < 0 ) a2 = 0;
	if( b2 < 0 ) b2 = 0;
	if( a3 < 0 ) a3 = 0;
	if( b3 < 0 ) b3 = 0;
	
	if(a1 == b1 && a2 == b2 && a3 == b3) return true;
	return false;	
}

bool last2digits(int a, int b){
	int a1, b1, a2, b2;
	a1 = a%10;
	b1 = b%10;
	a2 = (a%100) - a1;
	b2 = (b%100) - b1;
	if( a2 < 0 ) a2 = 0;
	if( b2 < 0 ) b2 = 0;

	if(a1 == b1 && a2 == b2 ) return true;
	return false;	
}

bool samegroup(int a, int b){
	int a2, b2, i;
	a2 = (a%100) ;
	b2 = (b%100) ;
	if( a2 == 00 ) a2 = 100;
	if( b2 == 00 ) b2 = 100;

	if( a2 < 0 ) a2 = 0;
	if( b2 < 0 ) b2 = 0;
	for(i = 1; i <= 100 ; i+= 4){
		if( (a2 == i || a2 == i+1 || a2 == i+2 || a2 == i+3) && (b2 == i || b2 == i+1 || b2 == i+2 || b2 == i+3) ) return true;
	}
	return false;
}

int main(void){
	double aposta, valorfinal = 0.0;
	int numapostado, nsorteado;
	
	while(1){
		std::cin >> aposta >> numapostado >> nsorteado;
		if( aposta == 0.0 && numapostado == 0 && nsorteado == 0) break;
	
		( last4digits(numapostado, nsorteado) )? valorfinal = aposta*3000.0 : 
		( last3digits(numapostado, nsorteado) )? valorfinal = aposta*500.0 :
		( last2digits(numapostado, nsorteado) )? valorfinal = aposta*50.0 : 
		( samegroup(numapostado, nsorteado) )? valorfinal = aposta*16.0 : valorfinal = 0.0;

		printf("%.2f\n", valorfinal);
	}

	return 0;
}
