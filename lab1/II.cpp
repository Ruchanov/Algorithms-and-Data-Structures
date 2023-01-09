#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<char> q;
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        q.push(c);
    }
    
    return 0;
}