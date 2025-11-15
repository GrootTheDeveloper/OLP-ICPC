struct SegTree {
    int n;
    vector<int> st;
    SegTree(int n=0): n(n), st(4*n+5, 0) {}
    void add(int p, int v, int id, int l, int r){
        if(l==r){ st[id]+=v; return; }
        int m=(l+r)>>1;
        if(p<=m) add(p,v,id<<1,l,m);
        else     add(p,v,id<<1|1,m+1,r);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    void add(int p,int v){ add(p,v,1,1,n); }
    int sum(int L,int R,int id,int l,int r){
        if(R<l||r<L) return 0;
        if(L<=l&&r<=R) return st[id];
        int m=(l+r)>>1;
        return sum(L,R,id<<1,l,m)+sum(L,R,id<<1|1,m+1,r);
    }
    int sum(int L,int R){ if(L>R) return 0; return sum(L,R,1,1,n); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i]; // permutation 1..n

    SegTree st(n);
    long long inv = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        inv += st.sum(x+1, n); // số phần tử trước đó > x
        st.add(x, 1);          // đánh dấu đã thấy x
    }
    cout << inv << '\n';
    return 0;
}
