#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    int ii, sum = 0, maxx = 0 ;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int rowsum = 0, rowmax = 0, t;
        for(int j = 0; j < m; ++j){
            cin >> t;
            rowsum += t;
            rowmax = max(t, rowmax);
        }
        if(rowmax > maxx){
            maxx = rowmax;
            ii = i;
            sum = rowsum;
        }
        else if(maxx == rowmax && rowsum > sum){
            maxx = rowmax;
            ii = i;
            sum = rowsum;
        }
    }
    cout << ii;
    return 0;
}