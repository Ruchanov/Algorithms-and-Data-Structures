#include<iostream>
#include<limits.h>
using namespace std;

string tobinary(long long x){
    string s = "";
    while(x != 0){
        s += x % 2 + 48;
        x /= 2;
    }
    string res = "";
    for(int i = s.size()-1; i >= 0; i--){
        res += s[i];
    }
    return res;
}
struct Node{
    char val;
    Node* next;
    Node(char x){
        val = x;
        next = nullptr;
    }
};
struct stack{
    Node* head;
    stack(){
        this->head = nullptr;
    }
    void insert(char val){
        Node* temp = new Node(val);
        if(!head){
            head = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }
    void pop(){
        if(head){
            if(!head->next){
                Node* tmp = head;
                head = nullptr;
                delete (tmp);
            }else{
                Node* toDelete = head;
			    head = head->next;
			    delete (toDelete);
            }
        }
    }
    char getCur(){
        return head->val;
    }
    bool isEmpty(){
        return head == nullptr;
    }
};
int main(){
    int n;
    cin >> n;
    while(n--){
        long long x;
        cin >> x;
        stack st;
        string s = tobinary(x);
        for(int i = 0; i < s.size(); i++){
            if(!st.isEmpty() && st.getCur() == '1' && s[i] == '0'){
                st.pop();
            }else{
                st.insert(s[i]);
            }
        }
        if(st.isEmpty()){
            cout << "YES"<<endl;
        }else{
            cout << "NO"<<endl;
        }
    }
}