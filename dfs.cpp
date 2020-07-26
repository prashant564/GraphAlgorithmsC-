#include <bits/stdc++.h>
using namespace std;


void dfsUtilConnectedComponent(vector<int> g[], int i, bool vis[])
{
    vis[i]=true;
    for(auto it=g[i].begin();it!=g[i].end();it++)
        if(!vis[*it])
            dfsUtilConnectedComponent(g,*it,vis);
}


int noOfConnectedComponents(vector<int> g[], int N, bool vis[]){
    int count=0;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            dfsUtilConnectedComponent(g,i,vis);
            count++;
        }
    }
    return count;
}


void dfsUtilusingStack(vector<int> g[], vector<int> &v,bool vis[], int i){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        i = s.top();
        s.pop();
        if(!vis[i]){
            v.push_back(i);
            vis[i]=true;
        }

        for(auto it = g[i].begin();it!=g[i].end();it++){
            if(!vis[*it])
                s.push(*it);
        }
    }
}


void dfsUtil(vector<int> g[], vector<int> &v,bool vis[], int i)
{
    vis[i]=true;
    v.push_back(i);
    for(auto it=g[i].begin();it!=g[i].end();it++)
        if(!vis[*it])
            dfsUtil(g,v,vis,*it);
}

vector <int> dfs(vector<int> g[], int N, bool vis[])
{
    vector<int> ans;
    // bool *vis = new bool[N];
    // for(int i=0;i<N;i++)
    //     vis[i]=false;
    // dfsUtil(g,ans,vis,0);

    for(int i=0;i<N;i++)
        if(!vis[i])
            dfsUtilusingStack(g,ans,vis,i);
    return ans;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int N,E;
        cin>>N>>E;

        vector<int> adj[N];
        bool vis[N];
        memset(vis,false,sizeof(vis));

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> res = dfs(adj, N, vis);
        for(auto e: res)
            cout<<e<<" ";
        cout<<"\n";

        // cout<<noOfConnectedComponents(adj, N, vis)<<"\n";
    }
}