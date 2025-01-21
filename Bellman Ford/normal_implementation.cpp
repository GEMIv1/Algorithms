#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge{
    int from, to ,weight;
    Edge(){
        from = 0;
        to = 0;
        weight = 0;
    }
    Edge(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};


bool bellmanFord(vector<Edge> &edges, int src, int V){

    vector<double> dist(V, INF);
    dist[src] = 0;

    bool relaxed = true;
    for(int i=0; i<V&&relaxed;i++){
        relaxed = false;
        for(auto &edge : edges){
            if(dist[edge.from]+edge.weight < dist[edge.to]){
                dist[edge.to] = dist[edge.from]+edge.weight;
                relaxed = true;
            }
        }
    }

    bool relaxed = true;
    for(int i=0; i<V&&relaxed;i++){
        relaxed = false;
        for(auto &edge : edges){
            if(dist[edge.from]+edge.weight < dist[edge.to]){
                dist[edge.to] = dist[edge.from]+edge.weight;
                relaxed = true;
            }
        }
    }

    for(int i=0; i<V&&relaxed;i++){
        for(auto &edge : edges){
            if(dist[edge.from]+edge.weight < dist[edge.to]){
                return true;
            }
        }
    }



    return false;
}

int main(){


    int V = 4, E = 5, source = 0;//V -> vertices, E -> edges

    vector<Edge> edges = {
        {0, 1, -1},
        {1, 2, -2},
        {2, 3, -3},
        {3, 0, -4},
        {1, 3, 2}
    };

    bool negativeCycle = bellmanFord(edges,source,V);

    if(negativeCycle)cout<<"There is a negative cycle\n";
    else cout<<"There is no negative cycle\n";

    return 0;
}