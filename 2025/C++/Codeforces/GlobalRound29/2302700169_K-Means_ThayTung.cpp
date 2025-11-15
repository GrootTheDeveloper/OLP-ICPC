#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;



struct point {
    double x, y;
};

double euclid (point a, point b) {
    double ans = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
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
    pointList = {{1, 7}, {2, 7}, {6, 6}, {3, 5}, {4, 5},
                {3, 4}, {7, 3}, {1, 2}, {6, 2}, {3, 1}};

    
    
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
            centers[0] = {2, 3};
            centers[1] = {4, 7};
            centers[2] = {5, 4};
        }

        // phân cụm
        for (int i = 0; i < n; i++) {
            int bestIndex = 0;
            double bestDistance = 1e18;
            for (int j = 0; j < clusterNumber; j++) {
                double curDistance = euclid(centers[j], pointList[i]);
//                curDistance = sqrt(curDistance);
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

        // IN BẢNG KẾT QUẢ PHÂN CỤM THEO ITERATION
        cout << "-------- Iteration " << cnt++ << " ---------\n";

        // Header bảng
        cout << left
            << "| " << setw(6) << "Point"
            << "| " << setw(13) << "C1"
            << "| " << setw(13) << "C2"
            << "| " << setw(13) << "C3"
            << "| " << setw(8) << "Cluster"
            << "|\n";
        cout << string(68, '-') << "\n";

        // In từng dòng dữ liệu
        for (int i = 0; i < n; i++) {
            int d1 = (int)(euclid(pointList[i], centers[0]));
            int d2 = (int)(euclid(pointList[i], centers[1]));
            int d3 = (int)(euclid(pointList[i], centers[2]))+;

            cout << "| " << setw(6) << ("A" + to_string(i + 1))
                << "| " << setw(13) << ("SQRT(" + to_string(d1) + ")")
                << "| " << setw(13) << ("SQRT(" + to_string(d2) + ")")
                << "| " << setw(13) << ("SQRT(" + to_string(d3) + ")")
                << "| " << setw(8)  << ("C" + to_string(label[i] + 1))
                << "|\n";
        }
        cout << string(68, '-') << "\n\n";

        // ======= Update centroids ========
        for (int i = 0; i < clusterNumber; i++) {
            if (!clusters[i].empty()) {
                centers[i] = centroid(clusters[i]);
                centers[i].x = round(centers[i].x);
                centers[i].y = round(centers[i].y);
            }
        }

        // ======= In new centroids ========
        cout << "New Centroids:\n";
        for (int i = 0; i < clusterNumber; i++) {
            cout << "  C" << i + 1 << " = (" << centers[i].x << ", " << centers[i].y << ")\n";
        }
        cout << "=====================================================\n\n";




    }
    while (change);


}
