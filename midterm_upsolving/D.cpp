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
    //cin >> n;
    int cnt = 0;
    if(isPrime(5));
    cout<<isPrime(2);
    //cout << cnt;
}