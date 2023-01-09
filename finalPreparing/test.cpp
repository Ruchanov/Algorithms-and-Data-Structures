#include <bits/stdc++.h>

using namespace std;
void function(vector<int> q){
    int temp;
    if(q.size() != 0){
        temp = q.front();
        q.erase(q.begin());
        // function(q);
        q.push_back(temp);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(1);
    q.push(1);
    q.push(1);

    return 0;
}