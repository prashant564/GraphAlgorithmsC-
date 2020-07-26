#include <bits/stdc++.h>
using namespace std;

int BFS(int i, vector<int> adj[], vector<bool> &vis, int l, int N){
    int count=0;
    vector<int> distance(N);
    list<int> q;
    q.push_back(i);
    vis[i]=true;
    distance[i]=0;
    
    while(!q.empty()){
        i=q.front();
        q.pop_front();
        
        for(auto it:adj[i]){
            if(!vis[it]){
                distance[it]=distance[i]+1;
                vis[it]=true;
                q.push_back(it);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(distance[i]==l)
            count++;
    }
    return count;
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int N,E,l;
	    cin>>N>>E;
	    vector<int> adj[N];
	    for(int i=0;i<E;i++){
	        int u,v;
	        cin>>u>>v;
	        adj[u].push_back(v);
	    }
	    cin>>l;
	    vector<bool> vis(N,false);
	    cout<<BFS(0,adj,vis,l,N)<<"\n";
	}
	return 0;
}