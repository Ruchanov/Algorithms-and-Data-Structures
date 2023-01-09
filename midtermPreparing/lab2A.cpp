#include <iostream>
using namespace std;


bool ok = true;

struct Node{
    unsigned long val;
    Node* next;
    Node* prev;
    Node (unsigned long x) {
        this->val = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


struct LinkedList{
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:

    void push(unsigned long val){
        Node * newNode = new Node(val);
        if (head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void remove(unsigned long val){
        Node * cur = head;
        while(cur != nullptr){
            if (cur -> val == val) {
                if (cur->prev) {
                    if (cur->next) {
                        cur->prev->next = cur->next;
                        cur->next->prev = cur->prev;
                    } else {
                        tail = cur->prev;
                        tail->next = nullptr;
                    }
                    break;
                } else {
                    if (cur->next) {
                        head = cur->next;
                        head->prev = nullptr;
                    } else {
                        head = tail = nullptr;
                    }
                    break;
                }
            }
            cur = cur -> next;
            if (cur == nullptr){
                cout << "ERROR" << endl;
                ok = false;
                return;
            }
        }

    }


    void print(){
        if (head == nullptr){
            cout << "EMPTY" << endl;
            return;
        }
        Node * cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    bool isEmpty(){
        return head == nullptr;

    }


    void sort() {
        if (head == nullptr) return;
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            while (nx) {
                if (cur->val > nx->val) {
                    unsigned long tmp = cur->val;
                    cur->val = nx->val;
                    nx->val = tmp;
                }
                nx = nx->next;
            }
            cur = cur->next;
        }
    }
};

int main() {
//    freopen("/Users/altair/CLionProjects/KBTU/input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LinkedList list;
    string s;
    while (cin>>s) {
        string n = "";
        for (int i = 1; i < s.size(); i++){
            n += s[i];
        }
        //stoi = string to int
        unsigned long val = stoi(n);
        if (s[0] == '+'){
            list.push(val);
        }
        else if (s[0] == '-'){
            if (list.isEmpty()){
                cout << "ERROR" << endl;
                return 0;
            }
            else{
                list.remove(val);
                if (!ok){
                    return 0;
                }
            }
        }
    }
    list.sort();
    list.print();
    return 0;
}