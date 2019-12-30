typedef long long int ll;

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> num;
    // vector<ll> dist; // rootまでの距離

    UnionFind(ll N) : par(N), num(N){ //最初は全てが根であるとして初期化
      for(ll i = 0; i < N; i++) par[i] = i;
      for(ll i = 0; i < N; i++) num[i] = 1;
      // for(ll i = 0; i < N; i++) dist[i] = 0;

    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        num[ry] = num[rx] + num[ry];
    }



    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
      return num[root(x)];
    }


};
