struct DSU{
  int n;// number of elements
  int *parent;// dynamic array to store the parent
  int *numNodes;// size of nodes

  void init(int _n){
    n=_n;
    numNodes = new int[_n];
    parent = new int[_n];

    for(int i=0;i<_n;i++)parent[i] = i;
    for(int i=0;i<_n;i++)numNodes = 1;
  }

  void Destroy(){
    n = 0;
    delete[] parent;
    delete[] numNodes;
  }

  int FIND(int i){
    int root = i;
    while(root != parent[root])root = parent[root];
    while(i!=root){ // path compression
      int nxt = parent[i]
      parent[i] = root;
      i = nxt;
    }
    return root;
}
  bool UNION(int i, int j){
    if(FIND(i)==FIND(j)) return true;
    int root1 = FIND(i);
    int root2 = FIND(j);
    if(numNodes[root1] < numNodes[root2]){
      numNodes[root2]+=NumNodes[root1];
      parent[root1] = root2;
    }
     if(numNodes[root1] > numNodes[root2]){
      numNodes[root1]+=NumNodes[root2];
      parent[root2] = root1;
    } 
  }
}
