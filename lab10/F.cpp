#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> visit;
void bfs(int v, int x) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		for (int i = 0; i < g[cur].size(); i++) {
			int u = g[cur][i];
			if (!visit[u]) {
				visit[u] = true;
				q.push(u);
                if(u == x){
                    cout << "YES";
                    return;
                }
			}
		}
		q.pop();
	}
    cout << "NO";
}

int main() {
	int m, n;
	cin >> m >> n;
	g.resize(m);
    visit.resize(m);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
        x--;
        y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
    int x, y;
    cin >> x >> y;
    bfs(x - 1,y - 1);
	return 0;
}