static const int INF = 1e9;
int main() {
    int n, m; if (!(cin >> n >> m)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    vector<pair<int,int>> L;
    deque<pair<int,int>> q;
    vector<vector<int>> day(n, vector<int>(m, INF));

    // init: water and L have day 0
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'L') L.push_back({i,j});
            if (g[i][j] != 'X') { // '.' or 'L'
                day[i][j] = 0;
                q.push_back({i,j});
            }
        }

    auto inside = [&](int x,int y){return 0<=x && x<n && 0<=y && y<m;};
    const int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

    // BFS to compute earliest melt day
    int maxDay = 0;
    while(!q.empty()){
        auto [x,y]=q.front(); q.pop_front();
        for(int dir=0; dir<4; ++dir){
            int nx=x+dx[dir], ny=y+dy[dir];
            if(!inside(nx,ny)) continue;
            if(day[nx][ny] != INF) continue;
            // if neighbor is ice, it melts one day after current water reaches border
            day[nx][ny] = day[x][y] + 1;
            maxDay = max(maxDay, day[nx][ny]);
            q.push_back({nx,ny});
        }
    }

    // binary search minimal D
    auto can = [&](int D)->bool{
        // BFS from L[0], only through cells with day <= D
        queue<pair<int,int>> qb;
        vector<vector<char>> vis(n, vector<char>(m, 0));
        qb.push(L[0]); vis[L[0].first][L[0].second]=1;
        while(!qb.empty()){
            auto [x,y]=qb.front(); qb.pop();
            if (x==L[1].first && y==L[1].second) return true;
            for(int dir=0; dir<4; ++dir){
                int nx=x+dx[dir], ny=y+dy[dir];
                if(!inside(nx,ny) || vis[nx][ny]) continue;
                if(day[nx][ny] <= D){
                    vis[nx][ny]=1;
                    qb.push({nx,ny});
                }
            }
        }
        return false;
    };

    int lo=0, hi=maxDay, ans=maxDay;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(can(mid)){ ans=mid; hi=mid-1; }
        else lo=mid+1;
    }
    cout << ans << '\n';
    return 0;
}
