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
    void deleteSecond(){
        ListNode *cur = this->head;
        int i = 1;
        while(cur->next->next!=nullptr){
            if(i % 2 == 0){
                cur = cur->next;
                i++;
            }
            cout<<cur->val<<" ";
            cur = cur->next;
            i++;
        }
        if(i % 2 == 0){
            cur = this->tail;
            cout<<cur->val<<" ";
        }else{
            cout<<cur->val;
        }
    }
    void print() {
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main(){
    LinkedList *l = new LinkedList;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l->push_back(x);
    }
    l->deleteSecond();
    return 0;
}