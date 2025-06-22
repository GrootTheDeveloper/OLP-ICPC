#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<string>a;
int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

vector<int>adj[100005];

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}