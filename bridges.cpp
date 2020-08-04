#include <bits/stdc++.h>
#define V 5
using namespace std;


/*
TC: O(V+E), SC:O(V)
To find bridges in a graph,
1) For all univisted nodes do a DFS with updating the id 
	value at each call.
2) Initially the low link value of a node will be its id
3) While traversing to other nodes, check if the current 
	node is not parent, if yes then move to the next node
4) If current node has been already visited, then find the min 
	between the low link values of the current node and the node 
	whose edges we are traversing
5) If not visited, then find min bet. ll values and check for the BRIDGES CONDITION
6) BRIDGES CONDITION- if(ids[from]<low[current]), then it's a bridge	
*/


int id=0;
vector<int> adj[V];
vector<int> ids(V,-1);
vector<int> low(V,-1);
vector<bool> vis(V,false);

void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int v, int parent, vector<int>& ans){
	vis[v]=true;
	id++;
	ids[v]=low[v]=id;

	for(auto it:adj[v]){
		if(it==parent)
			continue;
		if(!vis[it]){
			dfs(it,v,ans);
			low[v]=min(low[it],low[v]);
			if(ids[v]<low[it]){
				ans.push_back(v);
				ans.push_back(it);
			}
		}else{
			low[v]=min(low[it],low[v]);
		}
	}
}


void findBridges(){
	vector<int> ans;
	for(int i=0;i<V;i++){
		if(!vis[i])
			dfs(i,-1,ans);
	}
	for(int i=0;i<ans.size();i+=2)
		cout<<ans[i]<<"-"<<ans[i+1]<<"\n";
}

int main(){
	addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 	
    findBridges();
    return 0;
}