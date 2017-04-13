#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j, acabou, numtestes = 0, numinv, trocou, temp ;
	scanf("%d", &numtestes);
	char blank;
	blank = getchar();

	int tamvetor;

	while(numtestes > 0){
		int vetor[200001];
		numinv = 0;

		scanf("%d", &tamvetor);
		for(i = 0; i < tamvetor; i++){
			scanf("%d", &vetor[i]);
		}
		blank = getchar();

		int numinv = 0;
		for (i = 0; i < tamvetor - 1; i++){
			for (j = i+1; j < tamvetor; j++){
				if (vetor[i] > vetor[j]) numinv++;
			}
		}

		printf("%d\n", numinv );
		numtestes--;
	}

	return 0;
}