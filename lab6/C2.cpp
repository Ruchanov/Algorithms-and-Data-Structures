#include <bits/stdc++.h>

using namespace std;
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


void quick_sort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        quick_sort(a, l, pivot - 1);
        quick_sort(a, pivot + 1, r);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quick_sort(a,0,n - 1);
    int min = abs(a[1]-a[0]);
    for(int i = 0; i < (n-1); i++){
        int temp = abs(a[i]-a[i+1]);
        if (temp <= min){
            min = temp;
        }
    }
    for(int i = 0; i < (n-1); i++){
        int temp = abs(a[i]-a[i+1]);
        if (temp == min){
            cout << a[i] << " " << a[i + 1] << " ";
        }
    }
    return 0;
}