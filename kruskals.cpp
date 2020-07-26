#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V,E;
	vector<pair<int, pair<int,int>>> edges;
public:
	Graph(int v, int e){
		this->V=v;
		this->E=e;
	}

	void addEdge(int u, int v, int w){
		edges.push_back({w,{u,v}});
	}

	int kruskalMST();
};

class UnionFind{
	int n;
	int *link,*size;
public:

	UnionFind(int n){
		this->n=n;
		link = new int[n+1];
		size = new int[n+1];

		for(int i=0;i<=n;i++){
			link[i]=i;
			size[i]=1;
		}
	}

	// Find which component does p belong to, takes O(1) time
	int find(int p){
		// Find root of the component
		int root=p;
		while(root!=link[root])
			root=link[root];

		// Path compression code here so that lookup can be done in O(1)
		while(p!=root){
			int next = link[p];
			link[p] = root;
			p = next;
		}

		return root;
	}

	// find whether both a and b are in same component or not
	bool same(int a, int b){
		return find(a)==find(b);
	}

	// Unify components containing vertices a & b
	void unify(int a, int b){
		int x = find(a);
		int y = find(b);

		if(x==y) return;

		if(size[x]<size[y])
			swap(x,y);

		size[x]+=size[y];
		link[y]=x;
	}

};

// Find min spanning cost of the graph(Elog E or Elog V)
int Graph :: kruskalMST(){
		int max_wt=0;
		
		sort(edges.begin(),edges.end());

		UnionFind  uf(V);

		for(auto e: edges){
			int a = e.second.first;
			int b= e.second.second;
			if(!uf.same(a,b)){
				cout<<a<<"-"<<b<<"\n";
				max_wt+=e.first;
				uf.unify(a,b);
			}
		}
		return max_wt;
}


int main(){
	int V = 9, E = 14; 
    Graph g(V, E); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 

    cout << "Edges of MST are \n"; 
    int mst_wt = g.kruskalMST();
    cout<<"weight of mst is : "<<mst_wt<<"\n";
}