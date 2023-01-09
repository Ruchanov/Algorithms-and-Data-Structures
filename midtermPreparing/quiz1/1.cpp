#include<iostream>
using namespace std;
struct Node{
    string val;
    Node* next;
    Node(string val){
        this->val = val;
        next = nullptr;
    }
};
struct LInkedList{
    Node* head = nullptr;
    void insert(string s){
        Node* cur = head;
        Node* temp = new Node(s);
        if(!cur){
            head = temp;
        }else{
            while(cur->next){
                cur = cur->next;
            }
            cur -> next = temp;
        }
    }
    Node* getTail(){
        Node* cur = head;
        while(cur->next){
            cur = cur->next;
        }
        return cur;
    }
    void shiftLeft(int k){
        Node* tail = getTail();
        tail->next = head;
        while(k--){
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
    }
    void print(){
        Node* cur = head;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }

};
int main(){
    LInkedList ll;
    int n,k;
    cin >> n >> k;
    while(n--){
        string s;
        cin >> s;
        ll.insert(s);
    }
    ll.shiftLeft(k);
    ll.print();
}