struct Edge {
    int weight;
    int node;
};

struct Compare {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};

void prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(n, false);   // Tracks nodes included in MST
    vector<int> minEdgeWeight(n, INT_MAX); // Min edge weight for each node
    vector<int> parent(n, -1);      // Stores parent of each node in MST
    priority_queue<Edge, vector<Edge>, Compare> pq;

    int src = 0; 
    pq.push({0, src});
    minEdgeWeight[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().node;  // Current node
        pq.pop();

        if (inMST[u]) continue; // Skip if already in MST
        inMST[u] = true;

        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < minEdgeWeight[v]) {
                minEdgeWeight[v] = weight;
                pq.push({weight, v});
                parent[v] = u;
            }
        }
    }

}
