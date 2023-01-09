#include <bits/stdc++.h>
using namespace std;
unsigned long long p = 1;
char from_hash(unsigned long long n) {
	char ans = (n / p) + 97;
	p *= 2;
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<unsigned long long> v;
	for(int i = 0; i < n; i++){
        unsigned long long x;
        cin >> x;
        v.push_back(x);
    }
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cout << from_hash(v[i]);
		}else{
		    cout << from_hash(v[i] - v[i - 1]);
        }
    }
	return 0;
}