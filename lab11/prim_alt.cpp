#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> g[100000];
bool used[100000];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a,c});
    }
    int weight = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 1});
    while(!q.empty()){
        pair<int, int> c = q.top();
        q.pop();
        int mst = c.first;
        int v = c.second;
        if(used[v]) continue;
        used[v] = true;
        weight += mst;
        for(pair<int, int> e: g[v]){
            int u = e.first;
            int length = e.second;
            if(!used[u]){
                q.push({length, u});
            }
        }
    }
    cout << weight;
    return 0;
}