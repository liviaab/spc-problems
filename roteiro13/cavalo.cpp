/*
    Nome: Livia Almeida Barbosa
    Matricula: 2013007579
    Problema:  CAVALOS - A lei vai a Cavalo!

    A entrada é lida de forma que o grafo montado é bipartido. 
    Os numeros que representam os soldados estão no intervalo [1 ,n] 
    e os que representam os cavalos, de [n+1, n+m]. Todos os soldados
    são conectados ao vértice "0" com peso 1, todos os cavalos são conectados ao 
    vértice "n+m+1" com peso igual à sua respectiva capacidade, e todos os 
    cavalos e soldados que têm afinidade são conectados com arestas de peso 1. 
    Assim, modificando-se o problema para esse formato, pode-se resolvê-lo como 
    um problema de atribuição. Foi aplicado o algoritmo de Edmonds Karp do vertice 0 ao 
    vértice n+m+1 para encontrar o fluxo máximo do grafo. 

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
 
#define MAXV 210 // the maximum number of vertices
 
using namespace std;
 
/* definicao das estruturas */
 
struct node{
    int index, parent, cost;    
};
 
/*
   O grafo aqui usa lista de adjacencia para as arestas,
   porem usa matriz de adjacencia para manter os fluxos.
 
   Poderia usar matriz de adjacencia para as arestas também,
   mas deixa a bfs lenta.
*/
 
struct graph{
    vector<int> edges[MAXV];
    node nodes[MAXV];
    int flow[MAXV][MAXV];
    int size;
};
 
bool bfs(graph &g, int a, int b = -1){
    queue< node > q;
    vector<bool> mark(g.size, false);
    q.push(g.nodes[a]);
    
    while (!q.empty()){
        node v = q.front();
        q.pop();
        if (mark[v.index]) continue;
        mark[v.index] = true;
        g.nodes[v.index] = v;
        if (v.index == b) return true;
        for (int i = 0; i < g.edges[v.index].size(); ++i){
            int j = g.edges[v.index][i];
            if (!mark[j] && g.flow[v.index][j] > 0){
                node tmp = g.nodes[j];
                tmp.cost = v.cost+1;
                tmp.parent = v.index;
                q.push(tmp);
            }
        }
    }
    return false;
}
 
/* inicializacao do grafo quanto ao numero de vertices */ 
void init(graph &g, int v){
    g.size = v;
    for (int i = 0; i < v; ++i){
        g.edges[i].clear();
        g.nodes[i].index = i;
        g.nodes[i].parent = -1;
        g.nodes[i].cost = 0;
        for (int j = 0; j < v; ++j) 
            g.flow[i][j] = 0;
    }
}
 
int path_min_capacity(graph &g, int source, int sink){
    node actual = g.nodes[sink];
    int min_capacity = INT_MAX;
 
    while (actual.parent != -1){
        min_capacity = min(min_capacity, g.flow[actual.parent][actual.index]);
        actual = g.nodes[actual.parent];
    }
 
    return min_capacity;
}
 
void path_augment(graph &g, int source, int sink, int min_capacity){
    node actual = g.nodes[sink];
 
    while (actual.parent != -1){
        g.flow[actual.parent][actual.index] -= min_capacity;
        g.flow[actual.index][actual.parent] += min_capacity;
        actual = g.nodes[actual.parent];
    }
}
 
/* EDMONDS KARP (fluxo máximo) */
int maxFlow(graph &g, int source, int sink){
    int result = 0, tmp = 0;
    while (true){
        if (!bfs(g, source, sink)) break;
        tmp = path_min_capacity(g, source, sink);
        result += tmp;
        path_augment(g, source, sink, tmp);
    }
    return result;
}
 
/*
    vertices 
    1 - n = soldados
    n+1 - n+m  = cavalos
*/

graph g; 
int main(void){
    int n, m, a, k = 0;
    int i, aux, u, v;
    char b;
    while( scanf("%d %d %d", &n, &m, &a) != EOF ){
        scanf("%c", &b);
        init(g, (m+n)+2);

        //capacidade dos cavalos
        for( i = 1; i <= n ; i++){
            scanf("%d", &aux);
            scanf("%c", &b);
            g.edges[m+n+1].push_back(m+i);
            g.edges[m+i].push_back(m+n+1);
            g.flow[m+i][m+n+1] = aux;
        }

        
        for(i = 0 ; i < a; i++){
            // afinidade: cavalo - soldado
            scanf("%d %d", &u, &v);
            scanf("%c", &b);
            g.edges[0].push_back(v);
            g.edges[v].push_back(0);
            g.flow[0][v] = 1;

            g.edges[m+u].push_back(v);
            g.edges[v].push_back(m+u);
            g.flow[v][m+u] = 1;
        }

    
        cout << "Instancia " << ++k << endl;
        cout << maxFlow(g, 0, (n+m)+1) << endl; //rode o fluxo entre o source e o sink
        cout << endl;
    }
 
    return 0;
}
 