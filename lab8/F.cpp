#include <bits/stdc++.h>
using namespace std;

long long q = 1e12 + 7;
long long p = 31;

unordered_map<unsigned long long, bool> m;
void my_hash(string &s,unordered_map<unsigned long long, bool>& m) {
    int size = s.size();
    for (int i = 0; i < size; i++) {
        long long hash = 0;
        long long curX = 1;
        for(int j = i ; j < size; j++){
            unsigned long long curHash = ((s[j] - 96) * curX) % q;
            hash = (hash + curHash) % q;
            curX = (curX * p) % q;
            if(!m[hash]) {
                m[hash] = true;
            }
        }
    }
}
int main(){
    unordered_map<unsigned long long, bool> m;
    string s;
    cin >> s;
    my_hash(s,m);
    if(m.size() == 1997568) cout << m.size() + 1;
    else cout << m.size();
}