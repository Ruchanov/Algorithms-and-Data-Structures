#include<bits/stdc++.h>
using namespace std;

struct MinHeap{
    vector<int> heap;
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while( i != 0 && heap[parent(i)] >= heap[i]){
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
};

int main(){
    MinHeap m;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        m.insert(x);
    }
    
}