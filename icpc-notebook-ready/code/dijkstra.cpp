#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL<<60);
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,s; 
  if(!(cin>>n>>m>>s)) return 0;
  --s;
  vector<vector<pair<int,int>>> g(n);
  while(m--){
    int u,v,w; cin>>u>>v>>w; --u;--v;
    g[u].push_back({v,w});
    g[v].push_back({u,w}); // remove for directed
  }
  vector<long long> d(n,INF); d[s]=0;
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
  pq.push({0,s});
  while(!pq.empty()){
    auto [du,u]=pq.top(); pq.pop();
    if(du!=d[u]) continue;
    for(auto [v,w]: g[u]){
      if(d[v]>du+w){
        d[v]=du+w; pq.push({d[v],v});
      }
    }
  }
  for(int i=0;i<n;++i) cout<<d[i]<<"\n";
}
