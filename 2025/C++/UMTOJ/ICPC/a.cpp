#include <bits/stdc++.h>

using namespace std;

struct point {
    double x1,y1,x2,y2;
};

pair<double, double> calc(point p) {
    double a = (p.y1 - p.y2) / (p.x1 - p.x2);
    double b = p.y1 - a * p.x1;
    return {a, b};
}

bool comp(point a, point b) {
    return (calc(a) == calc(b)) && (b.x1 >= a.x2 && b.y1 >= a.y2);
}

bool compare(const point &A, const point &B) {
    if (A.x1 != B.x1) {
        return A.x1 < B.x1;
    }
    else {
        if (A.x2 != B.x2) {
            return A.x2 < B.x2;
        }
        else {
            if (A.y1 != B.y1) {
                return A.y1 < B.y1;
            }
            else {
                return A.y2 < B.y2;
            }
        }
    }
}


int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<point> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        }
        vector<bool> check(n + 1, false);

        sort(a.begin() + 1, a.end(), compare);

        int ans = n;

        for (int i = 1; i <= n; i++) {
            if (check[i] == false) {
                check[i] = true;
                for (int j = 1; j <= n; j++) {
                    if (check[j] == false && comp(a[i], a[j])) {
                        ans--;
                        check[j] = true;
                    }
                }
            }
        }

        cout << ans << endl;
    }
}