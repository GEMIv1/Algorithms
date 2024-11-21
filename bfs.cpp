const int N = 1e9;

void bfs(int src){
  vector<int> dist(N,-1);
  queue<int> q(N);

  q.push(src);
  dist[src] = 0;

  while(!q.empty()){
    int curr = q.front();
    q.pop();

    for(int v:adj[curr]){
      if(dist[v]==-1){//not visited
        dist[v] = dist[curr]+1;
      }
    }
  }
  

}
