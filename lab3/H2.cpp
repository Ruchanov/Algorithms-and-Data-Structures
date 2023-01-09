#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    v.push_back(1);
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n*2; i+=2){
        v.push_back(v[i-1] + a[i] -1);
        v.push_back(v[i] + 1);
    }
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

}