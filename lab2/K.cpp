#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    pair<bool, char> p;
    ListNode * next;
    ListNode * prev;

    ListNode(char val){
        p.first = true;
        p.second = val;
        next = nullptr;
        prev = nullptr;
    }
};

struct LinkedList{
    ListNode * head;
    ListNode * tail;
    int size;
    LinkedList(){
        this->size = 0;
        head = nullptr;
        tail = nullptr;
    }
    void push_back(int x){
		ListNode *temp = new ListNode(x);
		if (this->head == nullptr)
		{
			head = temp;
			tail = temp;
            this->size++;
		}
		else
		{
			tail->next = temp;
            temp->prev = tail;
            tail = temp;
            this->size++;
		}
    }
    void check(){
        ListNode * cur = head;
        while(cur -> next != nullptr){
            if(cur -> p.second == tail -> p.second){
                cur -> p.first = false;
                tail -> p.first = false;
            }
            cur = cur -> next;
        }
        cur = head;
        while(cur != nullptr){
            if(cur -> p.first == true){
                cout << cur -> p.second << " ";
                return;
            }
            cur = cur -> next;
        }
        cout << -1 << " ";
    }


};

int main(){
    LinkedList* l = new LinkedList();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin>>x;
        while(x--){
            char c;
            cin>>c;
            l->push_back(c);
            l->check();
        }
        cout<<endl;
        l->head = nullptr;
    }
}
