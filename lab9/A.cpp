#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s) {
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
vector<int> KMP(string txt, string pat) {
	vector<int> ans;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			ans.push_back(i - 2 * pat.size());
		}
	}
	return ans;
}

int main() {
	string s, t;
	cin >> s >> t;
	string s2 = s;
	int cnt = 1;
	while (s.size() < t.size()) {
		s += s2;
		cnt++;
	}
    vector<int> v = KMP(s,t);
	if (v.size() != 0) {
		cout << cnt;
		return 0;
	}
    vector<int> v2 = KMP(s + s2,t);
	if (v2.size() != 0) {
		cnt++;
        cout << cnt;
		return 0;
	}
	cout << -1;
	return 0;
}