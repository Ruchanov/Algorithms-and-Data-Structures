#include <bits/stdc++.h>

using namespace std;
int partition(char a[], int l, int r){
    int i = l - 1;
    int pivot = r;
    for(int j = l; j < r; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(char a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}
int main(){
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    char c;
    cin >> c;
    qsort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        if(a[i] > c){
            cout << a[i];
            break;
        }
        if( i == n - 1){
            cout << a[0];
            break;
        }
    }
    return 0;
}