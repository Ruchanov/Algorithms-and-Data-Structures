#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int l, int r){
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


void qsort(vector<int>& a, int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        qsort(a, l, pivot - 1);
        qsort(a, pivot + 1, r);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    qsort(v,0,n - 1);
    int dif = INT_MAX;
    for(int i = 1; i < v.size(); i++){
        if(abs(v[i] - v[i - 1]) < dif){
            dif = abs(v[i] - v[i - 1]);
        }
    }
    for(int i = 1; i < v.size(); i++){
        if(abs(v[i] - v[i - 1]) == dif){
            cout << v[i - 1]<< " " << v[i] << " ";
        }
    }
    return 0;
}