#include<iostream>

using namespace std;

struct ListNode{
    string val;
    ListNode* next;
    ListNode(){
        this->val ="";
        this->next = nullptr;
    }
    ListNode(string val){
        this->val=val;
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
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    void push_front(string val)
	{
		//this->size++;
		ListNode *temp = new ListNode(val);
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
            
		}
		else
		{
		    temp->next = this->head;
		    this->head = temp;
		}
        size++;
	}
    void print() {
		ListNode *cur = head;
		while (cur != nullptr) {
			cout << cur->val <<endl;
			cur = cur->next;
		}
		cout << endl;
	}
};
int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin>>n;   
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="" || (l->head && l->head->val == s)) continue;
        else l->push_front(s);
        
    }
    cout<<"All in all: "<<l->size<<endl;
    cout<<"Students:"<<endl;
    l->print();
    return 0;
}