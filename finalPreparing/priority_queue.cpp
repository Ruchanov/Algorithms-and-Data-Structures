#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    priority_queue<int> pq;
    q.push(3);
    q.push(1);
    q.push(5);
    pq.push(3);
    pq.push(1);
    pq.push(5);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}