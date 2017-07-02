/*
Utiliznado bfs para encontrar o menor caminho, fazendo somente os movimentos possíveis.
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <bits/stdc++.h>

#define N 8

using namespace std;

// All 8 possible movements for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
 
    return true;
}
 
struct Node{
    int x, y, dist;
    
    bool const operator==(const Node& o) const
    {
        return x == o.x && y == o.y;
    }
 
    bool operator<(const Node& o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
int BFS(Node src, Node dest){
    map<Node, bool> visited;
    
    queue<Node> q;
    q.push(src);
 
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
        
        if (x == dest.x && y == dest.y)
            return dist;
 
        if (!visited.count(node))
        {
            visited[node] = true;
 
            for (int i = 0; i < 8; ++i) 
            {
                int x1 = x + row[i];
                int y1 = y + col[i];
 
                if (valid(x1, y1))
                    q.push({x1, y1, dist + 1});
            }
        }
    }
 
    return INT_MAX;
}
int main(void){
	char ox1, dx1;
	int oy, dy;

	while(cin >> ox1 >> oy >> dx1 >> dy ){
		int ox = (ox1 == 'a')? 0 : (ox1 == 'b')? 1 : (ox1 == 'c')? 2 : (ox1 == 'd')? 3 :
		(ox1 == 'e')? 4 : (ox1 == 'f')? 5 : (ox1 == 'g')? 6 : 7;

		int dx = (dx1 == 'a')? 0 : (dx1 == 'b')? 1 : (dx1 == 'c')? 2 : (dx1 == 'd')? 3 :
		(dx1 == 'e')? 4 : (dx1 == 'f')? 5 : (dx1 == 'g')? 6 : 7;

	    Node src = {ox, oy-1};  
		Node dest = {dx, dy-1};
		cout << "To get from "<< ox1 << oy <<" to "<< dx1 << dy <<" takes "<< BFS(src, dest) <<" knight moves."<<endl;
	}

	return 0;
}