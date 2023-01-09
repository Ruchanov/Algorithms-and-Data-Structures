#include <iostream> 
#include <vector> 
#include <set> 
using namespace std; 

int INF = 1000000000; 
vector<pair<int,int>> g[200001];  
int n,m; 

int deikstra(int s, int end){ 
    vector<int> d(200001, INF); 
    d[s] = 0; 
    set< pair<int,int> > q; 
    q.insert(make_pair(d[s],s)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
                q.erase(make_pair(d[to], to)); 
                d[to] = d[v] + len; 
                q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 
int main(){ 
    cin >> n >> m; 
    while(m--){ 
        int a,b,c; 
        cin >> a >> b >> c; 
        g[a].push_back({b,c}); 
        g[b].push_back({a,c}); 
    } 
    int q,w,e,r; 
    cin >> q >> w >> e >> r;  
    int x = deikstra(q,w) + deikstra(w,e) + deikstra(e,r); 
    int y = deikstra(q,e) + deikstra(e,w) + deikstra(w,r) ; 
    if(x < y && x <= INF){
        cout << x;
    }else if( x >= y && y <= INF){
        cout << y;
    }else{
        cout << -1;
    }
    return 0; 
}