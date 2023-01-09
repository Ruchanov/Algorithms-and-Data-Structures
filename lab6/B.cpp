#include <bits/stdc++.h>

using namespace std;

bool binary_search(int a[], int n, int target){
    int l = 0;
    int r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == target) return true;
        if(a[mid] < target){
            l = mid + 1;
        }
        if(a[mid] > target){
            r = mid - 1;
        }
    }
    return false;
}

int partition(int a[], int l, int r){
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


void qsort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
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
    qsort(a, 0, n - 1);
    qsort(b, 0, m - 1);   
    int index = -1;     
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