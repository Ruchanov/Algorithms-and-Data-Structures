#include <bits/stdc++.h>

using namespace std;
vector<int> merge(int a[], int b[], int n, int m){
    vector<int> v;
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            v.push_back(a[i]);
            i++;
        }else{
            v.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        v.push_back(a[i]);
        i++;
    }
    while(j < m){
        v.push_back(b[j]);
        j++;
    }
    return v;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> v = merge(a,b,n,m);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}