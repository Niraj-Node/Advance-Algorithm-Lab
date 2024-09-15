#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int N;                    // Number of vertices
    vector<vector<int>> G;    // Adjacency matrix
    vector<vector<int>> edges; // Edge list

    void createEdgeMatrix() {
        int m = countEdges();
        edges.resize(m, vector<int>(2));
        int x = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (G[i][j] == 1) {
                    edges[x][0] = i;
                    edges[x][1] = j;
                    x++;
                }
            }
        }
    }

    int countEdges() const {
        int counter = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (G[i][j] == 1)
                    counter++;
            }
        }
        return counter;
    }

    int find(int node, vector<int>& parent) const {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }

    void Union(int u, int v, vector<int>& parent) {
        u = find(u, parent);
        v = find(v, parent);
        if (u != v) parent[v] = u;
    }

public:
    Graph(int size) : N(size), G(size, vector<int>(size, 0)) {}

    void addEdge(int u, int v) {
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int minimumCut() {
        createEdgeMatrix(); // Create edge list here
        
        int fans = INT_MAX;
        int m = edges.size(); // Correctly get the number of edges

        for (int k = 0; k < 100 * N * N; k++) {
            vector<int> parent(N);
            for (int i = 0; i < N; i++) parent[i] = i;

            int n = N;

            while (n > 2) {
                int e = rand() % m;
                int u = edges[e][0];
                int v = edges[e][1];

                int set1 = find(u, parent);
                int set2 = find(v, parent);

                if (set1 != set2) {
                    // cout << "Contracting vertices " << u << " and " << v << endl;
                    Union(u, v, parent);
                    n--;
                }
            }

            // Count remaining edges
            int ans = 0;
            // cout << "Edges that need to be removed to separate the graph:" << endl;
            for (int i = 0; i < m; i++) {
                int set1 = find(edges[i][0], parent);
                int set2 = find(edges[i][1], parent);

                if (set1 != set2) {
                    // cout << edges[i][0] << " <----> " << edges[i][1] << endl;
                    ans++;
                }
            }
            // cout << "Number of edges in the cut: " << ans << endl;
            fans = min(ans, fans);
        }

        return fans;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // Initialize random seed

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << "Final answer is " << g.minimumCut() << endl;
    return 0;
}
