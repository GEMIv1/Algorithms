#include <iostream>
#include <vector>
#define nl "\n"
using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};

void bellmanFord(int n, int m, int source, vector<Edge>& edges) {
    vector<vector<int>> dp(m+1,vector<int>(n+1,INF));

    dp[0][source] = 0;

    for(int k=1;k<=n-1;k++){
        for(int i=0;i<n;i++)dp[k][i]=dp[k-1][i];

        for(auto &edge: edges){
            if(dp[k][edge.from] != INF){
                dp[k][edge.to] = min(dp[k][edge.to], dp[k-1][edge.from]+edge.weight);
            }
        }
        
    }

    cout << "Shortest distances using at most k edges:" << endl;
    for (int k = 0; k < m; ++k) {
        cout << "k = " << k << ": ";
        for (int i = 1; i <= n; ++i) {
            if (dp[k][i] == INF) {
                cout << "INF ";
            } else {
                cout << dp[k][i] << " ";
            }
        }
        cout << nl;
    }

   bool negativeCycle = false;
   for(auto &edge : edges){
    if(dp[n-1][edge.from] != INF && dp[n-1][edge.from] + edge.weight < dp[n-1][edge.to]){
        negativeCycle = true;
        break;
    }
   }

   if(negativeCycle)cout<<"There is a negative cycle!!\n";
   else cout<<"There is no negative cycle\n";

    
}

int main() {
    int n = 4, m = 5, source = 0;//n -> nodes, m -> edges

    vector<Edge> edges = {
        {0, 1, -1},
        {1, 2, -2},
        {2, 3, -3},
        {3, 0, -4},
        {1, 3, 2}
    };

    bellmanFord(n, m, source, edges);

    return 0;
}
