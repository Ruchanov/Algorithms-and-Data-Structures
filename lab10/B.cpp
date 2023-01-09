#include <bits/stdc++.h>

using namespace std;
int a[101][101];
int bfs(int v,int n, int x) {
	int cnt = 0;
    queue<int> q;
	q.push(v);
	while (!q.empty()) {
        cnt++;
		int cur = q.front();
		for (int i = 0; i < n; i++) {
			if (a[cur][i] == 1) {
                a[cur][i] = 2;
                a[i][cur] = 2;
                if(i == x){
                    return cnt;
                }
				q.push(i);
			}
		}
		q.pop();
	}
    return -1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    cout << bfs(a - 1,n,b - 1);
    return 0;
}