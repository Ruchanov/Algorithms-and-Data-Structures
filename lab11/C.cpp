#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int dsuGet(int v) {
	if (v == p[v]) return v;
	else return p[v] = dsuGet(p[v]);
}

void dsuUnite(int u, int v) {
	u = dsuGet(u);
	v = dsuGet(v);
	if (rand() & 1) {
		swap(u, v);
	}
	if (u != v) {
		p[u] = v;
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	p.resize(n);
	int x, y;
	cin >> x >> y;
	vector<pair<int, pair<int, int> > > g;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		string s;
		cin >> s >> u >> v >> w;
		u--; v--;
		if(s == "both"){
			g.push_back({ w * min(x,y), {u, v} });
		}else if(s == "big"){
			g.push_back({ w * x, {u, v} });
		}else if(s == "small"){
			g.push_back({ w * y, {u, v} });
		}
	}
	sort(g.begin(), g.end());

	for (int i = 0; i < n; i++) {
		p[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < m; i++) {
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