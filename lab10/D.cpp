#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> colors;
vector<bool> visited;
int n, m, k;
int bfs(int v) {
    int dist = 0;
    if(colors[v] == 1) return 0;
	queue<pair<int, int>>  q;
    q.push({v, 0});
	visited[v] = true;
	while (!q.empty()) {
        //dist++; 
		int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visited[u]) {
                visited[u] = true;
                if(colors[u] == 1){
                    visited.assign(n,false);
                    return dist + 1;
                }else{
	    			q.push({u, dist + 1});
                }
			}
		}
	}
    visited.assign(n,false);
    return -1;
}

int main(){
    cin >> n >> m >> k;
    g.resize(n + 1);
    colors.resize(n + 1);
    visited.resize(n + 1);
    //colors.assign(n,0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(k--){
        int x, y;
        cin >> x >> y;
        if(x == 1){
            colors[y] = 1;
        }else{
            cout << bfs(y) << endl;
        }
    }

    return 0;
}