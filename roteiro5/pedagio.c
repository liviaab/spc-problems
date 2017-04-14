#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int inicio, fim, tamanho;
	int itens[10000];	
}Fila;

void criaFila( Fila *f){
	f->inicio = 0;
	f->fim = 0;
	f->tamanho = 0;
	int i;
	for(i = 0 ; i < 5001 ; i++)	f->itens[i] = 0;
}
int vazia(Fila *f){
	return (f->tamanho == 0)? 1:0;
}
int cheia(Fila *f){
	if (f->tamanho == 5000) return 1;
	return 0;
}
int tamanho(Fila *f){
	return f->tamanho;
}
int coloca(Fila *f, int elem){
	if( cheia(f) == 0 ){
		f->itens[f->fim] = elem;
		f->fim++;
		f->tamanho++;
		return 1;
	}
	return -1;
}

int retira(Fila *f){
	if( vazia(f) == 0 ){
		int r;
		f->tamanho--;
		r = f->itens[f->inicio];
		f->inicio++;
		return r;
	}
	return -1;
}

void bfs(int grafo[][50], int numVertices, int raiz, int *cidAlcancadas, int maxPedagio){	
	int visitados[50] = {0};
	int aux, i, j=0, auxMP;

	Fila fila;
	criaFila(&fila);

	visitados[raiz] = 1;
	coloca(&fila, raiz);

	while( maxPedagio >= 0 ){
		aux = retira(&fila);
		for(i = 0; i < numVertices; i++){
			if(grafo[aux][i] ==1 && !visitados[i]){
				visitados[i] = 1;
				coloca(&fila, i);
				
				cidAlcancadas[j] = i+1;
				j++;
			}
		}
		maxPedagio--; //"numero de pulos"
	}
}

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(void){
	int cidades, estradas, cidAtual, maxPedagios;
	int i, j, k, n = 1;
	int x, y;

	while( scanf("%d %d %d %d", &cidades, &estradas, &cidAtual, &maxPedagios) && cidades && estradas && cidAtual && maxPedagios ){
		int grafo[50][50] = {0};
		int cidAlcancadas[50] = {0};
		int numCidadesAlcandas = 0;


		for( i = 0 ; i < estradas; i++){
			scanf("%d %d", &j, &k);
			grafo[j-1][k-1] = 1;
			grafo[k-1][j-1] = 1;
		}

		bfs(grafo,cidades,cidAtual-1, cidAlcancadas, maxPedagios);

		for( numCidadesAlcandas = 0; cidAlcancadas[i] != 0; numCidadesAlcandas++); //contar qts cidades alcancadas tem
		
		printf("Teste %d\n",n );
		qsort(cidAlcancadas, numCidadesAlcandas, sizeof(int), cmpfunc);
		for( j = 0; j < numCidadesAlcandas ; j++){
			printf("%d", cidAlcancadas[j]);
			(j+1 == i)? printf("\n\n"): printf(" ");
		}

		n++;		
	}

	return 0;
}