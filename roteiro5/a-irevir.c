/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: IREVIR - Ir e vir

É feita a leitura da entrada e as intersecoes sao representadas em uma matriz de adjacencias. Caso seja de mao dupla, são inseridas arestas de u para v e de v para u.
Em seguida, executa-se o algoritmo de busca em profundidade para verificar se o requisito de conexidade é satisfeito ou não. Se todos os vértices forem visitados, o requisito é satisfeito. 
*/


#include <stdlib.h>
#include <stdio.h>

int grafo[2001][2001] = {0};			

//mudei pra void 
void DepthFirstSearch( int no, int numVertices, int *visitados){
	int j;
	visitados[no] = 1;

	for(j = 0; j < numVertices; j ++){
		if( !visitados[j] && grafo[no][j] == 1 ){
				DepthFirstSearch( j, numVertices, visitados);
		}
	}
}


int main(void){	
	int numIntersecoes, numRuas, resultado = 1;
	int v, w, p;
	int i, j, k;

	scanf("%d %d", &numIntersecoes, &numRuas);


	while( numIntersecoes && numRuas){
		for (i = 0; i < numIntersecoes; i++){
			for (j = 0; j < numIntersecoes; j++){
				grafo[i][j] = 0;
			}
		}

		for(i = 1 ; i <= numRuas; i++){
			scanf("%d %d %d", &v, &w, &p);
			grafo[v-1][w-1] = 1;			
			if(p == 2) grafo[w-1][v-1] = 1;
		}

		int visitados[2000] = {0};
		
		int naoachou = 0;
		for( i = 0 ; i < numIntersecoes ; i++){

			DepthFirstSearch( i, numIntersecoes, visitados);
			for(j = 0; j < numIntersecoes ; j++){
				if(!visitados[j]) naoachou = 1;
				visitados[j] = 0;
			}
			if(naoachou) break;
		}


		printf("%d\n", !naoachou );
		scanf("%d %d", &numIntersecoes, &numRuas);
	}
	return 0;
}
