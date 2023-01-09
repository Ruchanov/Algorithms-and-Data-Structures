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
    void change(int i, int val){
        heap[i - 1] += val;
        int ii = i - 1;
        while( ii != 0 && heap[parent(ii)] < heap[ii]){
            swap(heap[parent(ii)],heap[ii]);
            ii = parent(ii);
        }
        cout << ii + 1 << endl;
    }
};
int main(){
    MaxHeap m;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        m.insert(x);
    }
    int k;
    cin >> k;
    while(k--){
        int i,val;
        cin >> i >> val;
        m.change(i,val);
    }
    for(int i = 0; i < m.heap.size(); i++){
        cout << m.heap[i]<<" ";
    }
    return 0;
}