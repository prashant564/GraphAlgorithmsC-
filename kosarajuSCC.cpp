#include<bits/stdc++.h>
using namespace std;
#define V 5

/*
KOSARAJU ALGORITHM
  TC: O(V+E)
  SC: O(V) 
1)- Create both normal and reversed graph
2)- Do a dfs with a visited array, and store 
nodes in a stack by their finishing order
3)- Select the top element of stack and pop it.
4)- Do a DFS on the top ele of the stack, 
but this time on the reversed graph
5)- Each DFSUtil call gives a SCC
*/

vector<int> adj[V],radj[V];

void addEdge(int u, int v){
	adj[u].push_back(v);
	radj[v].push_back(u);
}

void fillByFinishingTimeDFS(int v, vector<bool> &vis, stack<int> &s){
	vis[v]=true;
	for(auto e:adj[v])
		if(vis[e]==false)
			fillByFinishingTimeDFS(e,vis,s);
	s.push(v);	
}

void dfs(int v, vector<bool> &vis){
	vis[v]=true;
	cout<<v<<" ";

	for(auto e:radj[v])
		if(!vis[e])
			dfs(e,vis);
}

void findSCCs(){
	stack<int> s;
	vector<bool> vis(V,false);
// Store nodes in stack in the order of their finishing time
	for(int i=0;i<V;i++){
		if(vis[i]==false)
			fillByFinishingTimeDFS(i,vis,s);
	}
// Marking all nodes as unvisited for the second DFS
	for(auto e:vis)
		e=false;
// To find all the SCCs
	while(!s.empty()){
		int v=s.top();
		s.pop();
		if(vis[v]==false){
			dfs(v,vis);
			cout<<endl;
		}
	}
}

int main(){
	addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    findSCCs();
    return 0;
}