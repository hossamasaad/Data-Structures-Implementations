#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define Sort(vec) sort(vec.begin(),vec.end())
#define ii pair<int,int>

using namespace std;

struct Graph
{
    int V, E;
    vector< pair<int,ii>> edges;

    Graph(int V, int E){
        this-> E = E;
        this-> V = V;
    }

    void addEdge(int u, int v, int w){
        edges.pb(mp(w,mp(u,v)));
    }

    int kruskalMST();
};


struct disjoint{
    int *parent, *rank;
    int n;

    disjoint(int n){
        this-> n = n;
        parent = new int[n+1];
        rank   = new int[n+1];

        for(int i=0;i<=n;i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void Union(int x, int y)
    {
        x = find(x); y = find(y);

        if( rank[x] > rank[y] )
            parent[y] = x;
        else
            parent[x] = y;

        if(rank[x] == rank[y] )
            rank[y] += 1;
    }
};

int Graph::kruskalMST() {
    int mst_wt = 0;
    Sort(edges);
    disjoint ds(V);

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        int su = ds.find(u);
        int sv = ds.find(v);

        if( su != sv )
        {
            cout << u << " " << v << endl;
            mst_wt += edges[i].first;
            ds.Union(su, sv);
        }
    }

    return mst_wt;
}

int main() {

    int V = 9, E = 14;
    Graph g(V, E);

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

    cout << "\nWeight of MST is " << mst_wt;
    return 0;
}
