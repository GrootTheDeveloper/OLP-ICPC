#include <bits/stdc++.h>
#define int long long
using namespace std; 

double median(vector<double> &a) {
    int n = a.size()-1;
    if (n % 2 == 0) {
        return (a[n / 2] + a[n / 2 + 1]) / 2.0;
    }
    else {
        return 1.0 * a[n / 2 + 1];
    }
}

signed main(){
    int n; cin >> n;
    vector<double>a(n + 1);
    int half = n / 2;
    for (int i = 1; i <= n; i++)  {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<double> left(1), right(1);
    double q1,q2,q3;
    if (n % 2== 1) {
        q1 = a[half];  
        for (int i = 1; i <= half; i++) {
            left.push_back(a[i]);
        }
        for (int i = half + 2; i <= n; i++) {
            right.push_back(a[i]);
        }
        q2 = median(left);
        q3 = median(right);
    }
    else {
        for (int i = 1; i <= half; i++) {
            left.push_back(a[i]);
        }
        for (int i = half + 1; i <= n; i++) {
            right.push_back(a[i]);
        }
        q1 = median(a);
        q2 = median(left);
        q3 = median(right);
    }

    cout << q1 << " " << q2 << " " << q3;
}
