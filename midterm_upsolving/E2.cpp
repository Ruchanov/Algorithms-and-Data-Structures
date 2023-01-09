#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};
Node* insert(int val,Node* head){
    Node* temp = new Node(val);
    if(!head){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
    return head;
}
Node* pop(Node* head){
    if(head){
        if(!head->next){
            delete (head);
        }else{
            Node* toDelete = head;
		    head = head->next;
			delete (toDelete);
        }
    }
    return head;
}
Node* getCur(Node* head){
    if(head == nullptr){
        cout << "error"<<endl;
    }else{
        cout << head->val<<endl;
    }
    return head;
}
Node* getMax(Node* head){
    Node* cur = head;
    int max = 0;
    while(cur){
        if(cur->val > max){
            max = cur->val;
        }
        cur = cur->next;
    }
    cout << max<<endl;
    return head;
}
int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            head = insert(x,head);
        }if(s == "delete"){
            head = pop(head);
        }if(s == "getmax"){
            if(!head) cout << "error";
            else head = getMax(head);
        }if(s == "getcur"){
            if(head == nullptr){
                cout << "error"<<endl;
            }else{
                cout <<head->val<<endl;
            }
        }
    }
}