#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};
struct LL{
    Node* head = nullptr;
    int mx = -1;
    void insert(int val){
        if(val > mx) mx = val;
        Node* temp = new Node(val);
        if(!head){
            head = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }
    void pop(){
        bool test = true;
        if(head->val == mx){
            test = false;
        }
        if(head){
            if(!head->next){
                delete (head);
            }else{
                Node* toDelete = head;
			    head = head->next;
			    delete (toDelete);
            }
        }
        if(test == false){
            mx = getMax();
        }
    }
    // void getCur(){
    //     if(head == nullptr){
    //         cout << "error"<<endl;
    //     }else{
    //         cout << head->val<<endl;
    //     }
    // }
    int getMax(){
        Node* cur = head;
        int max = -1;
        while(cur){
            if(cur->val > max){
                max = cur->val;
            }
            cur = cur->next;
        }
        return max;
    }
};
int main(){
    LL l;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            l.insert(x);
        }if(s == "delete"){
            l.pop();
        }if(s == "getmax"){
            if(l.mx == -1){
                cout << "error"<<endl;
            }else{
                cout << l.mx << endl;
            }
        }if(s == "getcur"){
            if(l.head == nullptr){
                cout << "error"<<endl;
            }else{
                cout <<l.head->val<<endl;
            }
        }
    }
}