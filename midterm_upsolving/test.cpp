#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    while(k--){
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 65){
                s[i] = 90;
            }else{
                s[i] = s[i] - 1;
            }
        }
    }
    cout << s;
    return 0;
}