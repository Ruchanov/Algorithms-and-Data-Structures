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
    void deleteSecond(int index)
	{
		if (index == 0)
		{
			this->head = this->head->next;
			this->size--;
		}
		else if (index == this->size - 1)
		{
			ListNode *cur = this->head;
			while (cur->next != this->tail)
			{
				cur = cur->next;
			}
			this->tail = cur;
			this->size--;
		} else if (index > 0 && index < this->size) {
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			ListNode *toDel = cur->next;
			cur->next = cur->next->next;
			this->size--;
			delete (toDel);
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
    for(int i = 0;i < n; i++){
        int x;
        cin>>x;
        l->push_back(x);
    }
    for(int i = 1; i < n; i += 2){
        l->deleteSecond(i);
    }
    l->print();
    return 0;
}