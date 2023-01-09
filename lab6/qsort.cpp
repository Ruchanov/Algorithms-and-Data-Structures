#include <iostream>

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


void qsort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}

int main(){

    int a[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(a)/sizeof(int);

    qsort(a, 0, n - 1);

    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }

    return 0;
}