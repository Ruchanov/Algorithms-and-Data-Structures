#include <bits/stdc++.h>

using namespace std;

bool comp(string& s, string& s2){
    return s.size() <= s2.size();
}

vector<string> merge(vector<string> left, vector<string> right) {
	vector<string> result;
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

vector<string> merge_sort(vector<string> a, int l, int r) {
	if (l == r) {
		vector<string> result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<string> left = merge_sort(a, l, m);
	vector<string> right = merge_sort(a, m + 1, r);
	return merge(left, right);
}


int main(){
    string n;
	getline(cin,n);
	int k = stoi(n);
    for(int j = 0; j < k; j++){
        string s;
        getline(cin,s);
        // s += ' ';
        vector<string> v;
	    string t = "";
	    for (int i = 0; i < s.length(); i++) {
		    if (s[i] != ' ') {
			    t += s[i];
		    } else if (s[i] == ' ') { 
			    v.push_back(t);
			    t = "";
		    }
        }
        if(t.size() != 0) v.push_back(t);
        vector<string> ans = merge_sort(v, 0, v.size() - 1);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}