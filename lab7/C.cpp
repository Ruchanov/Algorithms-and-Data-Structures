#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int mid, int r){
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int ans[r + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            ans[k++] = a[i++];
        }else{
            ans[k++] = a[j++];
        }
    }
    while(i <= mid){
        ans[k++] = a[i++];
    }
    while(j <= r){
        ans[k++] = a[j++];
    }
    for(i = l; i <= r; i++){
        a[i] = ans[i];
    }
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);   
    int index = -1;
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }     
    // cout << endl;
    // for(int i = 0; i < m; i++){
    //     cout << b[i] << " ";
    // }     
    // cout << endl;
    
    for(int  i = 0; i < n; i++){
        for(int j = index + 1; j < m; j++){
            if(a[i] == b[j]){
                cout << a[i] << " ";
                index = j;
                break;
            }
        }
    }
    return 0;
}