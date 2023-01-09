#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

struct LinkedList {
    ListNode* head;
    ListNode* tail;
    int size = 0;
    LinkedList(): head(nullptr) {}
    void add(int x) {
        size++;
        ListNode* node = new ListNode(x);
        if (head == nullptr) {
            head = node;
            tail = node;
        }else {
			this->tail->next = node;
			this->tail = node;
		}
    }
    void  kill(int k){
        if(k == 0){
            head = head->next;
        }
        if (k == 1) {
			head = head->next;
			size--;
		}else if (k == size - 1) {
			ListNode* cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			tail = cur;
			size--;
		}
        else if (k > 1 && k < size - 1) {
			ListNode* cur = head;
			for (int i = 0; i < k - 1; i++) {
				cur = cur->next;
			}
			ListNode* toDel = cur->next;
			cur->next = cur->next->next;
			size--;
			delete (toDel);
		}
    }
    void print() {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList *l = new LinkedList();
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        l->add(x);
    }
    l->kill(n-k);
    l->print();
    return 0;
}