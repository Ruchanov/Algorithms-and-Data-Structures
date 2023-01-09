#include <bits/stdc++.h>

using namespace std;
vector<int> merge(vector<int> l, vector<int> r) {
	vector<int> answer;
	int l1 = 0, r1 = 0;
	while (l1 < l.size() && r1 < r.size()) {
		if (l[l1] < r[r1]) {
			answer.push_back(l[l1++]);
		} else {
			answer.push_back(r[r1++]);
		}
	}
	while (l1 < l.size()) {
		answer.push_back(l[l1++]);
	}
	while (r1 < r.size()) {
		answer.push_back(r[r1++]);
	}
	return answer;
}

int main(){
    vector<int> v,v1;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    vector<int> answer = merge(v,v1);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}