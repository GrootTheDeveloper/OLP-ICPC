#include <bits/stdc++.h>

using namespace std;

int main(){
    int w,h;cin>> w>> h;
    vector<int>down, up;
    for (int i = 1; i <= w; i++) {
        int x; cin >> x;
        if (i % 2 == 1){
            down.push_back(x);
        }
        else up.push_back(h-x);
    }

    int n = w/2;
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    map<int,int> save;

    for (int fly = 1; fly <= h; fly++) {
        int l = 0, r = n- 1;
        int hit = 0;
        int ans = n + 1;
        while(l <= r) {
            int mid = l + r >> 1;
            if (down[mid] > fly) {
                ans = mid + 1;
                r = mid - 1;
            }    
            else {
                l = mid + 1;
            }
        }

        if (ans == n + 1) {} else hit += n - ans + 1;
        l = 0, r = n - 1;
        
        ans = n + 1;

        while(l <= r) {
            int mid = l + r >> 1;
            if (up[mid] > fly) {
                ans = mid + 1;
                r = mid - 1;
            }    
            else {
                l = mid + 1;
            }
        }
        
        hit += ans - 1;

        save[hit]++;
    }
    int min_val = INT_MAX;
    for (auto [l,r] : save) {
        min_val = min(min_val, l);
    }
    for (auto [l ,r] : save) {
        if (l == min_val) {
            cout << l << " " << r;
            break;
        }
    }
}