#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> d;
vector<int> p;

void findd(int a, int b){
	queue<int> q;
    q.push(a);
    d[a] = 0;
    p[a] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int x = v * 2;
        int y = v - 1;
        if(d[x] > d[v] + 1){
            d[x] = d[v] + 1;
            q.push(x);
            p[x] = v;
        }
        if(d[y] > d[v] + 1){
            d[y] = d[v] + 1;
            q.push(y);
            p[y] = v;
        }
    } 
}

int main(){
    int a, b;
    cin >> a >> b;
	findd(a,b);
    cout << d[b - 1] << endl;
    vector<int> v;
    for(int i = b; i != a; i = p[i]){
        v.push_back(i);
    }
    for(int i = v.size() -1; i >= 0; i--){
        cout << v[i] << " ";
    }
}


