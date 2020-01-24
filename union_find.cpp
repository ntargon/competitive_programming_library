class UnionFind{
  vector< int > par;
  vector< int > num;

  public:
    UnionFind(int N) : par(N), num(N){
      for(int i=0; i<N; i++){
        par[i] = i;
        num[i] = 1;
      }
    }

    int root(int x){
      if(par[x] == x) return x;
      return par[x] = root(par[x]);
    }

    void unite(int x, int y){
      int rx = root(x);
      int ry = root(y);
      if(rx == ry) return;
      par[rx] = ry;
      num[ry] = num[rx] + num[ry];
    }

    bool same(int x, int y){
      int rx = root(x);
      int ry = root(y);
      return rx == ry;
    }

    int size(int x){
      return num[root(x)];
    }
};