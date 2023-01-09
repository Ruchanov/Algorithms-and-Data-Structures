#include <bits/stdc++.h>
using namespace std;
vector<int> comp;
int dsuGet(int v) {
	if (v == comp[v]) return v;
	else return comp[v] = dsuGet(comp[v]);
}

void dsuUnite(int u, int v) {
	u = dsuGet(u);
	v = dsuGet(v);
	if (rand() & 1) {
		swap(u, v);
	}
	if (u != v) {
		comp[u] = v;
	}
}


int main() {
	int n;
	cin >> n;
	comp.resize(n);
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
	vector<pair<int, pair<int, int> > > g;
	for (int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++){
            g.push_back({v[i] + v[j],{i,j}});
        }
	}
	sort(g.begin(), g.end());

	for (int i = 0; i < n; i++) {
		comp[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < g.size(); i++) {
		int x = g[i].second.first;
		int y = g[i].second.second;
		int c = g[i].first;
		if (dsuGet(x) != dsuGet(y)) {
			sum += c;
			dsuUnite(x, y);
		}
	}
	cout << sum;
	return 0;
}