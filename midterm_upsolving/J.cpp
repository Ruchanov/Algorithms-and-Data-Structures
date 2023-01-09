#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v,int target, int sum, int begin){
    int l = begin;
    int r = v.size() - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(v[mid] + target > sum){
            r = mid - 1;
        }
        if(v[mid] + target < sum){
            l = mid + 1;
        }if(v[mid] + target == sum){
            return v[mid];
        }
    }
    return 0;
}


int main(){
    long long sum;
    cin >> sum;
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        int l = i+1;
        int r = v.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(v[mid] + v[i] > sum){
                r = mid - 1;
            }
            if(v[mid] + v[i] < sum){
                l = mid + 1;
            }if(v[mid] + v[i] == sum){
                cout<<v[i]<<" "<<v[mid];
                return 0;
            }
        }
    }
}