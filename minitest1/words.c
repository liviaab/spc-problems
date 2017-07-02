#include <stdio.h>
#include <string.h>

typedef struct P{
	char palavra[50];
	int tamanho;
}P;

void insereOrdenado(P palavras[50], char aux[50], int numPalavrasAteAgr){
	int tamNova = strlen(aux);
	if(numPalavrasAteAgr == 0){
		strcpy(palavras[0].palavra, aux);
		palavras[0].tamanho = tamNova;
		return; 
	}

	int i, j, inseriu = 0;
	for(i = 0; i < numPalavrasAteAgr ; i++){
		if( tamNova > palavras[i].tamanho ){
			// se o tamanho da nova for maior do que a atual, a nova deveria estar nesse lugar
			for (j = (numPalavrasAteAgr - 1); j >= i; j--){
				strcpy(palavras[j+1].palavra, palavras[j].palavra);
				palavras[j+1].tamanho = palavras[j].tamanho;
			}
			strcpy(palavras[i].palavra, aux);
			palavras[i].tamanho = tamNova;
			inseriu = 1;
			break;
		}
	}
	if(!inseriu){
		strcpy(palavras[numPalavrasAteAgr].palavra, aux);
		palavras[numPalavrasAteAgr].tamanho = tamNova;
	}
	return;

}

int main(void){
	int casos, i, j, numPalavrasAteAgr;
	char k;

	scanf("%d", &casos);
	scanf("%c", &k);

	while(casos){
		P palavras[50];
		char aux[50];
		i = 0; j = 0; numPalavrasAteAgr = 0;

		while(1){   
			scanf("%s", aux);
			scanf("%c", &k); // branco ou new line
			if( k == ' ' || k == '\n'){	
				insereOrdenado(palavras, aux, numPalavrasAteAgr);
				numPalavrasAteAgr++;
				i++;
				j = 0;
			}
			if(  k == '\n' )break;
		}
		
		int x;
		for( x = 0; x < i ; x++){
			if ( x != (i -1)) printf("%s ", palavras[x].palavra );
			else  printf("%s\n", palavras[x].palavra );
		}
		
		casos--;
	}

	return 0;
}
