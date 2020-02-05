#include <bits/stdc++.h>

using namespace std;

vector<int> adjList[10];
bool visited[10];

void addEdge(int u, int v)
{
    adjList[u].push_back(v);
}

// Graph traversal DFS and BFS

void DFS(int u)
{
    visited[u] = true;
    for(int i=0;i<adjList[u].size();i++)
    {
        if(!visited[adjList[u][i]])
            DFS(adjList[u][i]);
    }
}

void BFS(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int s = q.front(); q.pop();
        cout << s << endl;
        for(int i=0;i<adjList[s].size();i++)
        {
            if(!visited[ adjList[s][i] ])
            {
                visited[ adjList[s][i] ] = true;
                q.push( adjList[s][i] );
            }
        }
    }
}

// get Connected Component of a graph

int getConnectedComponent()
{
    int numCC = 0;
    for(int i=1;i<=7;i++)
    {
        if(!visited[i]){
            numCC++;
            DFS(i);
        }
    }
    return numCC;
}

// gat a topological sort for the graph

vector<int> path;

void TopoDFS(int u)
{
    visited[u] = true;
    for(int i=0;i<adjList[u].size();i++)
    {
        if(!visited[adjList[u][i]])
            TopoDFS(adjList[u][i]);
    }
    path.push_back(u);
}

void topoSort()
{
    for(int i=1;i<=7;i++)
        if(!visited[i])
           TopoDFS(i);

    reverse(path.begin(), path.end());    
    for(int i=0;i<path.size();i++)
        cout << path[i] << endl;
}

// check is graph is barpartite or not

int color[10];

bool isBipartite(int u)
{
    memset(color, -1, sizeof(color));        // -1 notColored 
    bool bipartite = true;                   // 0 first Color
    color[u] = 0;                            // 1 second color
    queue<int> q; q.push(u);

    while(!q.empty() && bipartite)
    {
        int s = q.front(); q.pop();
        for(int i=0;i<adjList[s].size();i++)
        {
            if(color[ adjList[s][i] ] == -1)
            {
                color[ adjList[s][i] ] = 1 - color[s];
                q.push( adjList[s][i] );
            }
            else if( color[ adjList[s][i] ] == color[s] ){
                bipartite = false;
                break;
            }
        }
    }
    return bipartite;
}

// SSC Tarjan's Algorithm

vector<int> ID,low_link,S;
bool onStack[10];
int dfsNum = 0,numSCC=0;
int UNVISITED = -1;

void clear()
{
    ID.assign(10, UNVISITED);
    low_link.assign(10, 1e9);
    memset(onStack, false, sizeof(onStack));
    dfsNum = 0;
    numSCC = 0;
}

void tarjan(int u)
{
    ID[u] = low_link[u] = dfsNum++;
    S.push_back(u);
    onStack[u] = true;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v = adjList[u][i];
        if( ID[v] == UNVISITED )
            tarjan(v);
        
        if( onStack[v] )
            low_link[u] = min(low_link[u], low_link[v]);
        
        if( low_link[u] == ID[u] )
        {
            cout << "SCC " << ++numSCC << endl;
            while(true)
            {
                int v = S.back(); S.pop_back();
                onStack[v] = 0;
                cout << v << " ";
                if( u == v ) break;
            }
            cout << endl;
        }
    }
}

void getSCC(){
    clear();
    for(int i=1;i<=7;i++)
    {
        if(ID[i] == UNVISITED)
            tarjan(i);
    }
}

// Dijkstrta's Algorithm To get Shortest path

typedef pair<int, int> ii; 
int Dis[10];
int prev[10];
vector< ii > grid[10];

void dijkstra(int s)
{
    memset(visited, false, 10);
    memset(Dis, 1e9, 10);
    memset(prev,0,sizeof(prev));

    Dis[s] = 0;

    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push( ii(0,s) );

    while(!pq.empty())
    {
        ii p = pq.top(); pq.pop();
        int minValue = p.first;
        int idx = p.second;

        visited[idx] = true;
        if( Dis[idx] < minValue )
        {
            for(int j=0;j<grid[idx].size();j++)
            {
                ii v = grid[idx][j];
                int edge_to = v.first;
                if(visited[edge_to]) continue;

                int new_dist = Dis[idx] + minValue;
                if( new_dist < Dis[edge_to])
                {
                    prev[edge_to] = idx;
                    Dis[edge_to] = new_dist;
                    pq.push( ii(new_dist,edge_to) ); 
                }
            }
        }
    }
}

void getShortestPath(int s, int e)
{
    dijkstra(s);
    vector<int> path;
    if(Dis[e] == 1e9) return;    // no path reach to this point
    for(int i=9;i>=0;i++)
    {
        path.push_back(prev[i]);
    }
}

int main() {
    
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(3, 7);

    // DFS(1);
    // BFS(1);
    // topoSort()
    // cout << getConnectedComponent() << endl;
    // cout << isBipartite(1) << endl;
    // getSCC()
    // getShortestPath()

}

//      1
//   2      3
// 4   5  6   7
