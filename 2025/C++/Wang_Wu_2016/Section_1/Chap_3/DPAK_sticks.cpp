/*
Source: ACM Mid-Central United States 2004.
IDs for online judges: POJ 2013, ZOJ 2172.
Status: 
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
int n;
std::vector<int> a, divisor;
int sum;
int maxA;

std::vector<bool> used;

bool dfs(int idx, int currLen, int targetLen, int count) {
    if (count == a.size() - 1) return true;
    if (currLen == targetLen) return dfs(1, 0, targetLen, count);

    for (int i = idx; i < a.size(); ++i) {
        if (used[i]) continue;
        if (currLen + a[i] > targetLen) continue;

        used[i] = true;
        if (dfs(i + 1, currLen + a[i], targetLen, count + 1)) return true;
        used[i] = false;

        if (currLen == 0 || currLen + a[i] == targetLen) return false;
        while (i + 1 < a.size() && a[i] == a[i + 1]) ++i;
    }
    return false;
}

int main() {
    while(std::cin >> n && n != 0) {
        a.resize(n + 1);
        divisor.clear();
        used.assign(n + 1, false);
        sum = 0;
        maxA = -1;        
        for (int i = 1; i <= n; std::cin >> a[i], maxA = std::max(maxA, a[i]), sum+=a[++i - 1]);

        int k = sum / maxA;

        int temp = sum;

        for (int i = 1; i * i <= sum; ++i) {
            if (temp % i == 0) {
                divisor.push_back(i);
                if (i != sum / i) divisor.push_back(sum/i);
            }
        }
        std::sort(divisor.begin(), divisor.end());
        int find = -1;

        for (int i = 0; i < divisor.size(); i++) 
            if (divisor[i] > k) {
                find = i - 1;
                break;
            }

        sort(a.begin() + 1, a.end());

        while(find >= 0) {
            int temp = sum / divisor[find];
            if (dfs(1, 0, temp, 0)) {
                std::cout << temp;
                break;
            }
            find--;
        }

    
    }
    
}
