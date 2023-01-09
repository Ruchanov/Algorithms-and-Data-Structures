#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<vector<int>> g;
vector<bool> visited;
void bfs(int v){   
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for( int i = 0;i < g[u].size(); i++){   
            int children = g[u][i];
            if(!visited[children]){
                visited[children] = true;
                if (g[children].size() > g[u].size()){
                    cnt += 1;
                }
                q.push(children);
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < g.size(); i++){
        if(!visited[i]){
            cnt++;
            bfs(i);
        }
    }
    cout << cnt;
    return 0;
}