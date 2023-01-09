#include <bits/stdc++.h>

using namespace std;
#define unll unsigned long long
int my_hash(string s) {
    unll p = 1;
    unll q = 1e9 + 7;
    int x = 11;
    unll answer = 0;
    for (int i = 0; i < s.size(); i++) {
      //answer += ((s[i] - 48 + 1) * p) % q;
      answer = (answer + ((s[i] - 47) * p) % q) % q;
      p = (p * x) % q;
      //p *= x;
    }
    return answer;
}

int main(){
    long long n;
    cin >> n;
    long long limit = n;
    n = n*2;
    vector <string> v;
    string x;
    map<string, bool> exist;
    map<string, string> hash;
    for(long long i = 0; i < n; i++){
        cin >> x;
        string num = to_string(my_hash(x));
        exist[x] = true;
        hash[x] = num;
        v.push_back(x);
    }
    long long cnt = 0;
    for(auto c : v){
        if(exist[hash[c]] && cnt < limit){
            cnt++;
            printf("Hash of string \"%s\" is %s\n", c.c_str(), hash[c].c_str());
        }
    }

    return 0;
}