/*

Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: CAIXAS - Desempilhando caixas

Durante a leitura da entrada, apenas armazena-se o numero de caixas por pilha e, 
quando a caixa 1 é indicada, armazena-se em qual pilha e altura ela está (P1 e A1). Em seguida,
faz-se a soma das caixas das pilhas que estão antes de P1, mas apenas daquelas que estao 
na mesma altura ou acima de A1. Caso seja encontrada uma pilha mais baixa qeu A1, o somatorio é 
finalizado. A mesma coisa é feita para as pilhas que estão depois de P1 e imprime-se o resultado
do somatório de valor mais baixo.

*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void){
	int ncaixastotal, npilhas, ncaixasppilha, idcaixa;
	int i, j, pilhacx1, alturacx1, somaant, somapost;
	

	while(1){

		cin >> ncaixastotal >> npilhas;
		
		if( ncaixastotal == 0 && npilhas == 0) break;
		
		int qtdes[npilhas] = {0} ;
		pilhacx1 = 0;

		//leitura da entrada
		for( i = 0 ; i < npilhas; i++){
			cin >> ncaixasppilha;	

			qtdes[i] = ncaixasppilha;			
			for( j = 0 ; j < ncaixasppilha;j++){
				cin >> idcaixa;
				if(idcaixa == 1) {
					pilhacx1 = i;
					alturacx1 = j+1;
				}
			}
		}

		//processamento
		somaant = qtdes[pilhacx1] - alturacx1;
		somapost = qtdes[pilhacx1] - alturacx1;

		for( i = pilhacx1 -1  ; i >=0 ; i--){
			if( qtdes[i] >= alturacx1 ) somaant += (qtdes[i] - alturacx1)+1;
			else break;
		}

		for( i = pilhacx1 + 1; i < npilhas ; i++){
			if( qtdes[i] >= alturacx1 ) somapost += (qtdes[i] - alturacx1)+1;
			else break;
		}

		cout << min(somaant, somapost) << endl;

	}	

	return 0;
}