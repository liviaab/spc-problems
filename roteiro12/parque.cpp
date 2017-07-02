/*

Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: PARQUE - Parque Jurassico

De acordo com as orientações proposta na solução do problema, foi aplicado o algortimo de 
Longest Common Subsequence (LCS) para, primeiramente, encontrar a substring que representa a 
interseção das strings de entrada.
A impressão da menor string que contem as strings de entrada como subsequencia é feita 
seguindo um loop que repete os passos:
"-Adicionando todos os elementos de S2 e S1 que estão antes do elemento de P (interseção)
- Adicionando os elementos de P"

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

int common[101][101];

int lcs (char *a, char *b){
	for (int i=0; i<=strlen(a); i++){
		for (int j=0; j<=strlen(b); j++){

			if (i == 0 || j == 0){
				common[i][j] = 0;
			}
			else if (a[i-1] == b[j-1]){
				common[i][j] = 1 + common[i-1][j-1];
			}
			else{
				common[i][j] = max (common[i-1][j], common[i][j-1]);
			}
		}
	}

	return common[strlen(a)][strlen(b)];
}

void printUnion(char *a, char *b){
	int m = strlen(a);
	int n = strlen(b);
	int index = common[m][n];
	
	char lcs[index+1];
	lcs[index] = '\0'; 
	

	int i = m, j = n;
	while (i > 0 && j > 0)	{
	   if (a[i-1] == b[j-1]){
	       lcs[index-1] = a[i-1];
	       i--; j--; index--;    
	   }
	
	   else if (common[i-1][j] > common[i][j-1])
	      i--;
	   else
	      j--;
	}

	// imprimindo s1, s2, P
	int p = 0 , q = 0;
	for( int i = 0 ; i < strlen(lcs) ; i++){
		while( a[p] != lcs[i] ){
			cout << a[p];
			p++;
		}
		while( b[q] != lcs[i] ){
			cout << b[q];
			q++;
		}

		// ja vai ser igual
		if(a[p] == lcs[i] && b[q] == lcs[i]){
			cout << lcs[i];
			p++;
			q++;
		}
	}
	// o restante de cada string
	while( p < strlen(a) ){
		cout << a[p];
		p++;
	}
	while(q < strlen(b) ){
		cout << b[q];
		q++;
	}
}


int main(void){
	int n = 0;

	while(1){
		char S1[101], S2[101];
		//memset(common, 0, sizeof(common	[0][0])*101*101);
		//memset(S1, '\0', sizeof(S1[0])*101);
		cin >> S1;
		if ( S1[0] == '#') break;
		cin >> S2;

		lcs(S1, S2);

		cout << "Teste " << ++n << endl;

		printUnion(S1, S2);

		printf("\n\n");
	}

	return 0;
}