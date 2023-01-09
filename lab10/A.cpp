#include <bits/stdc++.h>

using namespace std;
int a[1001][1001];
int n, m;
int main(){
    cin >> n >> m;
    int numMushrooms = 0;
    queue<pair<int, int> > mario;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                numMushrooms++;
            }
            if(a[i][j] == 2){
                mario.push({i,j});
            }
        }
    }
    int time = 0;
    while(!mario.empty()){
        int sizee = mario.size();
        if(numMushrooms == 0){
            break;
        }
        while(sizee--){
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++){
            //         cout << a[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            int i = mario.front().first;
            int j = mario.front().second;
            mario.pop();
            if (i > 0 && a[i - 1][j] == 1) {
		    	a[i - 1][j] = 2;
		    	mario.push({ i - 1, j });
		    	numMushrooms--;
		    }
		    if (a[i + 1][j] == 1) {
		    	a[i + 1][j] = 2;
		    mario.push({ i + 1, j });
		    	numMushrooms--;
		    }
		    if (j > 0 && a[i][j - 1] == 1) {
		    	a[i][j - 1] = 2;
		    	mario.push({ i, j - 1 });
		    	numMushrooms--;
		    }
		    if (a[i][j + 1] == 1) {
		    	a[i][j + 1] = 2;
		    	mario.push({ i, j + 1 });
		    	numMushrooms--;
		    }
        }
        time++;
    }
    if(numMushrooms != 0) cout << -1;
    else cout << time << endl;

    return 0;
}