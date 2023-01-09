#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> array, int target){
  int left = 0;
  int right = array.size() - 1;
    int res = -1;
  while (left <= right){
    int mid = left + (right - left) / 2;
    if (array[mid] <= target){
            res = mid;
            left = mid + 1;
        }
    else right = mid - 1;
  }
    if(res == -1) return 0;
    return res + 1;
}

int ans(vector<int> w, int l, int r){
    return binary_search(w, r) - binary_search(w, l - 1);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> v, result;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // l2 <= r2 <= l1 <= r1 || l1 <= r1 <= l2 <= r2 
        if(r2 < l1 || r1 < l2){
            int res = ans(v, l1, r1) + ans(v, l2, r2);
            cout << res << "\n";
        } 
        else{
            int mini = min(l1, l2);
            int maxi = max(r1, r2);
            cout << ans(v, mini, maxi) << "\n";
        }
    }     
}
