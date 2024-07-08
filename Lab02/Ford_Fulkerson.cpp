#include<bits/stdc++.h>
using namespace std;

/*
6
10
0
5
0 2 13
0 1 16
1 2 10
2 1 4
3 2 9
2 4 14
1 3 12
4 3 7
4 5 4
3 5 20

Answer :- 23
*/


class Graph {
    int nodes;
    int edges;
    int source;
    int target;
    
    vector<vector<pair<int, int>>> adjList;

    bool bfs(vector<pair<int, int>> graph[], vector<int>& parent) 
    {
        vector<bool> visited(nodes, false);
        queue<int> q;

        visited[source] = true;
        parent[source] = -1;
        q.push(source);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto next : graph[curr]) {
                int neighbor = next.first;
                int edgeW = next.second;
                if (!visited[neighbor] && edgeW > 0) {
                    if(neighbor == target) {
                        parent[neighbor] = curr;
                        return true;
                    }
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = curr;
                }
            }
        }
        
        return false;
    }

public: 

    Graph(int n, int m, int s, int t) {
        nodes = n;
        edges = m;
        source = s;
        target = t;
    }

    void takeGraph() {
        adjList.resize(nodes);

        for (int i = 0; i < edges; i++) {
            cout << "Enter edge " << i+1 << " (u, v, w): ";
            int u, v, w;
            cin >> u >> v >> w;

            adjList[u].push_back(make_pair(v, w));
        }
    }

    void PrintGraph() {
        for (int i = 0; i< nodes; i++)
        {
            cout << i << "-> { ";
            for(auto x : adjList[i])
                cout << "{" << x.first << "," << x.second << "}, " << endl;
            cout << " }" << endl;
        }
    }

    int fordFulkerson()
    {
        vector<pair<int, int>> residualGraph[nodes];
        
        for (int u = 0; u < nodes; u++) {
            for (auto edge : adjList[u]) {
                int v = edge.first;
                int w = edge.second;
                residualGraph[u].push_back({v, w});
            }
        }
        
        vector<int> parent(nodes, -1);
        int maxFlow = 0;
        //vector<int> path;

        while (bfs(residualGraph, parent)) {
            
            int bottlenackCapacity = INT_MAX;
            for (int v = target; v != source; v = parent[v]) {
                int u = parent[v];

                auto it = find_if(residualGraph[u].begin(), residualGraph[u].end(), [v](const auto& p) { return p.first == v; }); 
                int edgeW = 0;
                if (it != residualGraph[u].end()) edgeW = it->second;
                bottlenackCapacity = min(bottlenackCapacity, edgeW);

                //path.push_back(v);
            }
            
            for (int v = target; v != source; v = parent[v]) {
                int u = parent[v];
                
                auto it = find_if(residualGraph[u].begin(), residualGraph[u].end(), [v](const auto& p) { return p.first == v; }); 
                if (it != residualGraph[u].end()) it->second -= bottlenackCapacity;
                
                auto itr = find_if(residualGraph[v].begin(), residualGraph[v].end(), [u](const auto& p) { return p.first == u; }); 
                if (itr != residualGraph[v].end()) itr->second += bottlenackCapacity;
            }
            
            // for(int i = path.size() - 1; i>=0; i--)
            //     cout << path[i] << "-";
            // cout << endl;

            maxFlow += bottlenackCapacity;
        }
        
        return maxFlow;
    }

};

int main() {
    cout << "Enter the Number of Nodes & Edges: ";
    int n, m;
    cin >> n >> m;

    cout << "Enter the Source & Target Nodes: ";
    int source, target;
    cin >> source >> target;

    Graph g(n, m, source, target);
    g.takeGraph();
    cout << "Max Flow: " << g.fordFulkerson() << endl;

    return 0;
}