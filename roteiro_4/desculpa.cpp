/*

KNAPSACK - The Knapsack Problem

Since suproblems are evaluated again, this problem has Overlapping Subprolems 
property. So the 0-1 Knapsack problem has both properties (see this and this)
of a dynamic programming problem. Like other typical Dynamic Programming(DP) 
problems, recomputations of same subproblems can be avoided by constructing a 
temporary array K[][] in bottom up manner. Following is Dynamic Programming 
based implementation.
*/


#include <stdio.h>
#include <iostream>
#include <limits.h>

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

// Driver program to test above function
int main(void){

  int capacity, nitems, i, teste = 0;

  while(1){

    cin >> capacity >> nitems;
    if (capacity == 0 && nitems == 0) break;

    int values[nitems], weights[nitems];
    for(i =0 ; i < nitems ; i ++){
      cin >> weights[i] >> values[i];
    }

    printf("Teste %d\n", ++teste);
    printf("%d\n\n", knapSack(capacity, weights, values, i));
  }
  
  return 0;
}