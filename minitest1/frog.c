#include <stdio.h>

int main(void){
	int alturapulo, numcanos;
	int i, j, k, ans = 1;
	j = 0; // cano anterior

	scanf("%d %d", &alturapulo, &numcanos);

	for (i = 0; i < numcanos; i ++){
		scanf("%d", &k);
		if(i > 0 ){
			if ( !(abs(k - j) <=  alturapulo )) ans = 0;		
		}
		j = k;		//atualiza o anterior
	}
	

	(ans)? printf("YOU WIN\n"):printf("GAME OVER\n");

	return 0;
}