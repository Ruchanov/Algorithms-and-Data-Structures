#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long MOD = 1e9 + 9;
long long P = 11;


long long getHash(string & s) {
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i ++){
        long long curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string & s) {
    long long curP = 1;
    vector<long long> hashes(s.size());
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % MOD;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}

void rabinKarp(string & s, string & t, vector<long long> & hashes, bool legit[]) {
    int ans = 0;
    long long smallHash = getHash(t);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += MOD;
        if (i) smallHash = (smallHash * P) % MOD;
        if (smallHash == hashDiff){
            for (int ii = i; ii < i + t.size(); ii++){
                legit[ii] = true;
            }
        }
    }
}


int main() {
    string s;
    cin >> s;
    vector<long long> hashes = getPrefixHashes(s);
    bool legit[s.size()];
    for (int i = 0; i < s.size(); i ++){
        legit[i] = false;
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        rabinKarp(s, str, hashes, legit);
//        for (int i = 0; i < s.size(); i ++){
//            cout << legit[i] << " ";
//        }
//        cout << endl;

    }

    for (int i = 0; i < s.size(); i ++){
        if (!legit[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
