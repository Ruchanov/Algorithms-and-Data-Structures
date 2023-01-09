#include <iostream>
#include<set>
#include<cmath> 
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
int count_prime(int n){
    set<int> s;
    int i = 2;
    while(i <= n){
        if(n % i == 0 && isPrime(i)){
            s.insert(i);
            n /= i;
        }
        i++;
    }
    return s.size();
}

int main(){
    int n;
    cin >> n;
    cout << count_prime(n);
    return 0;
}