#include<iostream>
#include<limits.h>
#include<cmath>

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
    int getNearsetNum(int x){
        ListNode* test = this->head;
        int index = 0;
        int difference = INT_MAX;
        for(int i = 0; i < this->size;i++){
            if(abs(x-test->val)<difference){
                difference = abs(x-test->val);
                index = i;
            }
            test = test->next;
        }
        return index;
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
    int k;
    cin>>k;
    int f = l->getNearsetNum(k);
    cout<<f;
    return 0;
}


