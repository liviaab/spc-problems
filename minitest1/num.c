#include <stdio.h>
#include <stdlib.h>
 
int cmpfunc (const void * a, const void * b)
{
   return (int)( *(long long int*)a - *(long  long int*)b );
}

int main(void){
	int n, i, achou = 0;

	while(scanf("%d", &n) && n){
		long long int *numeros;
		numeros  = (long long int* )malloc(n*sizeof(long long int));

		for(i = 0; i < n ; i ++){
			scanf("%lld", &numeros[i]);
		}

		qsort(numeros, n, sizeof(long long int), cmpfunc);

		for(i = 0; i < n; i +=2){
			
			if( numeros[i] != numeros[i+1]){
				achou = 1;
				break;
			}
		}			

		
		if(achou) printf("%lld\n", numeros[i] );
		else printf("%lld\n", numeros[i-1] );
		free(numeros);
	}

	return 0;
}