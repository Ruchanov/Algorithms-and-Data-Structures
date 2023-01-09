#include <bits/stdc++.h>

using namespace std;
char a[101][101];
int n, m;
void dfs(int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '0') return;
    a[i][j] = '0';
    dfs(i - 1, j, n, m);
    dfs(i + 1, j, n, m);
    dfs(i, j - 1, n, m);
    dfs(i, j + 1, n, m);
}  

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '1'){
                cnt++;
                // cout << i << j << endl;
                dfs( i, j, n, m);
            }

        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << cnt;

    return 0;
}