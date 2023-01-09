#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g(200001);
vector<int> comp;
int dsuGet(int v) {
	if (v == comp[v]) return v;
	else return comp[v] = dsuGet(comp[v]);
}

bool dsuUnite(int u, int v) {
	u = dsuGet(u);
	v = dsuGet(v);
	if (u != v) {
		comp[u] = v;
        return true;
	}
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    comp.resize(n);
    for(int i = 0; i < n; i++){
        comp[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // sort(g.begin(), g.end());
    int cnt = 0;
    vector<int> v;
    for(int i = n - 1; i >= 0; i--){
        v.push_back(cnt);
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] > i){
                if(dsuUnite(i, g[i][j]))
                cnt--;
                dsuUnite(i, g[i][j]);
            }
        }
    }
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << endl;
    }
    return 0;
}
