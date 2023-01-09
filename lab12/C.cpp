#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

vector<int>road[401]; 
vector<int>airlines[401]; 
int ar[401][401];
void a(vector<int> road[401], queue<int>& q, vector<int>& d1, vector<bool>& used1){
    while(!q.empty()){ 
        int v = q.front(); 
        q.pop(); 
        for(int i = 0; i < road[v].size(); i++){ 
            int to = road[v][i]; 
            if(!used1[to]){ 
                used1[to] = true; 
                q.push(to); 
                d1[to] = d1[v]+1; 
            } 
        } 
    } 
} 

int main(){ 
    int n,m; 
    cin >> n >> m;
    while(m--){ 
        int a,b; 
        cin >> a >> b; 
        a--; 
        b--; 
        road[a].push_back(b); 
        road[b].push_back(a); 
        ar[a][b] = 1; 
        ar[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (ar[i][j] == 0 && i != j){ 
                airlines[i].push_back(j); 
            } 
        } 
    } 
    queue<int> q1, q2; 
    vector<int> d1(n + 1), d2(n + 1); 
    vector<bool> used1(n + 1), used2(n + 1);  
    q1.push(0); 
    used1[0] = true; 
    q2.push(0); 
    used2[0] = true; 
    a(road, q1, d1, used1);
    a(airlines, q2, d2, used2);
    if (!used1[n-1] || !used2[n-1]){ 
        cout << -1; 
    } 
    else { 
        if(d1[n - 1] > d2[n - 1]){
            cout << d1[n - 1];
        }else{
            cout << d2[n - 1];
        } 
    } 
}