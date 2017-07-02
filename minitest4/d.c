#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visitados[1000];
int matriz[1000][1000];
int numvisited;

void DepthFirstSearch( int no, int numVertices){
	int j;
	visitados[no] = 1;
	numvisited++;

	for(j = 0; j < numVertices; j ++){
		if( !visitados[j] && matriz[no][j] == 1 ){
				DepthFirstSearch( j, numVertices);
		}
	}
}


int main(void){
	int nespecies, minfos, amon;
	int i, a, b;
		
	while(scanf("%d %d",&nespecies, &minfos) != EOF){
		memset(matriz, 0, sizeof(matriz));
		memset(visitados, 0, sizeof(visitados));
		numvisited = 0;

		for(i = 0; i < minfos ; i++){
			scanf("%d %d", &a, &b);
			matriz[a-1][b-1] = 1;
			matriz[b-1][a-1] = 1;
		}

		scanf("%d", &amon);

		DepthFirstSearch(amon-1, nespecies);
		printf("%d\n", numvisited);
	}	

	return 0;
}

