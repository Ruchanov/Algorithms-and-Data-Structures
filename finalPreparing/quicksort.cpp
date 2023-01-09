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
        quick_sort(a,pivot + 1, r);

    }
}

int main(){
    

    return 0;
}