/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: URI 1517 - Maçãs	

Foi definida uma estrutura 'Maca' que tem três inteiros que representam as informações das 
coordenadas e o tempo que uma maçã caiu. Os dados da entrada são armazenados em um vetor de 
'Macas'. Seguindo as orientações propostas na solução da Wiki, considerou-se como subproblema 
da programação dinâmica a situação na qual Rafael começa na posição de uma maçã i, pegando-a, 
e se possível pegará as próximas, entre i+1 e K. Cria-se um vetor de inteiros que armazenará a 
resposta do problema na posição 0. As posições desse vetor são inicializadas com 1 (a cada subproblema 
da DP assume-se que Rafael pode pegar a maçã na "posição inicial") e caso seja possivel alcançar 
algum nó, é maximizado o número total de maçãs. A função que calcula o numero maximo de maçãs que 
podem ser obtidas, somente realiza essa maximização se for possível chegar do lugar i para j no tempo 
determinado.

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int XMAX, YMAX, TMAX;

typedef struct {
	int x;
	int y;
	int t;
} Maca;

void maxMacas( int nmacas, Maca posmacas[], int resposta[]){
	for( int i = nmacas - 1; i >= 0 ; i--){
		for(int j = i+1; j < nmacas + 1 ; j++){
			if( posmacas[j].t - posmacas[i].t >= 
				max( abs(posmacas[i].x - posmacas[j].x) ,
					abs(posmacas[i].y - posmacas[j].y)) ){
				resposta[i] = max(resposta[i], 1 + resposta[j]);
			}
		}
	}
}

int main(void){
int linhas, colunas, nmacasderrubadas;
	int i, j, k;
	int x, y, t, xinicial, yinicial;

	while(1){
		cin >> linhas >> colunas >> nmacasderrubadas;
		if (linhas == 0 && colunas == 0 && nmacasderrubadas == 0) break;

		Maca posmacas[nmacasderrubadas+1];
		int resposta[nmacasderrubadas+1];
		resposta[0] = 1;
		XMAX = 0; YMAX = 0; TMAX = 0;


		for( i = 1 ; i <= nmacasderrubadas ; i++){
			cin >> x >> y >> t;
			posmacas[i].x = x;
			posmacas[i].y = y;
			posmacas[i].t = t;
			resposta[i] = 1;
			XMAX = max(x, XMAX);
			YMAX = max(y, YMAX);
			TMAX = max(t, TMAX);
		}

		cin >> xinicial >> yinicial;
		posmacas[0].x = xinicial; posmacas[0].y = yinicial;
		posmacas[0].t = 0;
		maxMacas( nmacasderrubadas, posmacas, resposta );

		cout << resposta[0] - 1 << endl;
		
	}
	return 0;
}

