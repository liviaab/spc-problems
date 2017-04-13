#include <stdio.h>

// existe vertice = 1
// visitou = 2



typedef struct Item{
	int label;
	Item *proximo;
} Item;

typedef struct {
	
	
}Fila;

void bfs(int **grafo, int raiz, int *cidAlcancadas, int maxPedagio){
	int fila[50] = {0}, iniciofila = 0, fimfila = 0; //fila p/ o bfs
	//int indexCidAlcancadas;
	
	cidAlcancadas[0] = raiz;
	fila[0] = raiz;
	iniciofila = 0;
	fimfila = 1;



	for

}

int main(void){
	int cidades, estradas, cidAtual, maxPedagios;
	int i, j, k, n = 1;
	int x, y;

	while( scanf("%d %d %d %d", &cidades, &estradas, &cidAtual, &maxPedagios) &&
			cidades && estradas && cidAtual && maxPedagios ){
		int grafo[50][50] = {0};
		int cidAlcancadas[50] = {=};
		int numCidadesAlcandas = 0;


		for( i = 0 ; i < estradas; i++){
			scanf("%d %d", &j, &k);
			grafo[j-1][k-1] = 1;
			grafo[k-1][j-1] = 1;
		}

		bfs(grafo, cidAtual-1, cidAlcancadas, maxPedagios);

		printf("Teste %d\n",n );
		n++;		
	}

	return 0;
}