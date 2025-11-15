#include <bits/stdc++.h>
using namespace std;
struct Seg {
  int n; vector<long long> t;
  Seg(int n=0): n(n), t(2*n,0) {}
  void build(const vector<long long>& a){
    n = (int)a.size(); t.assign(2*n,0);
    for(int i=0;i<n;++i) t[n+i]=a[i];
    for(int i=n-1;i;--i) t[i]=t[i<<1]+t[i<<1|1];
  }
  void upd(int p,long long v){
    for(t[p+=n]=v;p>1;p>>=1) t[p>>1]=t[p]+t[p^1];
  }
  long long qry(int l,int r){
    long long res=0;
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
      if(l&1) res+=t[l++];
      if(!(r&1)) res+=t[r--];
    }
    return res;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q; if(!(cin>>n>>q)) return 0;
  vector<long long> a(n); for(auto &x:a) cin>>x;
  Seg st; st.build(a);
  while(q--){
    int type; cin>>type;
    if(type==1){int p; long long v; cin>>p>>v; st.upd(p,v);}
    else{int l,r; cin>>l>>r; cout<<st.qry(l,r)<<"\n";}
  }
}
