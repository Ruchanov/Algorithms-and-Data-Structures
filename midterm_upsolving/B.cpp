#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if( n == 0 || n == 1) return false;
    for(int i = 2; i < int(sqrt(n)) + 1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int l = 2;
    int r = n - 2;
    while(true){
        if( isPrime(l) && isPrime(r)){
            cout << l << " " << r;
            return 0;
        }
        l++;
        r--;
    }
}