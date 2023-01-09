#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};

struct LinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;
    void push_back(int x){
        Node* cur = head;
        Node* newNode = new Node(x);
        if(!cur){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    // void reverse(){
    //     Node* prev = nullptr;
    //     Node* cur = head;
    //     tail = head;
    //     Node* temp;
    //     while(cur){
    //         temp = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = temp;
    //     }
    //     head = prev;
    // }
    void print(){
        Node* cur = head;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};
int main(){
    LinkedList ll;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            ll.push_back(y);
        }if(x == 2){
            //ll.reverse();
        }
    }
    ll.print();
    return 0;
}