#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};
struct LinkedList{
    int size;
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        this-> size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    void push_back(int x){
		ListNode *temp = new ListNode(x);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
            this->size++;
		}
		else
		{
			this->tail->next = temp;
            this->tail = temp;
            this->size++;
		}
    }
    void reverse(){
        ListNode * next = nullptr;
        ListNode * prev = nullptr;
        ListNode * cur = head;
        while(cur != nullptr){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    void print() {
        int i = 0;
		ListNode *cur = head;
		while (cur != nullptr) {
            if(i % 2 == 0){
			    cout << cur->val << " ";
            }
			cur = cur->next;
            i++;
		}
		cout << endl;
	}
};
int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l->push_back(x);
    }
    l->reverse();
    l->print();
    return 0;
}