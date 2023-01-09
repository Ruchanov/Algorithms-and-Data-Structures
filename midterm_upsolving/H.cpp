#include<bits/stdc++.h>
using namespace std;

struct MaxHeap{
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return i * 2 + 1; 
    }
    int right(int i){
        return i * 2 + 2;
    }
    vector<int> heap;
    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while( i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }
    void heapify( int i){
        int l = left(i);
        int r = right(i);
        int biggest = i;
        if(l < heap.size() && heap[biggest] < heap[l]){
            biggest = l;
        }
        if(r < heap.size() && heap[biggest] < heap[r]){
            biggest = r;
        }
        if(biggest != i){
            swap(heap[biggest],heap[i]);
            heapify(biggest);
        }
    }
};
int main(){
    MaxHeap m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m.insert(x); 
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(m.left(i) < n && m.right(i) < n && m.heap[m.left(i)] < m.heap[m.right(i)]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}