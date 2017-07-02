
/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: ENERGIA - Transmissão de Energia

Semelhante ao problema Ir e Vir, utiliza-se a busca em profundidade para verificar se todas as linhas de transmissao estao conectadas. É feita a leitura da entrada e é montado um grafo nao direcionado. O algoritmo de busca em profundidade recefe esse grafo, visita os nós possíveis e, ao final, se houver alguma torre (vértice) nao visitado, imprime-se "falha". Caso contrario, o sistema funciona e imprime-se "normal".

*/


#include <stdlib.h>
#include <stdio.h>

void DepthFirstSearch( int grafo[100][100], int no, int numVertices, int *visitados);

int main(void){
	
	int numEstacoes, numLTs;
	int x, y, n = 1;
	int i, j, k;

	scanf("%d %d", &numEstacoes, &numLTs);
	while( numEstacoes && numLTs){

		int grafo[100][100] = {0};

		for(i = 0 ; i < numLTs; i++){
			scanf("%d %d", &x, &y);
			grafo[x-1][y-1] = 1;
			grafo[y-1][x-1] = 1;			
		}

		int visitados[100] = {0};
		
		int naoachou = 0;
		for( i = 0 ; i < numEstacoes ; i++){
			DepthFirstSearch( grafo, i, numEstacoes, visitados);
			for(j = 0; j < numEstacoes ; j++){
				if(!visitados[j]){
					naoachou = 1;
				}

				visitados[j] = 0;
			}
			if(naoachou) {
				break;
			}
		}

		printf("Teste %d\n", n);
		if(naoachou){
			printf("falha\n\n");
		}else{
			printf("normal\n\n");
		}
		
		scanf("%d %d", &numEstacoes, &numLTs);
		n++;
	}
	return 0;
}

void DepthFirstSearch(int grafo[100][100], int no, int numVertices, int *visitados){
	int j;
	visitados[no] = 1;

	for(j = 0; j < numVertices; j ++){
		if( !visitados[j] && grafo[no][j] == 1 ){
			DepthFirstSearch( grafo, j, numVertices, visitados);
		}
	}
}
