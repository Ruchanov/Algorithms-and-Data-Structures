#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
const int INF = 1e9;


int main(){
    int n;
    vector<pair<int, int> > g[MAXN];
    int d[MAXN];
    set<pair<int, int> > ss;
    cin >> n;
    pair<int, int> city[n];
    for(int i = 0; i < n ; i++){
        int x, y; cin >> x >> y;
        city[i] = make_pair(x, y);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(city[i].first - city[j].first) + abs(city[i].second-city[j].second);
            g[i+1].push_back(make_pair(j+1, w));
            g[j+1].push_back(make_pair(i+1, w));
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == 1) d[i] = 0;
        else{d[i] = INF;}
        ss.insert(make_pair(d[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair<int, int> p = *(ss.begin());
        ss.erase(p);

        int u = p.second;
        int du = p.first;

        if(du == INF) break;

        for(int j = 0; j< g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > w && d[v] > d[u]){
                ss.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                ss.insert(make_pair(d[v], v));
            }
        }
    }
    cout << d[n];
    return 0;
}