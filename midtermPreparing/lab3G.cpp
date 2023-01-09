#include<bits/stdc++.h>
using namespace std;
string binarySearch(vector<int>& v, int val){
    int l = 0;
    int r = v.size() - 1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid] == val){
            return "YES";
        }if(v[mid] < val){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return "NO";
}

int main(){
    int n,k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        cout << binarySearch(v,x)<<endl;
    }
    return 0;
}
