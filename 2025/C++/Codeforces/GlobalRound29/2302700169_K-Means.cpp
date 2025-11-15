#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;



struct point {
    double x, y;
};

double euclid (point a, point b) {
    double ans = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return ans;
}

point centroid(vector<point> pointList) {
    point ans;
    double x = 0.0, y = 0.0;
    for (auto i : pointList) {
        x += i.x;
        y += i.y;
    }
    x /= 1.0 * pointList.size();
    y /= 1.0 * pointList.size();
    ans.x = x;
    ans.y = y;
    return ans;
}

APC main() {
    vector<point> pointList;
    pointList = {{2, 10}, {2, 5}, {8, 4}, {5, 8},
                {7, 5}, {6, 4}, {1, 2}, {4, 9}};

    
    
    int clusterNumber = 3;
    int n = pointList.size();
    vector<point> centers;
    vector<int> label(n, -1);
    bool change;
    int cnt = 1;
    do {
        change = false;
        if (centers.empty() == true) {
            // Chọn 3 thằng đầu tiên làm centroid
            centers.resize(clusterNumber);
            centers[0] = pointList[0];
            centers[1] = pointList[3];
            centers[2] = pointList[6];
        }

        // phân cụm
        for (int i = 0; i < n; i++) {
            int bestIndex = 0;
            double bestDistance = 1e18;
            for (int j = 0; j < clusterNumber; j++) {
                double curDistance = euclid(centers[j], pointList[i]);
                if (curDistance < bestDistance) {
                    bestDistance = curDistance;
                    bestIndex = j;
                }
            }
            if (label[i] != bestIndex) {
                change = true;
                label[i] = bestIndex;
            }
        }

        vector<vector<point>> clusters(clusterNumber);
        for (int i = 0; i < n; i++) {
            clusters[label[i]].push_back(pointList[i]);
        }

                cout << "--------" << cnt++ << "---------" << endl;
        cout << fixed << setprecision(2);
        for (int i = 0; i < n; i++) {
            double d = euclid(pointList[i], centers[label[i]]);
            cout << "Point (" << pointList[i].x << ", " << pointList[i].y
                << ") -> cluster " << (label[i] + 1)
                << " | distance = sqrt(" << d*d << "), center = (" << centers[label[i]].x << " " << centers[label[i]].y<< ")\n";
        }
        for (int i = 0; i < clusterNumber; i++) {
            centers[i] = centroid(clusters[i]); 
        }

        cout << "----------------------------\n";

    }
    while (change);


}
