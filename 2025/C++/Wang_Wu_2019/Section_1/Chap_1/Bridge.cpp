#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin >> t; cin.ignore();
    while(t--) {
        int n;
        cin >> n;
        vector<int> times(n);
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }
        sort(times.begin(), times.end());
        
        int totalTime = 0;
        vector<vector<int>> moves;
        
        int person = n;
        
        while (person > 3) {
            int cost1 = times[1] + times[0] + times[person - 1] + times[1];
            int cost2 = times[person - 1] + times[0] + times[person - 2] + times[0];
            
            if(cost1 <= cost2) {
                moves.push_back({times[0], times[1]});
                moves.push_back({times[0]});
                moves.push_back({times[person - 2], times[person - 1]});
                moves.push_back({times[1]});
                totalTime += cost1;
            } else {
                moves.push_back({times[0], times[person - 1]});
                moves.push_back({times[0]});
                moves.push_back({times[0], times[person - 2]});
                moves.push_back({times[0]});
                totalTime += cost2;
            }
            person -= 2;
        }
        
        if(person == 3) {
            moves.push_back({times[0], times[1]});
            moves.push_back({times[0]});
            moves.push_back({times[0], times[2]});
            totalTime += times[0] + times[1] + times[2];
        } else if(person == 2) {
            moves.push_back({times[0], times[1]});
            totalTime += times[1];
        } else if(person == 1) {
            moves.push_back({times[0]});
            totalTime += times[0];
        }
        
        cout << totalTime << endl;
        for (auto step : moves) {
            for (auto person : step) {
                cout << person << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}