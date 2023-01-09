#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int max = INT_MIN;
    int sum = 0;
    int res;
    int sumOfRow = 0;
    int rowmax=INT_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j]>=rowmax) {
                rowmax = a[i][j];
                sumOfRow+= a[i][j];
            }
        }
        if(max < rowmax){
            max = rowmax;
            res = i;
            sum = sumOfRow;
        }else if(max == rowmax && sum < sumOfRow){
            max = rowmax;
            res = i;
            sum = sumOfRow;
        }
        sumOfRow = 0;
        rowmax=INT_MIN;
    }
    cout << res;
    return 0;
}