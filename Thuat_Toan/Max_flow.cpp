#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
//So dinh cua do thi
#define V 6
 
/*tra ve true neu co duong di, duong di luu trong parent[] */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
   //tao mang danh dau da di qua,mac dinh la 0
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
	//Tao hang doi danh dau dinh 's' la dinh bat dau
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
 
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    int rGraph[V][V];
              
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; //Luu tru duong di
 
    int max_flow = 0;
 
    while (bfs(rGraph, s, t, parent)) {
		////tim min cua luong
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

		// cap nhat dung luong cua luong
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
 

    return max_flow;
}
 
int main()
{
    int graph[V][V]
        = { { 0, 5, 0, 15, 0, 0}, { 0, 0, 10, 0, 5, 0},
            { 0, 0, 0, 3, 0, 20 }, { 0, 5, 0, 0, 0, 5},
            { 0, 0, 2, 0, 0, 5}, { 0, 0, 0, 0, 0, 0},
			
			 };
 
    cout << "Luong cuc dai: "
         << fordFulkerson(graph, 0, 5);
 
    return 0;
}
