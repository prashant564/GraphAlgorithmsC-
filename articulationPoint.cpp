#include <bits/stdc++.h>
#define V 5
using namespace std;

/*
TC: O(V+E), SC: O(V)
To find articulation points in graph,
1) Do a DFS on graph, and find the outdegree 
	of each starting node in dfs
2) If the outdegree is 2 or more then that node is an AP
3) There are 2 more cases for node to be AP
	* If it forms a cycle
	* If its id is less than the low link value of its child node
4) Rest same as finding bridges		
*/

int children,id=0;
vector<int> adj[V];
vector<int> ids(V,-1);
vector<int> low(V,-1);
vector<bool> vis(V,false);
vector<bool> isArt(V,false);

void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int root, int v, int parent){
	if(parent==root)
		children++;
	vis[v]=true;
	id++;
	ids[v]=low[v]=id;

	for(auto it:adj[v]){
		if(it==parent) continue;
		if(!vis[it]){
			dfs(root, it, v);
			low[v]=min(low[v],low[it]);
			if(ids[v]<=low[it])
				isArt[v]=true;
		}else{
			low[v]=min(low[v],low[it]);
		}
	}
}

void findArticulationPoints(){
	// vector<int> ans;
	for(int i=0;i<V;i++){
		if(!vis[i]){
			children=0;
			dfs(i, i, -1);
			if(children > 1)
				isArt[i]=true;
		}
	}

	for(int i=0;i<V;i++)
		if(isArt[i])
			cout<<i<<" ";
}

int main(){
	addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4);
    findArticulationPoints();
}