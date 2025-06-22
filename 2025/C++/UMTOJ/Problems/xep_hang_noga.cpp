#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val, prio, sz, mx;
    Node *l, *r;
    Node(int v): val(v), prio(rand()), sz(1), mx(v), l(nullptr), r(nullptr) {}
};
using pNode = Node*;

int gsz(pNode t){ return t ? t->sz : 0; }
int gmx(pNode t){ return t ? t->mx : INT_MIN; }
void upd(pNode t){
    if (!t) return;
    t->sz = 1 + gsz(t->l) + gsz(t->r);
    t->mx = max(t->val, max(gmx(t->l), gmx(t->r)));
}

void split(pNode t, int k, pNode &L, pNode &R) {
    if (!t) { L = R = nullptr; return; }
    if (gsz(t->l) >= k) {
        split(t->l, k, L, t->l);
        R = t;
    } else {
        split(t->r, k - gsz(t->l) - 1, t->r, R);
        L = t;
    }
    upd(t);
}

pNode merge(pNode L, pNode R) {
    if (!L || !R) return L ? L : R;
    if (L->prio > R->prio) {
        L->r = merge(L->r, R);
        upd(L);
        return L;
    } else {
        R->l = merge(L, R->l);
        upd(R);
        return R;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr));
    int N, J;
    cin >> N >> J;
    pNode root = nullptr;
    for(int i = 0, h; i < N; i++){
        cin >> h;
        root = merge(root, new Node(h));
    }

    while(J--){
        int A, B;
        char dir;
        cin >> A >> dir >> B;
        pNode L, tmp;
        split(root, A-1, L, tmp);
        pNode mid, R;
        split(tmp, 1, mid, R);

        int ans;
        if (dir == 'L') {
            pNode LL, jumped;
            split(L, gsz(L) - B, LL, jumped);
            ans = jumped->mx;
            root = merge( merge(LL, mid), merge(jumped, R) );
        } else {
            pNode jumped, RR;
            split(R, B, jumped, RR);
            ans = jumped->mx;
            root = merge( merge(L, jumped), merge(mid, RR) );
        }
        cout << ans << endl;
    }
    return 0;
}
