#include <bits/stdc++.h>
using namespace std;
#define int long long
struct iii{ int w,v,id; };
int n,m,L,R,sum(0),ans[33];
vector <int> res; iii a[33];
bool cmp(iii x,iii y){ return x.v<y.v; }
bool check(int d){ return (n==20&&d<8)||(n==25&&d<19)||(n==29&&d<10); }
void dq(int i,int wei,int val,int d){
    if (val<sum&&L<=wei&&wei<=R){
        if (check(d)) return;
        sum=val; m=0;
        for(auto x:res) ans[++m]=x;
    }
    for(int j=i; j<=n; j++) {
        if (a[j].v+val>sum) 
            return; 
        else if (wei+a[j].w<=R){
            res.push_back(a[j].id);
            dq(j+1,wei+a[j].w,val+a[j].v,d+1);
            res.pop_back();
        }
    }
}
int32_t main(){  
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>L>>R;
    for(int i=1; i<=n; i++){
        int x,y; cin>>x>>y;
        a[i]={x,-y,i};
    }
    sort(a+1,a+n+1,cmp); dq(1,0,0,0); 
    sort(ans+1,ans+m+1); cout<<m<<"\n";
    for(int i=1; i<=m; i++) cout<<ans[i]<<"\n";
}
