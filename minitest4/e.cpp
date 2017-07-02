#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

using namespace std;
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main(void){
	int m, capacidade, i;

	while(	cin >> m >> capacidade){
	int doces[m], pesos[m];

	for(i = 0; i < m ; i++){
		cin >> doces[i];		
	}

	for(i = 0; i < m ; i++){
		cin >> pesos[i];		
	}


	printf("%d\n", knapSack(capacidade, pesos, doces, m));

	}
	
	return 0;
}
