#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long q = 1e9 + 7;
long long p = 31;

map<int, int> ma;

long long my_hash(string & s) {
    long long hash = 0;
    long long curP = 1;
    for (int i = 0; i < s.size(); i ++){
        long long curHash = (s[i] - 'a' + 1) * curP % q;
        hash = (hash + curHash) % q;
        curP = (curP * p) % q;
    }
    return hash;
}

int rabinKarp(string & s, string & t) {
    int ans = 0;
    if (t.size() > s.size()) return 0;
    long long smallHash = my_hash(t);
    vector<long long> hashes(s.size());
    long long curP = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % q;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % q;
        }
        curP = (curP * p) % q;
    }
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += q;
        if (i) smallHash = (smallHash * p) % q;
        if (smallHash == hashDiff){
            if (ma.find(i) != ma.end()){
                ans++;
            }
            ma[i] = 1;
        }
    }
    return ans;
}

int main() {
    string s, s1, t;
    cin >> s >> s1 >> t;
    int x = rabinKarp(s, t);
    int y =rabinKarp(s1, t);
    cout << x + y << endl;
    return 0;
}
