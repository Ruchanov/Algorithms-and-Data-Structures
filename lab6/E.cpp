#include <bits/stdc++.h>

using namespace std;
int partition(int a[], int l, int r){
    int i = l - 1;
    int pivot = r;
    for(int j = l; j <= r - 1; ++j){
        if(a[j] > a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[m][n];
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        qsort(a[i], 0, n - 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}