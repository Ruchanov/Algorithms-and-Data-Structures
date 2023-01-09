#include <iostream>
#include <deque>
using namespace std;
int main() {
    int x;
    cin>>x;
    deque<char> d;
    while(x--){
        char c;
        cin>>c;
        d.push_back(c);
    }
    int se = 0, k = 0, n = 0;
    while(d.size() > 1) {
        if(n == d.size()) {
            break;
        }
        else if(d.front() == 'S') {
            if(k == 0) {
                se++;
                d.push_back('S');
                d.pop_front();
                n++;
            } else {
                d.pop_front();
                k--;
                n = 0;
            }
        }
        else if(d.front() == 'K') {
            if(se == 0) {
                k++;
                d.push_back('K');
                d.pop_front();
                n++;
            } else {
                n = 0;
                d.pop_front();
                se--;
            }
        }
    }
    if(d.front() == 'S'){
        cout << "SAKAYANAGI";
    }else{
        cout << "KATSURAGI";
    }
    return 0;
}