/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: ONZE - Você pode dizer 11

A leitura da entrada é feita considerando o número como uma string, já que é necessário imprimir os zeros à esquerda na resposta final. Foi implementado o critério de divisibilidade por 11 descrito na solucao proposta pelo site da WikiMaratona do DCC. Soma-se todos os algarismso de posições pares (somapar) e todos os algarismos de posições ímpares (somaimpar).  Se o resultado da diferença entre (somaimpar-somapar) for múltiplo de 11, então o número é um múltiplo.

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

int main(void){
	string  a;
	cin >> a;
	while(1){	
		int somaimpar = 0, somapar =0;

		if( a.length() == 1 && a[0]-48 == 0) break;

		for(int i = 0; i < a.length() ; i++){
			if(i %2 == 0){
				somapar += a[i]-48;
			}else{
				somaimpar += a[i]-48;
			}
		}

		int diferenca = somaimpar - somapar ;
		if(  diferenca%11 == 0){
			cout << a << " is a multiple of 11.\n";
		}
		else{
			cout << a << " is not a multiple of 11.\n";
		}

		cin >> a;
	}
	return 0;
}
