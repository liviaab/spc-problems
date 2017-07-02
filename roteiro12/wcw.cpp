/*

Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: WCW - Elementar, meu caro Watson!

O problema consiste em determinar o numero minimo de trocas para ordenar elementos de 1 a N.
Os elementos da entrada sao armazenados em um vetor, o qual será ordenado. Cada elemento deve
terminar na posição correspondente ( o numero 1 na posição 1, o número 2 na posição 2...). 
O loop que itera sobre o vetor sempre faz a troca do elemento que nao está na posiçao  
correspondente. Somente avança para a próxima posição do vetor caso a posição atual esteja com
o respectivo elemento. Com uma variável que é incrementada toda vez que o bloco de troca é
executado, sabe-se, ao final, quantas trocas foram realizadas.

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void){
	int numinstancias, numinteiros;
	int i, j;
	cin >> numinstancias;
	for( i = 0; i < numinstancias; i++){
		

		int vetor[10002];
		cin >> numinteiros;
		for( j = 1 ; j <= numinteiros ; j++ ){
			cin >> vetor[j] ;
		}

		int numtrocas = 0;
		int k , temp;

		//ordenando
		for( k = 1 ; k < numinteiros ; ){
			if( vetor[k] == k) k++;
			else{
               //troca
               temp = vetor[vetor[k]];
               vetor[vetor[k]] = vetor[k];
               vetor[k] = temp;

               numtrocas += 1;				
			}
		}

		cout << numtrocas << endl;
	}

	return 0;
}
