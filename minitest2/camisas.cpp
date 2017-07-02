#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

#define MAXV 100

using namespace std;

/* definicao das estruturas */

struct node{
	int index, parent, cost;
};

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

void insertRelation(graph &g, string t, int vol, int nvoluntarios){
	int tam = (t == "XXL")? 6: ( t == "XL")? 5: (t == "L")? 4 : (t == "M")? 3 : ( t == "S")? 2 : 1;
/*	g.edges[nvoluntarios+vol].push_back(tam);
	g.edges[tam].push_back(nvoluntarios+vol);
	g.flow[tam][nvoluntarios+vol] = 1;*/

	g.edges[nvoluntarios+tam].push_back(vol);
	g.edges[vol].push_back(nvoluntarios+tam);
	g.flow[vol][nvoluntarios+tam] = 1;
}

int main(void){
	int ncasos, ncamisas, nvoluntarios;
	cin >> ncasos;

	while(ncasos > 0){		
		cin >> ncamisas >> nvoluntarios;
		int pesocamisa = ncamisas/6;
		
		graph g;
		init(g, (nvoluntarios+6)+2);
		
		// camisas - final
		for(int i = 1; i <= 6; i++){
			g.edges[nvoluntarios+6+1].push_back(nvoluntarios+i);
			g.edges[nvoluntarios+i].push_back(nvoluntarios+6+1);
			g.flow[nvoluntarios+i][nvoluntarios+6+1] = pesocamisa;
		}
		
		// inicio - voluntarios
		for(int i = 1; i <= nvoluntarios; i++){
			g.edges[0].push_back(i);
			g.edges[i].push_back(0);
			g.flow[0][i] = 1;
		}

		string t1, t2;		
		for(int i = 1 ; i <= nvoluntarios ; i++){
			cin >> t1 >> t2;
			insertRelation(g, t1, i, nvoluntarios);
			insertRelation(g, t2, i, nvoluntarios);
		}

		string ans = (maxFlow(g, 0, (nvoluntarios+6)+1) >= nvoluntarios)? "YES":"NO";
		cout << ans << endl; 
		ncasos--;
	}
	return 0;
}