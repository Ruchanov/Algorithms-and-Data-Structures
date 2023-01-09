#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<bool> visited;
vector<int> colors;
vector<int> ans;
int n, m;
bool detectCycle(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			if (detectCycle(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}
void dfs(int v){
	visited[v] = true;
	for (int i=0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u])
			dfs(u);
	}
	ans.push_back(v);
}
void topological_sort() {
	for (int i = 0; i < n; i++)
		visited[i] = false;
	for (int i = n - 1; i >= 0; i--)
		if (!visited[i]){
			dfs (i);
        }
	reverse (ans.begin(), ans.end());
}
int main(){
    cin >> n >> m;
    g.resize(n);
    visited.resize(n);
    colors.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
		if (detectCycle(i)) {
			cout << "Impossible";
			return 0;
		}
	}
    topological_sort();
    cout << "Possible" << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1<< " ";
    }
    return 0;
}