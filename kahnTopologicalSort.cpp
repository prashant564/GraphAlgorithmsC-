#include <bits/stdc++.h>
using namespace std;


// LOGIC
/*
This is a linear time top sort algo. 
We find the indegree of each node. Indegree of a node is the number of edges 
coming towards it. 
We store indegree of each node in an array.
We create a queue of nodes with indegree = 0
Now we start at the indegree=0 edges and remove all the edges connected to them
IF this removal of edges has resulted in a node getting its indegree as 0, we add 
that node to queue.
We do the same thing until queue is empty.
*/

void addEdge(vector<int> adj[], vector<int> &inDegree, int u, int v){
	adj[u].push_back(v);
	inDegree[v]++;
}

// TC:O(V+E)=>O(N), SC: O(V)
void kahnTopSort(vector<int> adj[], vector<int> &inDegree, int V){
	queue<int> q;
	vector<int> ans;
	for(int i=0;i<V;i++)
		if(inDegree[i]==0)
			q.push(i);

	while(!q.empty()){
		int curr=q.front();
		ans.push_back(curr);
		q.pop();

		for(auto node:adj[curr]){
			inDegree[node]--;
			if(inDegree[node]==0)
				q.push(node);
		}
	}

	cout<<"Top Sort is: ";
	for(auto e: ans)
		cout<<e<<" ";	
}


int main(){
	int V=6;
	vector<int> adj[V];
	vector<int> inDegree(V);
    addEdge(adj, inDegree,5, 2); 
    addEdge(adj, inDegree,5, 0); 
    addEdge(adj, inDegree,4, 0); 
    addEdge(adj, inDegree,4, 1); 
    addEdge(adj, inDegree,2, 3); 
    addEdge(adj, inDegree,3, 1);
    kahnTopSort(adj, inDegree, V);
    return 0;	
}