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
    void deleteSecond(int pos){
        if (pos == 1){
            head = head -> next;
        }
        else{
            int i = 1;
            ListNode * cur = head;
            ListNode * prev = nullptr;
            while(cur != nullptr){
                if (i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
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
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        l->push_back(x);
    }
    // for(int i = 2; i <= n; i += 2){
    //     // cout<<i;
    //     l->deleteSecond(i);
    // }
    // l->deleteSecond(4);
    l->print();
    return 0;
}