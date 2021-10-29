#include <iostream>
#include <limits.h>

using namespace std;

#define Vertex 9

int calculateMinDistance(int dist[], bool sptSet[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < Vertex; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void showResult(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < Vertex; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

void dijkstra(int graph[Vertex][Vertex], int src)
{
	int dist[Vertex]; 

	bool sptSet[Vertex]; 

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < Vertex - 1; count++) {
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < Vertex; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	showResult(dist);
}

int main()
{
	int graph[Vertex][Vertex] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}

