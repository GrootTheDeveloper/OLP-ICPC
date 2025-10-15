#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

bool comp(const ll &x, const ll &y) {
    return abs(x) < abs(y);
}
signed main() {
     int n;
    cin>>n;
    vector<ll> a(n);
    for (auto &x : a) cin>>x;

    int zerocnt=0;
    for (auto x : a) if (x==0) ++zerocnt;

    vector<ll> neg, pos, new_a;
    for (auto x : a) {
        if (x<0) neg.push_back(x);
        else if (x>0) pos.push_back(x);
        if (x!= 0) new_a.push_back(x);
    }

    auto amin = *min_element(a.begin(), a.end(), comp);
    auto amax_neg = neg.empty() ? (ll)1e18 : *max_element(neg.begin(), neg.end());
    auto amax_neg_abs = neg.empty() ? (ll)1e18 : *max_element(neg.begin(), neg.end(), comp);
    
    ll luna=0, thana=0;

    if (zerocnt>=2) {
        luna = *max_element(a.begin(), a.end());
        thana = *min_element(a.begin(), a.end());
    }
    else if (zerocnt==1) {
        if ((int)neg.size() % 2 == 0) {
            luna = thana = 0;
        } else {
        luna = *max_element(new_a.begin(), new_a.end());
        thana = *min_element(new_a.begin(), new_a.end());
        }
    } else {
        if ((int)neg.size() % 2 == 0) {
            if (pos.empty() == false) {
                luna = thana = *min_element(pos.begin(), pos.end());
            }
            else {
                luna = thana = *max_element(neg.begin(), neg.end(), comp);
            }
        } else {
            ll res = *min_element(neg.begin(), neg.end(), comp);
            luna = res;
            thana = res;
        }
    }
    cout<<luna<<" "<< thana;
}
