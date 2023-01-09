#include <bits/stdc++.h>

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
void KMP(string txt, string pat,int n) {
	//vector<int> ans;
    int cnt = 0;
	string concat = pat + '#' + txt;
	vector<int> pi = prefixFunction(concat);
	for (int i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
            cnt++;
            if(cnt == n){
                cout <<"YES";
                return;
            }
			//ans.push_back(i - 2 * pat.size());
		}
	}
    cout << "NO";
    //return ans;
}
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    string t;
    cin >> t;
    KMP(t,s,n);
    return 0;
}