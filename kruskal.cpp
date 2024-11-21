struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight; // Sort edges by weight
    }
};

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<Edge> mst; // To store the edges of the MST
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) { // If the edge doesn't form a cycle
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }
