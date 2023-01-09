#include <bits/stdc++.h>
using namespace std;

long long q = 1e9 + 7;
long long P = 31;

long long my_hash(string & s) {
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i ++){
        long long curHash = (s[i] - 'a' + 1) * curP % q;
        hash = (hash + curHash) % q;
        curP = (curP * P) % q;
    }
    return hash;
}
void rabinKarp(string & s, pair<string, int> & t, int & mx) {
    if (t.first.size() > s.size()) return;
    long long smallHash = my_hash(t.first);
    vector<long long> hashes(s.size());
    long long curP = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % q;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % q;
        }
        curP = (curP * P) % q;
    }
    for (int i = 0; i < s.size() - t.first.size() + 1; i ++){
        long long hashDiff = hashes[i + t.first.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += q;
        if (i) smallHash = (smallHash * P) % q;
        if (smallHash == hashDiff){
            t.second++;
            mx = max(mx, t.second);
        }
    }
}

int main() {
    while(true){
        int q;
        cin >> q;
        if (q == 0) break;
        pair<string,int> str[q];
        for (int i = 0; i < q; i++){
            cin >> str[i].first;
            str[i].second = 0;
        }
        string s;
        cin >> s;
        int mx = -1;
        for (int i = 0; i < q; i ++){
            rabinKarp(s, str[i], mx);
        }
        cout << mx << endl;
        for (int i = 0; i < q; i ++){
            if (str[i].second == mx){
                cout << str[i].first << endl;
            }
        }
    }
}