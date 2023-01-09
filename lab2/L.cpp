#include<iostream>
#include<limits.h>
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
    int maxSum(){
        int max = INT_MIN;
        int current_max = 0;
        ListNode *cur = head;
        while(cur!=nullptr){
            current_max = current_max + cur->val;
        if (max < current_max)
            max = current_max;
 
        if (current_max < 0)
            current_max = 0;
            cur = cur->next;
        }
        return max;
    }
};

int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin>>n;
    for(int i = 0;i < n; i++ ){
        int x;
        cin>>x;
        l->push_back(x);
    }
    cout<<l->maxSum();
}