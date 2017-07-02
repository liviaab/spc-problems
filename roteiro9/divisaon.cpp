/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: NLOGONIA - Divisão da Nlogônia

O problema é identificar se um ponto está ao nordeste, noroeste, sudeste ou sudoeste de um ponto dado como referência. A primeira verificação (e a mais fácil) é saber se a cidade se encontra na divisa, ou seja, na mesma coordenada x ou y do ponto de referência. Em seguida, verifica-se se o ponto está à direita ou à esquerda da referência. Em seguida, verifica-se se ele se encontra acima ou abaixo. De acordo com a posição, a resposta correspondente é impressa.

*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void){

	int nconsultas;
	int pdivX, pdivY;
	int resX, resY;
	cin >> nconsultas;
	while(nconsultas > 0){
		cin >> pdivX >> pdivY;

		while( nconsultas > 0){
			cin >> resX >> resY ;
			
			if (resX == pdivX || resY == pdivY) cout << "divisa" << endl;
			else if ( resX - pdivX > 0 ){
				if(resY - pdivY > 0) cout << "NE" << endl;
				else cout << "SE" << endl;
			}else{
				if(resY - pdivY > 0) cout << "NO" << endl;
				else cout << "SO" << endl;
			}
			nconsultas--;
		}
		cin >> nconsultas;	
	}

	return 0;
}
