#include<iostream>

using namespace std;

struct ListNode{
    string val;
    ListNode* next;
    ListNode(){
        this->val = "";
        this->next = nullptr;
    }
    ListNode(string val){
        this->val = val;
        this->next = nullptr;
    }ListNode(string val, ListNode* next){
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
    void push_back(string s){
		ListNode *temp = new ListNode(s);
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
    void firstToLast(){
        ListNode *temp = this->head;
        this->head = this->head->next;
        this->tail->next = temp; 
        this->tail = temp;
        this->tail->next = nullptr;
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
    int n,m;
    LinkedList *l = new LinkedList();
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        l->push_back(s);
    }
    while(m--){
        l->firstToLast();
    }
    l->print();
    return 0;
}