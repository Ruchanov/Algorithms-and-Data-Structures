#include <iostream>

using namespace std;


int biggestDiv(int a) {
    int maxdiv = 1;
    for (int i=1; i<a; i++) {
        if (a%i==0) {
            maxdiv = i;
        }
    } 
    return maxdiv;
}

int cntdiv(int a) {
    int cnt = 0;
    for (int i=1; i<a; i++) {
        if (a%i==0) {
            cnt++;
        }
    } 
    return cnt;
}
int sum =0;

int formula (int n) {
    if (n==1) return sum + 1;
    sum += cntdiv(n);
    return formula (biggestDiv(n));
}

int main () {
    int n;
    cin >> n;
    cout << formula(n);
    return 0;

}