#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* next;
    int val;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
    // Node(){
    //     val = 0;
    //     next = nullptr;
    // }
};
struct LinkedList
{
    Node* head = nullptr;
    //Node* tail = nullptr;
    int size = 0;
    LinkedList(){
        head = nullptr;
        //tail = nullptr;
    }
    Node* getTail(){
        Node* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        return cur;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(size == 0){
            head = newNode;
            //tail = newNode;
            size++;
        }else{
            //Node* h = head;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(size == 0){
            head = newNode;
            //tail = newNode;
            size++;
        }else{
            Node* cur = head;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = newNode;
            size++;
            // tail->next = newNode;
            // tail = newNode;
        }
    }
    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* cur = head;
        size++;
        if(pos == 0){
            newNode->next = head;
            head = newNode;
            return;
        }
        while(--pos){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    Node* pop_front(){
        if(!head->next){
            Node* ret = head;
            head = nullptr;
            //tail = nullptr;
            return ret;
        }
        Node* node = head;
        head = head->next;
        size--;
        return node;
    }
    Node* pop_back(){
        if(!head->next){
            Node* ret = head;
            head = nullptr;
            //tail = nullptr;
            return ret;
        }
        Node* cur = head;
        while(cur->next->next){
            cur = cur->next;
        }
        Node* ret = cur->next;
        cur->next = nullptr;
        size--;
        //tail = cur;
        return ret;
    }
    Node* remove(int pos){
        Node* cur = head;
        if(pos == 0){
            return pop_front();
        }
        while(--pos){
            cur = cur->next;
        }
        Node* res = cur->next;
        cur->next = cur->next->next;
        size--;
        return res;
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
    void shiftRight(int k){
        shiftLeft(size-k);
    }
    void replace(int pos1,int pos2){
        Node* node = remove(pos1);
        insert(node->val,pos2);
    }
    void swap(int pos1,int pos2){
        replace(pos1,pos2);
        replace(pos2-1,pos1);

    }
    Node* middleNode(){
        Node* fast = head;
        Node* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
    }

};

int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.print();
    cout<<ll.middleNode()->val;
    return 0;
}