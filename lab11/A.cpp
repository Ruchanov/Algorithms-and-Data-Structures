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
	comp[u] = v;
}


int main() {
	int n, m;
	cin >> n >> m;
	comp.resize(n);
	vector<pair<int, pair<int, int> > > g;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
        y--;
		g.push_back({z,{x,y}});
        // for(int k = x ; k < y; k++){
        //     for(int j = k + 1; j <= y; j ++){
        //         g.push_back({z,{k,j}});
        //     }
        // }
	}
	sort(g.begin(), g.end());

	for (int i = 0; i < n; i++) {
		comp[i] = i;
	}

	long long sum = 0;
	for (int i = 0; i < g.size(); ++i) {
		int x = g[i].second.first;
		int y = g[i].second.second;
		int c = g[i].first;
		for(int j = x + 1; j <= y; j++){
			if (dsuGet(x) != dsuGet(j)) {
				dsuUnite(x, j);
				sum += c;
			}else{
				j = comp[x];
			}
		}
	}
	cout << sum;
	return 0;
}