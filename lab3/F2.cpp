#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> binary_search(int a[], int target,int size){
    int left = 0, right = size, mid, sum = 0;
    while (left < right){
        mid = left + (right - left) / 2;
        if (target == a[mid]){
            while (mid + 1 < size && a[mid + 1] == target){
                mid++;
            }
            break;
        }else if (target < a[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    while (mid > -1 && a[mid] > target){
        mid--;
    }
    for (int i = 0; i <= mid; i++){
        sum += a[i];
    }
    return {mid + 1, sum};
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int q;
    cin >> q;
    while (q--){
        int power;
        cin >> power;
        vector<int> res = binary_search(a, power,n);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}


