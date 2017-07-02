#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
using namespace std;

int minKey(int key[], bool mstSet[], int numVertices){
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < numVertices; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
void primMST(int graph[1000][1000], int *parent, int numVertices){
     int key[numVertices];   
     bool mstSet[numVertices];  
 
     for (int i = 0; i < numVertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     key[0] = 0;     
     parent[0] = -1; 
 
     for (int count = 0; count < numVertices-1; count++){
        int u = minKey(key, mstSet, numVertices);
 
        mstSet[u] = true; 
        for (int v = 0; v < numVertices; v++)
          if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
}
 


int main(void){
	int nesquinas, nruas;

	while(1){
		cin >> nesquinas >> nruas;
		if (nesquinas == 0 && nruas == 0) break;

		int grafomax[1000][1000];
		int grafomin[1000][1000];
		memset(grafomin, 0, sizeof(grafomin[0][0])*1000*1000);
		memset(grafomax, 0, sizeof(grafomax[0][0])*1000*1000);

		int a, b, c;
		for( int i = 0 ; i < nruas ; i++){
			cin >> a >> b >> c;
			grafomax[a-1][b-1] = -c;
			grafomax[b-1][a-1] = -c;
			grafomin[a-1][b-1] = c;
			grafomin[b-1][a-1] = c;
		}

		int parent[nesquinas], sum1, sum2;		
		memset(parent, -1, sizeof(parent[0])*nesquinas);	

		primMST(grafomin, parent, nesquinas);
		sum1 = 0;
		for(int i = 1; i < nesquinas; i++){
			sum1 += grafomin[i][parent[i]];
		}
		primMST(grafomax, parent, nesquinas);
		sum2 = 0;
		for(int i = 1; i < nesquinas; i++){
			sum2 += grafomax[i][parent[i]];
		}

		cout << (-sum2) - sum1 << endl;
	}
	return 0;
}