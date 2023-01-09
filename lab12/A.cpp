#include <bits/stdc++.h>
using namespace std;

int main() {
    const int INF = 1e9;
    vector<vector<int> > d(501, vector<int> (505, INF));
    vector<vector<int> > vv(501, vector<int> (505, INF));
    int ans = 0;
    vector<int> arr;
    int n;  
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
            if (d[i][j] == 0 and i != j) d[i][j] = INF;
            if (i == j) vv[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int k; 
        cin >> k;
        arr.push_back(k);
        for (int j = 0; j < arr.size(); ++j) {
            vv[k][arr[j]] = d[k][arr[j]];
            vv[arr[j]][k] = d[arr[j]][k];
        } 
        ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                vv[arr[j]][k] = min(vv[arr[j]][k], vv[arr[j]][arr[i]] + vv[arr[i]][k]);
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                vv[k][arr[j]] = min(vv[k][arr[j]], vv[k][arr[i]] + vv[arr[i]][arr[j]]);
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                vv[arr[i]][arr[j]] = min(vv[arr[i]][arr[j]], vv[arr[i]][k] + vv[k][arr[j]]);
                if (vv[arr[i]][arr[j]] < INF and vv[arr[i]][arr[j]] > ans) 
                    ans = vv[arr[i]][arr[j]];
            }
        }    
        cout << ans << endl;
    }
    return 0;
}