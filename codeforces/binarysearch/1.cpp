#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> v, int k){
    int left = 0;
    int right = v.size() - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] == k){
            return mid + 1;
        }else if( v[mid] > k){
            right = mid -1;
        }else if(v[mid] < k){
            left = mid + 1; 
        }
    }
    return right + 1; 
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int x = 5 *  i;
        sum += x;
        v.push_back(sum);
    }
    cout << binary_search(v,240-k);
}