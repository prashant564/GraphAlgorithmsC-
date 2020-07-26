#include <bits/stdc++.h>
using namespace std;

class Graph{
	int N; // no. of vertices/nodes
	list<int> *adj; //adjacency list representing the graph

	void DFSUtil(int n, bool vis[]);

public:
	Graph(int N);
	void addEdge(int n, int w);
	void DFS(int n);
	int ConnectedComponents();
};

Graph :: Graph(int N){
	this->N=N;
	adj = new list<int>[N];
}

void Graph:: addEdge(int n, int w){
	adj[n].push_back(w); //Add w to the given node's list
	adj[w].push_back(n);
}

int Graph :: ConnectedComponents(){
	int count=0;
	bool vis[N];
	memset(vis,false,sizeof(vis));

	for(int i=0;i<N;i++){
		if(vis[i]==false){
			DFSUtil(i,vis);
			count++;
		}
	}
	return count;
}


void Graph :: DFSUtil(int n, bool vis[]){
	vis[n]=true;
	// cout<<n<<" ";
	// ans.push_back(n);
	for(auto it=adj[n].begin();it!=adj[n].end();it++){
		if(!vis[*it])
			DFSUtil(*it,vis);
	}
}


void Graph :: DFS(int n){
	bool vis[N];
	memset(vis,false,sizeof(vis));
	DFSUtil(n,vis);
}


int main(){
	int size=4;
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    //STARTING_NODE=0 here
    // g.DFS(1);

    cout<<g.ConnectedComponents()<<"\n";

    return 0;
}