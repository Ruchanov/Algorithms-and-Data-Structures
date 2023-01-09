#include <bits/stdc++.h>

using namespace std;
bool comp(pair<vector<int>,int>& a, pair<vector<int>,int>& b){
    if(a.second == b.second){
        for(int i = 0; i < a.first.size(); i++){
            if(a.first[i] != b.first[i]){
                return a.first[i] < b.first[i];
            }
        }
    }
    return a.second > b.second;
}
vector<pair<vector<int>,int>> merge(vector<pair<vector<int>,int>> left, vector<pair<vector<int>,int>> right) {
	vector<pair<vector<int>,int>> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (comp(left[l], right[r])) {
			result.push_back(left[l++]);
		} else {
			result.push_back(right[r++]);
		}
	}
	while (l < left.size()) {
		result.push_back(left[l++]);
	}
	while (r < right.size()) {
		result.push_back(right[r++]);
	}
	return result;
}

vector<pair<vector<int>,int>> merge_sort(vector<pair<vector<int>,int>> a, int l, int r) {
	if (l == r) {
		vector<pair<vector<int>,int>> result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<pair<vector<int>,int>> left = merge_sort(a, l, m);
	vector<pair<vector<int>,int>> right = merge_sort(a, m + 1, r);
	return merge(left, right);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>,int>> v; 
    for(int i = 0; i < n; i++){
        vector<int> temp;
        int sum = 0;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            temp.push_back(x);
            sum += x;
        }
        v.push_back(make_pair(temp,sum));
    }
    vector<pair<vector<int>,int>> ans = merge_sort(v, 0, v.size() - 1);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].first.size(); j++){
            cout << ans[i].first[j] << " ";
        }
        cout << endl;
    }
    return 0;
}