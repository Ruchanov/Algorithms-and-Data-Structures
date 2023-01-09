#include <bits/stdc++.h>

using namespace std;
struct MinHeap{
    vector<int> heap;
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    void insert(int x){
        heap.push_back(x);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] >= heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    int extractMin(){
        if( heap.size() == 0) return INT_MIN;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]){
            smallest = l;
        }if(r < heap.size() && heap[r] < heap[smallest]){
            smallest = r;
        }if(smallest != i){
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }
};

int main(){
    return 0;
}