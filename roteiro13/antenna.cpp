/*
    Nome: Livia Almeida Barbosa
    Matricula: 2013007579
    Problema:  10349 - Antenna Placement

     
    O "mapa" da entrada é lido e armazenado de uma forma modificada, com numeros nos 
    lugares dos pontos de interesse, em ordem crescente e aumentado à medida que mais 
    pontos aparecem. Existe uma variável que é incrementada a cada '*' encontrado, que 
    serve para armazenar o "mapa modificado" e, ao mesmo tempo, indicar a quantidade de 
    pontos de interesse que existem. 
    Em seguida, o grafo bipartido e bidirecionado que representa o problema, é montado a partir do mapa.
    É aplicado o algoritmo de Edmonds Karp para encontrar o fluxo máximo do grafo.
    A resposta apresentada é a quantidade de pontos de interesse menos o fluxo máximo, que
    é o maior conjunto independente do grafo.

*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
 
#define MAXV  400 // the maximum number of vertices
 
using namespace std;
 

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
  

int main(void){
    int nscenarios, hlines, wmaxpoints;
    int i, j;
    char x, b;

    cin >> nscenarios;
    while(nscenarios > 0){
        cin >> hlines >> wmaxpoints;
        int map[40][10];
        int narestas=0;

        string line;
        for(i = 0 ; i < hlines; i++){
            cin >> line;
            for(j = 0 ; j < wmaxpoints ; j++){
                if(line[j] == '*'){
                    map[i][j] = ++narestas;
                }else{
                    map[i][j] = 0;
                }
            }
        }

        graph g;
        init(g, narestas+2);
        bool ligarInicio; 

        for(i = 0; i < hlines; i++){

            ligarInicio = !(i%2);
            for( j = 0 ; j < wmaxpoints; j++){
                int v = map[i][j];
                if( v != 0){
                    if( ligarInicio ){
                        g.edges[0].push_back(v);
                        g.edges[v].push_back(0);
                        g.flow[0][v] = 1;
                        g.flow[v][0] = 1;
                    }else{
                        g.edges[narestas+1].push_back(v);
                        g.edges[v].push_back(narestas+1);
                        g.flow[narestas+1][v] = 1;
                        g.flow[v][narestas+1] = 1;
                    }

                    //direita
                    if( j+1 < wmaxpoints && map[i][j+1] != 0 ){ 
                        g.edges[v].push_back( map[i][j+1] );
                        g.edges[map[i][j+1]].push_back(v);
                        g.flow[v][map[i][j+1]] = 1;
                        g.flow[map[i][j+1]][v] = 1;
                    }

                    // pra baixo
                    if( i + 1 < hlines && map[i+1][j] != 0){
                       g.edges[v].push_back(map[i+1][j]);
                        g.edges[map[i+1][j]].push_back(v);
                        g.flow[v][map[i+1][j]] = 1;
                        g.flow[map[i+1][j]][v] = 1;
                    }
                }

                ligarInicio = !ligarInicio;
            }            
        }
        
        cout << narestas - maxFlow(g, 0, (narestas)+1) << endl; 
        nscenarios--;
    }

    return 0;
}
 