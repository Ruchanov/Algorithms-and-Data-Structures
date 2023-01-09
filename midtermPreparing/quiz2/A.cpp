#include<bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int> heap;
    int parent(int i){
        return(i - 1) / 2;
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
        while(i != 0 && heap[parent(i)] <= heap[i]){
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }

    int extractMax(){
        if(heap.size() == 0) return INT_MAX;
        if(heap.size() == 1){
            int res = heap[0];
            heap.pop_back();
            return res;
        }
        int res = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return res;
    }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int biggest = i;
        if(l < heap.size() && heap[l] > heap[biggest]){
            biggest = l;
        }
        if(r < heap.size() && heap[r] > heap[biggest]){
            biggest = r;
        }
        if(biggest != i){
            swap(heap[i],heap[biggest]);
            heapify(biggest);
        }
    }
};

int main(){
    MaxHeap m;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int i = 1; i <= x; i++){
            m.insert(i);
        }
    }
    for(int i = 0; i < m.heap.size(); i++){
        cout << m.heap[i] << " "; 
    }
    int res = 0;
    while(k--){
        res += m.extractMax();
    }
    cout << res;
}